-- 
DELETE FROM `npc_vendor` WHERE (`entry`=18266 AND `item`=63696 AND `ExtendedCost`=56 AND `type`=1) OR (`entry`=20231 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20231 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20231 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20231 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20231 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19314 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19314 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19314 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19314 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=30734 AND `item`=79740 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=30734 AND `item`=1515 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=30734 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18773 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18802 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18802 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18802 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16829 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16829 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=16826 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18774 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(18266, 1, 63696, 0, 56, 1, 0, 0, 26124), -- Bold Blood Garnet
(20231, 6, 4470, 0, 0, 1, 0, 0, 26124), -- Simple Wood
(20231, 5, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(20231, 4, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(20231, 3, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(20231, 1, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(19314, 5, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(19314, 4, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(19314, 3, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(19314, 1, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(30734, 7302, 79740, 0, 0, 1, 0, 0, 26124), -- Plain Wooden Staff
(30734, 7301, 1515, 0, 0, 1, 0, 0, 26124), -- Rough Wooden Staff
(30734, 7297, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(18773, 4251, 38682, 0, 0, 1, 0, 0, 26124), -- Enchanting Vellum
(18802, 5, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(18802, 3, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(18802, 2, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(16829, 4, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(16829, 3, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(16826, 18, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(16826, 17, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(16826, 16, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(16826, 14, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(16826, 11, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(16826, 10, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(16826, 9, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(16826, 8, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(18774, 2, 52188, 0, 0, 1, 0, 0, 26124); -- Jeweler's Setting

UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=24520 AND `ExtendedCost`=53 AND `type`=1); -- Honor Hold Favor
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27834 AND `ExtendedCost`=69 AND `type`=1); -- Circlet of the Victor
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27833 AND `ExtendedCost`=69 AND `type`=1); -- Band of the Victor
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27809 AND `ExtendedCost`=56 AND `type`=1); -- Jagged Deep Peridot
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27812 AND `ExtendedCost`=56 AND `type`=1); -- Brilliant Blood Garnet
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=28361 AND `ExtendedCost`=56 AND `type`=1); -- Delicate Blood Garnet
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=20231 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=20231 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=20231 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=20231 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=20231 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=20231 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19314 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=16823 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=16823 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=16823 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=16823 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=16823 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16823 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=35465 AND `ExtendedCost`=0 AND `type`=1); -- Evoker's Silk Amice
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29153 AND `ExtendedCost`=0 AND `type`=1); -- Blade of the Archmage
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29151 AND `ExtendedCost`=0 AND `type`=1); -- Veteran's Musket
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29156 AND `ExtendedCost`=0 AND `type`=1); -- Honor's Call
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=23999 AND `ExtendedCost`=0 AND `type`=1); -- Honor Hold Tabard
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=23619 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Felsteel Shield Spike
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=33150 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Cloak - Subtlety
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29722 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Nethercobra Leg Armor
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29169 AND `ExtendedCost`=0 AND `type`=1); -- Ring of Convalescence
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29166 AND `ExtendedCost`=0 AND `type`=1); -- Hellforged Halberd
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=24180 AND `ExtendedCost`=0 AND `type`=1); -- Design: Dawnstone Crab
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=22547 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Chest - Exceptional Stats
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=25826 AND `ExtendedCost`=0 AND `type`=1); -- Sage's Band
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=25825 AND `ExtendedCost`=0 AND `type`=1); -- Footman's Longsword
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=25870 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Skyfire Diamond
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29215 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Felstalker Breastplate
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29214 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Felstalker Bracers
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=22905 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Elixir of Major Agility
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29719 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Cobrahide Leg Armor
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=22531 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Superior Healing
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=24008 AND `ExtendedCost`=0 AND `type`=1); -- Dried Mushroom Rations
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=24007 AND `ExtendedCost`=0 AND `type`=1); -- Footman's Waterskin
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=29213 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Felstalker Belt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17657 AND `item`=23142 AND `ExtendedCost`=0 AND `type`=1); -- Design: Regal Deep Peridot
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=24520 AND `ExtendedCost`=53 AND `type`=1); -- Honor Hold Favor
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27834 AND `ExtendedCost`=69 AND `type`=1); -- Circlet of the Victor
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27833 AND `ExtendedCost`=69 AND `type`=1); -- Band of the Victor
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27809 AND `ExtendedCost`=56 AND `type`=1); -- Jagged Deep Peridot
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=27812 AND `ExtendedCost`=56 AND `type`=1); -- Brilliant Blood Garnet
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18266 AND `item`=28361 AND `ExtendedCost`=56 AND `type`=1); -- Delicate Blood Garnet
UPDATE `npc_vendor` SET `slot`=7300, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=30734 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1); -- Scribe's Satchel
UPDATE `npc_vendor` SET `slot`=7299, `VerifiedBuild`=26124 WHERE (`entry`=30734 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=7298, `VerifiedBuild`=26124 WHERE (`entry`=30734 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=4260, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=4259, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=4258, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=4257, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=4256, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=4255, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4254, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=4253, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=4252, `VerifiedBuild`=26124 WHERE (`entry`=18773 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=397, `VerifiedBuild`=26124 WHERE (`entry`=18802 AND `item`=22900 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Elixir of Camouflage
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16829 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18771 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18772 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18987 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=18987 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18987 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16826 AND `item`=27688 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Ravager Dog
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18774 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28470 AND `ExtendedCost`=0 AND `type`=1); -- Subtle Amber
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28467 AND `ExtendedCost`=0 AND `type`=1); -- Smooth Amber
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28468 AND `ExtendedCost`=0 AND `type`=1); -- Rigid Zircon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28464 AND `ExtendedCost`=0 AND `type`=1); -- Sparkling Zircon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28463 AND `ExtendedCost`=0 AND `type`=1); -- Solid Zircon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28459 AND `ExtendedCost`=0 AND `type`=1); -- Delicate Tourmaline
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28461 AND `ExtendedCost`=0 AND `type`=1); -- Brilliant Tourmaline
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22227 AND `item`=28458 AND `ExtendedCost`=0 AND `type`=1); -- Bold Tourmaline
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=35101 AND `item`=25527 AND `ExtendedCost`=0 AND `type`=1); -- Swift Red Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=35101 AND `item`=25529 AND `ExtendedCost`=0 AND `type`=1); -- Swift Purple Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=35101 AND `item`=25528 AND `ExtendedCost`=0 AND `type`=1); -- Swift Green Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=35101 AND `item`=25473 AND `ExtendedCost`=0 AND `type`=1); -- Swift Blue Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=35101 AND `item`=25472 AND `ExtendedCost`=0 AND `type`=1); -- Snowy Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=35101 AND `item`=25470 AND `ExtendedCost`=0 AND `type`=1); -- Golden Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=35101 AND `item`=25471 AND `ExtendedCost`=0 AND `type`=1); -- Ebon Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=16824 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19451 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19451 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19451 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19451 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19451 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19451 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19452 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19452 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19452 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19452 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19452 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19452 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water

DELETE FROM `npc_vendor` WHERE (`entry`=19004 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18775 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18775 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(19004, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(18775, 321, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(18775, 310, 90146, 0, 0, 1, 0, 0, 26124); -- Tinker's Kit

UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=23848 AND `ExtendedCost`=0 AND `type`=1); -- Nethergarde Bitter
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=3546 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `slot`=405, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30753 AND `ExtendedCost`=0 AND `type`=1); -- Warphorn Spear
UPDATE `npc_vendor` SET `slot`=404, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30751 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Axe
UPDATE `npc_vendor` SET `slot`=403, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30752 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Battleaxe
UPDATE `npc_vendor` SET `slot`=402, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30750 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Warblade
UPDATE `npc_vendor` SET `slot`=401, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30749 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Sparring Blade
UPDATE `npc_vendor` SET `slot`=400, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30754 AND `ExtendedCost`=0 AND `type`=1); -- Ancient Bone Mace
UPDATE `npc_vendor` SET `slot`=2951, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=30745 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Toolbox
UPDATE `npc_vendor` SET `slot`=2950, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1); -- Mining Sack
UPDATE `npc_vendor` SET `slot`=2949, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=30747 AND `ExtendedCost`=0 AND `type`=1); -- Gem Pouch
UPDATE `npc_vendor` SET `slot`=2948, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=30748 AND `ExtendedCost`=0 AND `type`=1); -- Enchanter's Satchel
UPDATE `npc_vendor` SET `slot`=2947, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18906 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16798 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=399, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30751 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Axe
UPDATE `npc_vendor` SET `slot`=398, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30752 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Battleaxe
UPDATE `npc_vendor` SET `slot`=397, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30750 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Warblade
UPDATE `npc_vendor` SET `slot`=396, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30749 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Sparring Blade
UPDATE `npc_vendor` SET `slot`=395, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19001 AND `item`=30754 AND `ExtendedCost`=0 AND `type`=1); -- Ancient Bone Mace
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=44737 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Silk Robes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=60335 AND `ExtendedCost`=0 AND `type`=1); -- Thick Hide Pack
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Crusty Flatbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35953 AND `ExtendedCost`=0 AND `type`=1); -- Mead Basted Caribou
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35947 AND `ExtendedCost`=0 AND `type`=1); -- Sparkling Frostcap
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35948 AND `ExtendedCost`=0 AND `type`=1); -- Savory Snowplum
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35951 AND `ExtendedCost`=0 AND `type`=1); -- Poached Emperor Salmon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35952 AND `ExtendedCost`=0 AND `type`=1); -- Briny Hardcheese
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35950 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Potato Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33454 AND `ExtendedCost`=0 AND `type`=1); -- Salted Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33452 AND `ExtendedCost`=0 AND `type`=1); -- Honey-Spiced Lichen
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35949 AND `ExtendedCost`=0 AND `type`=1); -- Tundra Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33451 AND `ExtendedCost`=0 AND `type`=1); -- Fillet of Icefin
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33443 AND `ExtendedCost`=0 AND `type`=1); -- Sour Goat Cheese
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Crusty Flatbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33445 AND `ExtendedCost`=0 AND `type`=1); -- Honeymint Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=33444 AND `ExtendedCost`=0 AND `type`=1); -- Pungent Seal Whey
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=35954 AND `ExtendedCost`=0 AND `type`=1); -- Sweetened Goat's Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=40042 AND `ExtendedCost`=0 AND `type`=1); -- Caraway Burnwine
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=40036 AND `ExtendedCost`=0 AND `type`=1); -- Snowplum Brandy
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32638 AND `item`=40035 AND `ExtendedCost`=0 AND `type`=1); -- Northrend Honey Mead
UPDATE `npc_vendor` SET `slot`=339, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=23805 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Ultra-Spectropic Detection Goggles
UPDATE `npc_vendor` SET `slot`=338, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=23803 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Cogspinner Goggles
UPDATE `npc_vendor` SET `slot`=320, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=319, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=318, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=4404 AND `ExtendedCost`=0 AND `type`=1); -- Silver Contact
UPDATE `npc_vendor` SET `slot`=317, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=316, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=315, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=314, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=313, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=312, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=311, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=309, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=308, `VerifiedBuild`=26124 WHERE (`entry`=18775 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer

DELETE FROM `npc_vendor` WHERE (`entry`=18911 AND `item`=136377 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18006 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18006 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18907 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18907 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18907 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(18911, 340, 136377, 0, 0, 1, 0, 0, 26124), -- Oversized Bobber
(18006, 2, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(18006, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(18907, 18, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(18907, 17, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(18907, 16, 39354, 0, 0, 1, 0, 0, 26124); -- Light Parchment

UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=34478 AND `ExtendedCost`=388 AND `type`=1); -- Tiny Sporebat
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=31775 AND `ExtendedCost`=1994 AND `type`=1); -- Sporeggar Tabard
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=22906 AND `ExtendedCost`=388 AND `type`=1); -- Recipe: Shrouding Potion
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=38229 AND `ExtendedCost`=103 AND `type`=1); -- Pattern: Mycah's Botanical Bag
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=22916 AND `ExtendedCost`=103 AND `type`=1); -- Recipe: Transmute Primal Earth to Water
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=29150 AND `ExtendedCost`=1077 AND `type`=1); -- Hardened Stone Shard
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=29149 AND `ExtendedCost`=1076 AND `type`=1); -- Sporeling's Firestick
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=25828 AND `ExtendedCost`=104 AND `type`=1); -- Petrified Lichen Guard
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=25827 AND `ExtendedCost`=103 AND `type`=1); -- Muck-Covered Drape
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=25550 AND `ExtendedCost`=100 AND `type`=1); -- Redcap Toadstool
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=25548 AND `ExtendedCost`=100 AND `type`=1); -- Tallstalk Mushroom
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=24539 AND `ExtendedCost`=102 AND `type`=1); -- Marsh Lichen
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18382 AND `item`=30156 AND `ExtendedCost`=100 AND `type`=1); -- Recipe: Clam Bar
UPDATE `npc_vendor` SET `slot`=344, `VerifiedBuild`=26124 WHERE (`entry`=18911 AND `item`=6533 AND `ExtendedCost`=0 AND `type`=1); -- Aquadynamic Fish Attractor
UPDATE `npc_vendor` SET `slot`=343, `VerifiedBuild`=26124 WHERE (`entry`=18911 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=342, `VerifiedBuild`=26124 WHERE (`entry`=18911 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=341, `VerifiedBuild`=26124 WHERE (`entry`=18911 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=339, `VerifiedBuild`=26124 WHERE (`entry`=18911 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18911 AND `item`=27696 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Blackened Sporefish
UPDATE `npc_vendor` SET `slot`=1881, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23595 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Plate Gloves
UPDATE `npc_vendor` SET `slot`=1880, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23594 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Plate Bracers
UPDATE `npc_vendor` SET `slot`=1879, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23596 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Breastplate
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `slot`=1873, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23594 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Plate Bracers
UPDATE `npc_vendor` SET `slot`=1872, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23595 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Plate Gloves
UPDATE `npc_vendor` SET `slot`=1871, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23596 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Breastplate
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `slot`=1441, `VerifiedBuild`=26124 WHERE (`entry`=18005 AND `item`=22909 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Elixir of Major Defense
UPDATE `npc_vendor` SET `slot`=1440, `VerifiedBuild`=26124 WHERE (`entry`=18005 AND `item`=22902 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Elixir of Major Frost Power
UPDATE `npc_vendor` SET `slot`=1437, `VerifiedBuild`=26124 WHERE (`entry`=18005 AND `item`=22907 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Super Mana Potion
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18005 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18250 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=1870, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23594 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Plate Bracers
UPDATE `npc_vendor` SET `slot`=1869, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23595 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Plate Gloves
UPDATE `npc_vendor` SET `slot`=1868, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=23596 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Breastplate
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19694 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `slot`=37, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=35347 AND `ExtendedCost`=0 AND `type`=1); -- Evoker's Silk Trousers
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=33999 AND `ExtendedCost`=0 AND `type`=1); -- Cenarion War Hippogryph
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31804 AND `ExtendedCost`=0 AND `type`=1); -- Cenarion Expedition Tabard
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29172 AND `ExtendedCost`=0 AND `type`=1); -- Ashyen's Gift
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29170 AND `ExtendedCost`=0 AND `type`=1); -- Windcaller's Orb
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29171 AND `ExtendedCost`=0 AND `type`=1); -- Earthwarden
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=33149 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Cloak - Stealth
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31402 AND `ExtendedCost`=0 AND `type`=1); -- Design: The Natural Ward
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29721 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Nethercleft Leg Armor
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31390 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Wildguard Breastplate
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31356 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Flask of Distilled Wisdom
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=22922 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Major Nature Protection Potion
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29173 AND `ExtendedCost`=0 AND `type`=1); -- Strength of the Untamed
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29174 AND `ExtendedCost`=0 AND `type`=1); -- Watcher's Cowl
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31391 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Wildguard Leggings
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31392 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Wildguard Helm
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=22918 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Primal Water to Air
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=28271 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Gloves - Precise Strikes
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25735 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Clefthoof Vest
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=24183 AND `ExtendedCost`=0 AND `type`=1); -- Design: Nightseye Panther
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25835 AND `ExtendedCost`=0 AND `type`=1); -- Explorer's Walking Stick
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25838 AND `ExtendedCost`=0 AND `type`=1); -- Warden's Hauberk
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=32070 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Earthen Elixir
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25836 AND `ExtendedCost`=0 AND `type`=1); -- Preserver's Cudgel
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25526 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Greater Rune of Warding
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29720 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Clefthide Leg Armor
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25869 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Earthstorm Diamond
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=28632 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Weightstone
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=23618 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Sharpening Stone
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25736 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Clefthoof Leggings
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=24429 AND `ExtendedCost`=0 AND `type`=1); -- Expedition Flare
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=23814 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Green Smoke Flare
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25737 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Clefthoof Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18581 AND `item`=27922 AND `ExtendedCost`=77 AND `type`=1); -- Mark of Defiance
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18581 AND `item`=27942 AND `ExtendedCost`=69 AND `type`=1); -- Incendic Rod
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18581 AND `item`=27931 AND `ExtendedCost`=69 AND `type`=1); -- Splintermark
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18581 AND `item`=27922 AND `ExtendedCost`=77 AND `type`=1); -- Mark of Defiance
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18581 AND `item`=27942 AND `ExtendedCost`=69 AND `type`=1); -- Incendic Rod
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18581 AND `item`=27931 AND `ExtendedCost`=69 AND `type`=1); -- Splintermark
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=29112 AND `ExtendedCost`=0 AND `type`=1); -- Cenarion Spirits
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=18907 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18993 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18993 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18993 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17896 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=37, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=35347 AND `ExtendedCost`=0 AND `type`=1); -- Evoker's Silk Trousers
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=33999 AND `ExtendedCost`=0 AND `type`=1); -- Cenarion War Hippogryph
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31804 AND `ExtendedCost`=0 AND `type`=1); -- Cenarion Expedition Tabard
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29172 AND `ExtendedCost`=0 AND `type`=1); -- Ashyen's Gift
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29170 AND `ExtendedCost`=0 AND `type`=1); -- Windcaller's Orb
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29171 AND `ExtendedCost`=0 AND `type`=1); -- Earthwarden
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=33149 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Cloak - Stealth
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31402 AND `ExtendedCost`=0 AND `type`=1); -- Design: The Natural Ward
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29721 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Nethercleft Leg Armor
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31390 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Wildguard Breastplate
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31356 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Flask of Distilled Wisdom
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=22922 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Major Nature Protection Potion
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29173 AND `ExtendedCost`=0 AND `type`=1); -- Strength of the Untamed
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29174 AND `ExtendedCost`=0 AND `type`=1); -- Watcher's Cowl
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31391 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Wildguard Leggings
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=31392 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Wildguard Helm
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=22918 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Primal Water to Air
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=28271 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Gloves - Precise Strikes
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25735 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Clefthoof Vest
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=24183 AND `ExtendedCost`=0 AND `type`=1); -- Design: Nightseye Panther
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25835 AND `ExtendedCost`=0 AND `type`=1); -- Explorer's Walking Stick
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25838 AND `ExtendedCost`=0 AND `type`=1); -- Warden's Hauberk
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=32070 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Earthen Elixir
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25836 AND `ExtendedCost`=0 AND `type`=1); -- Preserver's Cudgel
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25526 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Greater Rune of Warding
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=29720 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Clefthide Leg Armor
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25869 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Earthstorm Diamond
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=28632 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Weightstone
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=23618 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Sharpening Stone
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25736 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Clefthoof Leggings
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=24429 AND `ExtendedCost`=0 AND `type`=1); -- Expedition Flare
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=23814 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Green Smoke Flare
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17904 AND `item`=25737 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Clefthoof Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21172 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water

DELETE FROM `npc_vendor` WHERE (`entry`=18009 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18009 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18009 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18019 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18019 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(18009, 28, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(18009, 27, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(18009, 3, 85663, 0, 0, 1, 0, 0, 26124), -- Herbalist's Spade
(18019, 2, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(18019, 1, 4565, 0, 0, 1, 0, 0, 26124); -- Simple Dagger

UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `slot`=727, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=21898 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Imbued Netherweave Pants
UPDATE `npc_vendor` SET `slot`=726, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=21899 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Imbued Netherweave Boots
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19722 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=20028 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=20028 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20028 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=20028 AND `item`=27694 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Blackened Trout
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=20028 AND `item`=27695 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Feltail Delight
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18010 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18009 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick

DELETE FROM `npc_vendor` WHERE (`entry`=19053 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19053 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19053 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19053 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19042 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19042 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19042 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19042 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19234 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19235 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19245 AND `item`=82344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19245 AND `item`=83094 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19245 AND `item`=82343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19245 AND `item`=83095 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33634 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33634 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33630 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33630 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19239 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33640 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33637 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33633 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33633 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33633 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33638 AND `item`=79740 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33638 AND `item`=1515 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=33638 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19244 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19244 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19244 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=35326 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=34162 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=34163 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=34049 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=34050 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33832 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33296 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33192 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33334 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33484 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=35321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33304 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=35324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33333 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33593 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33589 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33587 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33585 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33586 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33584 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33588 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33583 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33579 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33972 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33559 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33973 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33974 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33557 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33552 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33287 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33577 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33582 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33566 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33580 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33578 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33539 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33222 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33538 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33537 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33536 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33531 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33386 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33534 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33970 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33965 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33535 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33529 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33280 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33527 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33528 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33520 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33523 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33207 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33518 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33519 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33524 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33522 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33515 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33514 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33512 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33331 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33513 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33516 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33279 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33517 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33501 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=33810 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32090 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32089 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32085 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32086 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32087 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32088 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32084 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=32083 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30762 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30761 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30763 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30767 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30769 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30768 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30778 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30780 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30776 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30779 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30772 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30773 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30774 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30770 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=30183 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=23572 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29387 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29383 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29376 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29370 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29385 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29382 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29375 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29369 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29386 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29381 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29374 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29368 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29384 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29379 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29373 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29367 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29266 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29272 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29267 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29274 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29269 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29270 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29275 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29268 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29271 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18525 AND `item`=29273 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34949 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34894 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34893 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34896 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34898 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34892 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34895 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34891 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34888 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34887 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34890 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34889 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34940 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34939 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34941 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34943 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34942 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34944 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34946 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34945 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34947 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34922 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34921 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34923 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34934 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34933 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34935 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34931 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34930 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34932 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34914 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34916 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34912 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34928 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34927 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34929 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34905 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34904 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34903 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34910 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34911 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34906 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34902 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34900 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34936 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34937 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34938 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34924 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34925 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34926 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34917 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34918 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=27667 AND `item`=34919 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52278 AND `item`=15198 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=52278 AND `item`=15196 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=52278 AND `item`=19032 AND `ExtendedCost`=5992 AND `type`=1) OR (`entry`=52278 AND `item`=19506 AND `ExtendedCost`=5992 AND `type`=1) OR (`entry`=52278 AND `item`=31774 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=52278 AND `item`=23999 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19049 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19197 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19197 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19197 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19678 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19661 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19661 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19227 AND `item`=74918 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18756 AND `item`=134007 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18756 AND `item`=134004 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19186 AND `item`=82344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19186 AND `item`=83094 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19186 AND `item`=82343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19186 AND `item`=83095 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18484 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18484 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(19053, 9, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(19053, 8, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(19053, 7, 28399, 0, 0, 1, 0, 0, 26124), -- Filtered Draenic Water
(19053, 6, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(19042, 8, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19042, 7, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19042, 6, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19042, 4, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(19234, 1, 38682, 0, 0, 1, 0, 0, 26124), -- Enchanting Vellum
(19235, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19245, 9, 82344, 0, 0, 1, 0, 0, 26124), -- Hearthglen Ambrosia
(19245, 8, 83094, 0, 0, 1, 0, 0, 26124), -- Foote Tripel
(19245, 7, 82343, 0, 0, 1, 0, 0, 26124), -- Lordaeron Lambic
(19245, 6, 83095, 0, 0, 1, 0, 0, 26124), -- Lagrave Stout
(33634, 13, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(33634, 3, 90146, 0, 0, 1, 0, 0, 26124), -- Tinker's Kit
(33630, 4, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(33630, 3, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19239, 3, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(33640, 2, 30746, 0, 0, 1, 0, 0, 26124), -- Mining Sack
(33637, 2, 52188, 0, 0, 1, 0, 0, 26124), -- Jeweler's Setting
(33633, 11, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(33633, 3, 10940, 2, 0, 1, 0, 0, 26124), -- Strange Dust
(33633, 1, 38682, 0, 0, 1, 0, 0, 26124), -- Enchanting Vellum
(33638, 6, 79740, 0, 0, 1, 0, 0, 26124), -- Plain Wooden Staff
(33638, 5, 1515, 0, 0, 1, 0, 0, 26124), -- Rough Wooden Staff
(33638, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19244, 28, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19244, 27, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19244, 3, 85663, 0, 0, 1, 0, 0, 26124), -- Herbalist's Spade
(18525, 125, 35326, 0, 0, 1, 0, 0, 26124), -- Battlemaster's Alacrity
(18525, 124, 34162, 0, 0, 1, 0, 0, 26124), -- Battlemaster's Depravity
(18525, 123, 34163, 0, 0, 1, 0, 0, 26124), -- Battlemaster's Cruelty
(18525, 122, 34049, 0, 0, 1, 0, 0, 26124), -- Battlemaster's Audacity
(18525, 121, 34050, 0, 0, 1, 0, 0, 26124), -- Battlemaster's Perseverance
(18525, 120, 33832, 0, 0, 1, 0, 0, 26124), -- Battlemaster's Determination
(18525, 119, 33296, 0, 0, 1, 0, 0, 26124), -- Brooch of Deftness
(18525, 118, 33192, 0, 0, 1, 0, 0, 26124), -- Carved Witch Doctor's Stick
(18525, 117, 33325, 0, 0, 1, 0, 0, 26124), -- Voodoo Shaker
(18525, 116, 33334, 0, 0, 1, 0, 0, 26124), -- Fetish of the Primal Gods
(18525, 115, 33484, 0, 0, 1, 0, 0, 26124), -- Dory's Embrace
(18525, 114, 35321, 0, 0, 1, 0, 0, 26124), -- Cloak of Arcane Alacrity
(18525, 113, 33304, 0, 0, 1, 0, 0, 26124), -- Cloak of Subjugated Power
(18525, 112, 35324, 0, 0, 1, 0, 0, 26124), -- Cloak of Swift Reprieve
(18525, 111, 33333, 0, 0, 1, 0, 0, 26124), -- Kharmaa's Shroud of Hope
(18525, 110, 33593, 0, 0, 1, 0, 0, 26124), -- Slikk's Cloak of Placation
(18525, 109, 33589, 0, 0, 1, 0, 0, 26124), -- Wristguards of Tranquil Thought
(18525, 108, 33587, 0, 0, 1, 0, 0, 26124), -- Light-Blessed Bonds
(18525, 107, 33585, 0, 0, 1, 0, 0, 26124), -- Achromic Trousers of the Naaru
(18525, 106, 33291, 0, 0, 1, 0, 0, 26124), -- Voodoo-Woven Belt
(18525, 105, 33586, 0, 0, 1, 0, 0, 26124), -- Studious Wraps
(18525, 104, 33584, 0, 0, 1, 0, 0, 26124), -- Pantaloons of Arcane Annihilation
(18525, 103, 33588, 0, 0, 1, 0, 0, 26124), -- Runed Spell-Cuffs
(18525, 102, 33583, 0, 0, 1, 0, 0, 26124), -- Waistguard of the Great Beast
(18525, 101, 33579, 0, 0, 1, 0, 0, 26124), -- Vestments of Hibernation
(18525, 100, 33972, 0, 0, 1, 0, 0, 26124), -- Mask of Primal Power
(18525, 99, 33559, 0, 0, 1, 0, 0, 26124), -- Starfire Waistband
(18525, 98, 33973, 0, 0, 1, 0, 0, 26124), -- Pauldrons of Tribal Fury
(18525, 97, 33974, 0, 0, 1, 0, 0, 26124), -- Grasp of the Moonkin
(18525, 96, 33557, 0, 0, 1, 0, 0, 26124), -- Gargon's Bracers of Peaceful Slumber
(18525, 95, 33552, 0, 0, 1, 0, 0, 26124), -- Pants of Splendid Recovery
(18525, 94, 33287, 0, 0, 1, 0, 0, 26124), -- Gnarled Ironwood Pauldrons
(18525, 93, 33577, 0, 0, 1, 0, 0, 26124), -- Moon-Walkers
(18525, 92, 33582, 0, 0, 1, 0, 0, 26124), -- Footwraps of Wild Encroachment
(18525, 91, 33566, 0, 0, 1, 0, 0, 26124), -- Blessed Elunite Coverings
(18525, 90, 33580, 0, 0, 1, 0, 0, 26124), -- Band of the Swift Paw
(18525, 89, 33578, 0, 0, 1, 0, 0, 26124), -- Armwraps of the Kaldorei Protector
(18525, 88, 33539, 0, 0, 1, 0, 0, 26124), -- Trickster's Stickyfingers
(18525, 87, 33222, 0, 0, 1, 0, 0, 26124), -- Nyn'jah's Tabi Boots
(18525, 86, 33538, 0, 0, 1, 0, 0, 26124), -- Shallow-Grave Trousers
(18525, 85, 33540, 0, 0, 1, 0, 0, 26124), -- Master Assassin Wristwraps
(18525, 84, 33537, 0, 0, 1, 0, 0, 26124), -- Treads of Booming Thunder
(18525, 83, 33536, 0, 0, 1, 0, 0, 26124), -- Stormwrap
(18525, 82, 33531, 0, 0, 1, 0, 0, 26124), -- Polished Waterscale Gloves
(18525, 81, 33324, 0, 0, 1, 0, 0, 26124), -- Treads of the Life Path
(18525, 80, 33530, 0, 0, 1, 0, 0, 26124), -- Natural Life Leggings
(18525, 79, 33386, 0, 0, 1, 0, 0, 26124), -- Man'kin'do's Belt
(18525, 78, 33534, 0, 0, 1, 0, 0, 26124), -- Grips of Nature's Wrath
(18525, 77, 33532, 0, 0, 1, 0, 0, 26124), -- Gleaming Earthen Bracers
(18525, 76, 33970, 0, 0, 1, 0, 0, 26124), -- Pauldrons of the Furious Elements
(18525, 75, 33965, 0, 0, 1, 0, 0, 26124), -- Hauberk of the Furious Elements
(18525, 74, 33535, 0, 0, 1, 0, 0, 26124), -- Earthquake Bracers
(18525, 73, 33529, 0, 0, 1, 0, 0, 26124), -- Steadying Bracers
(18525, 72, 33280, 0, 0, 1, 0, 0, 26124), -- War-Feathered Loop
(18525, 71, 33527, 0, 0, 1, 0, 0, 26124), -- Shifting Camouflage Pants
(18525, 70, 33528, 0, 0, 1, 0, 0, 26124), -- Gauntlets of Sniping
(18525, 69, 33520, 0, 0, 1, 0, 0, 26124), -- Vambraces of the Naaru
(18525, 68, 33523, 0, 0, 1, 0, 0, 26124), -- Sabatons of the Righteous Defender
(18525, 67, 33207, 0, 0, 1, 0, 0, 26124), -- Implacable Guardian Sabatons
(18525, 66, 33518, 0, 0, 1, 0, 0, 26124), -- High Justicar's Legplates
(18525, 65, 33519, 0, 0, 1, 0, 0, 26124), -- Handguards of the Templar
(18525, 64, 33524, 0, 0, 1, 0, 0, 26124), -- Girdle of the Protector
(18525, 63, 33522, 0, 0, 1, 0, 0, 26124), -- Chestguard of the Stoic Guardian
(18525, 62, 33515, 0, 0, 1, 0, 0, 26124), -- Unwavering Legguards
(18525, 61, 33514, 0, 0, 1, 0, 0, 26124), -- Pauldrons of Gruesome Fate
(18525, 60, 33512, 0, 0, 1, 0, 0, 26124), -- Furious Deathgrips
(18525, 59, 33331, 0, 0, 1, 0, 0, 26124), -- Chain of Unleashed Rage
(18525, 58, 33513, 0, 0, 1, 0, 0, 26124), -- Eternium Rage-Shackles
(18525, 57, 33516, 0, 0, 1, 0, 0, 26124), -- Bracers of the Ancient Phalanx
(18525, 56, 33279, 0, 0, 1, 0, 0, 26124), -- Iron-Tusk Girdle
(18525, 55, 33517, 0, 0, 1, 0, 0, 26124), -- Bonefist Gauntlets
(18525, 54, 33501, 0, 0, 1, 0, 0, 26124), -- Bloodthirster's Wargreaves
(18525, 53, 33810, 0, 0, 1, 0, 0, 26124), -- Amani Mask of Death
(18525, 52, 32090, 0, 0, 1, 0, 0, 26124), -- Cowl of Naaru Blessings
(18525, 51, 32089, 0, 0, 1, 0, 0, 26124), -- Mana-Binders Cowl
(18525, 50, 32085, 0, 0, 1, 0, 0, 26124), -- Warpstalker Helm
(18525, 49, 32086, 0, 0, 1, 0, 0, 26124), -- Storm Master's Helmet
(18525, 48, 32087, 0, 0, 1, 0, 0, 26124), -- Mask of the Deceiver
(18525, 47, 32088, 0, 0, 1, 0, 0, 26124), -- Cowl of Beastly Rage
(18525, 46, 32084, 0, 0, 1, 0, 0, 26124), -- Helmet of the Steadfast Champion
(18525, 45, 32083, 0, 0, 1, 0, 0, 26124), -- Faceguard of Determination
(18525, 44, 30762, 0, 0, 1, 0, 0, 26124), -- Infernoweave Robe
(18525, 43, 30761, 0, 0, 1, 0, 0, 26124), -- Infernoweave Leggings
(18525, 42, 30764, 0, 0, 1, 0, 0, 26124), -- Infernoweave Gloves
(18525, 41, 30763, 0, 0, 1, 0, 0, 26124), -- Infernoweave Boots
(18525, 40, 30766, 0, 0, 1, 0, 0, 26124), -- Inferno Tempered Leggings
(18525, 39, 30767, 0, 0, 1, 0, 0, 26124), -- Inferno Tempered Gauntlets
(18525, 38, 30769, 0, 0, 1, 0, 0, 26124), -- Inferno Tempered Chestguard
(18525, 37, 30768, 0, 0, 1, 0, 0, 26124), -- Inferno Tempered Boots
(18525, 36, 30778, 0, 0, 1, 0, 0, 26124), -- Inferno Hardened Leggings
(18525, 35, 30780, 0, 0, 1, 0, 0, 26124), -- Inferno Hardened Gloves
(18525, 34, 30776, 0, 0, 1, 0, 0, 26124), -- Inferno Hardened Chestguard
(18525, 33, 30779, 0, 0, 1, 0, 0, 26124), -- Inferno Hardened Boots
(18525, 32, 30772, 0, 0, 1, 0, 0, 26124), -- Inferno Forged Leggings
(18525, 31, 30773, 0, 0, 1, 0, 0, 26124), -- Inferno Forged Hauberk
(18525, 30, 30774, 0, 0, 1, 0, 0, 26124), -- Inferno Forged Gloves
(18525, 29, 30770, 0, 0, 1, 0, 0, 26124), -- Inferno Forged Boots
(18525, 28, 30183, 0, 0, 1, 0, 0, 26124), -- Nether Vortex
(18525, 27, 23572, 0, 0, 1, 0, 0, 26124), -- Primal Nether
(18525, 26, 29387, 0, 0, 1, 0, 0, 26124), -- Gnomeregan Auto-Dodger 600
(18525, 25, 29383, 0, 0, 1, 0, 0, 26124), -- Bloodlust Brooch
(18525, 24, 29376, 0, 0, 1, 0, 0, 26124), -- Essence of the Martyr
(18525, 23, 29370, 0, 0, 1, 0, 0, 26124), -- Icon of the Silver Crescent
(18525, 22, 29385, 0, 0, 1, 0, 0, 26124), -- Farstrider Defender's Cloak
(18525, 21, 29382, 0, 0, 1, 0, 0, 26124), -- Blood Knight War Cloak
(18525, 20, 29375, 0, 0, 1, 0, 0, 26124), -- Bishop's Cloak
(18525, 19, 29369, 0, 0, 1, 0, 0, 26124), -- Shawl of Shifting Probabilities
(18525, 18, 29386, 0, 0, 1, 0, 0, 26124), -- Necklace of the Juggernaut
(18525, 17, 29381, 0, 0, 1, 0, 0, 26124), -- Choker of Vile Intent
(18525, 16, 29374, 0, 0, 1, 0, 0, 26124), -- Necklace of Eternal Hope
(18525, 15, 29368, 0, 0, 1, 0, 0, 26124), -- Manasurge Pendant
(18525, 14, 29384, 0, 0, 1, 0, 0, 26124), -- Ring of Unyielding Force
(18525, 13, 29379, 0, 0, 1, 0, 0, 26124), -- Ring of Arathi Warlords
(18525, 12, 29373, 0, 0, 1, 0, 0, 26124), -- Band of Halos
(18525, 11, 29367, 0, 0, 1, 0, 0, 26124), -- Ring of Cryptic Dreams
(18525, 10, 29266, 0, 0, 1, 0, 0, 26124), -- Azure-Shield of Coldarra
(18525, 9, 29272, 0, 0, 1, 0, 0, 26124), -- Orb of the Soul-Eater
(18525, 8, 29267, 0, 0, 1, 0, 0, 26124), -- Light-Bearer's Faith Shield
(18525, 7, 29274, 0, 0, 1, 0, 0, 26124), -- Tears of Heaven
(18525, 6, 29269, 0, 0, 1, 0, 0, 26124), -- Sapphiron's Wing Bone
(18525, 5, 29270, 0, 0, 1, 0, 0, 26124), -- Flametongue Seal
(18525, 4, 29275, 0, 0, 1, 0, 0, 26124), -- Searing Sunblade
(18525, 3, 29268, 0, 0, 1, 0, 0, 26124), -- Mazthoril Honor Shield
(18525, 2, 29271, 0, 0, 1, 0, 0, 26124), -- Talisman of Kalecgos
(18525, 1, 29273, 0, 0, 1, 0, 0, 26124), -- Khadgar's Knapsack
(27667, 62, 34952, 0, 0, 1, 0, 0, 26124), -- The Mutilator
(27667, 61, 34949, 0, 0, 1, 0, 0, 26124), -- Swift Blade of Uncertainty
(27667, 60, 34894, 0, 0, 1, 0, 0, 26124), -- Blade of Serration
(27667, 59, 34951, 0, 0, 1, 0, 0, 26124), -- Vanir's Fist of Carnage
(27667, 58, 34950, 0, 0, 1, 0, 0, 26124), -- Vanir's Fist of Savagery
(27667, 57, 34893, 0, 0, 1, 0, 0, 26124), -- Vanir's Fist of Brutality
(27667, 56, 34896, 0, 0, 1, 0, 0, 26124), -- Gavel of Naaru Blessings
(27667, 55, 34898, 0, 0, 1, 0, 0, 26124), -- Staff of the Forest Lord
(27667, 54, 34892, 0, 0, 1, 0, 0, 26124), -- Crossbow of Relentless Strikes
(27667, 53, 34895, 0, 0, 1, 0, 0, 26124), -- Scryer's Blade of Focus
(27667, 52, 34891, 0, 0, 1, 0, 0, 26124), -- The Blade of Harbingers
(27667, 51, 34888, 0, 0, 1, 0, 0, 26124), -- Ring of the Stalwart Protector
(27667, 50, 34887, 0, 0, 1, 0, 0, 26124), -- Angelista's Revenge
(27667, 49, 34890, 0, 0, 1, 0, 0, 26124), -- Anveena's Touch
(27667, 48, 34889, 0, 0, 1, 0, 0, 26124), -- Fused Nethergon Band
(27667, 47, 34940, 0, 0, 1, 0, 0, 26124), -- Sunguard Legplates
(27667, 46, 34939, 0, 0, 1, 0, 0, 26124), -- Chestplate of Stoicism
(27667, 45, 34941, 0, 0, 1, 0, 0, 26124), -- Girdle of the Fearless
(27667, 44, 34943, 0, 0, 1, 0, 0, 26124), -- Legplates of Unending Fury
(27667, 43, 34942, 0, 0, 1, 0, 0, 26124), -- Breastplate of Ire
(27667, 42, 34944, 0, 0, 1, 0, 0, 26124), -- Girdle of Seething Rage
(27667, 41, 34946, 0, 0, 1, 0, 0, 26124), -- Inscribed Legplates of the Aldor
(27667, 40, 34945, 0, 0, 1, 0, 0, 26124), -- Shattrath Protectorate's Breastplate
(27667, 39, 34947, 0, 0, 1, 0, 0, 26124), -- Blue's Greaves of the Righteous Guardian
(27667, 38, 34922, 0, 0, 1, 0, 0, 26124), -- Greaves of Pacification
(27667, 37, 34921, 0, 0, 1, 0, 0, 26124), -- Ecclesiastical Cuirass
(27667, 36, 34923, 0, 0, 1, 0, 0, 26124), -- Waistguard of Reparation
(27667, 35, 34934, 0, 0, 1, 0, 0, 26124), -- Rushing Storm Kilt
(27667, 34, 34933, 0, 0, 1, 0, 0, 26124), -- Hauberk of Whirling Fury
(27667, 33, 34935, 0, 0, 1, 0, 0, 26124), -- Aftershock Waistguard
(27667, 32, 34931, 0, 0, 1, 0, 0, 26124), -- Runed Scales of Antiquity
(27667, 31, 34930, 0, 0, 1, 0, 0, 26124), -- Wave of Life Chestguard
(27667, 30, 34932, 0, 0, 1, 0, 0, 26124), -- Clutch of the Soothing Breeze
(27667, 29, 34914, 0, 0, 1, 0, 0, 26124), -- Leggings of the Pursuit
(27667, 28, 34916, 0, 0, 1, 0, 0, 26124), -- Gauntlets of Rapidity
(27667, 27, 34912, 0, 0, 1, 0, 0, 26124), -- Scaled Drakeskin Chestguard
(27667, 26, 34928, 0, 0, 1, 0, 0, 26124), -- Trousers of the Scryers' Retainer
(27667, 25, 34927, 0, 0, 1, 0, 0, 26124), -- Tunic of the Dark Hour
(27667, 24, 34929, 0, 0, 1, 0, 0, 26124), -- Belt of the Silent Path
(27667, 23, 34905, 0, 0, 1, 0, 0, 26124), -- Crystalwind Leggings
(27667, 22, 34904, 0, 0, 1, 0, 0, 26124), -- Barbed Gloves of the Sage
(27667, 21, 34903, 0, 0, 1, 0, 0, 26124), -- Embrace of Starlight
(27667, 20, 34910, 0, 0, 1, 0, 0, 26124), -- Tameless Breeches
(27667, 19, 34911, 0, 0, 1, 0, 0, 26124), -- Handwraps of the Aggressor
(27667, 18, 34906, 0, 0, 1, 0, 0, 26124), -- Embrace of Everlasting Prowess
(27667, 17, 34901, 0, 0, 1, 0, 0, 26124), -- Grovewalker's Leggings
(27667, 16, 34902, 0, 0, 1, 0, 0, 26124), -- Oakleaf-Spun Handguards
(27667, 15, 34900, 0, 0, 1, 0, 0, 26124), -- Shroud of Nature's Harmony
(27667, 14, 34936, 0, 0, 1, 0, 0, 26124), -- Tormented Demonsoul Robes
(27667, 13, 34937, 0, 0, 1, 0, 0, 26124), -- Corrupted Soulcloth Pantaloons
(27667, 12, 34938, 0, 0, 1, 0, 0, 26124), -- Enslaved Doomguard Soulgrips
(27667, 11, 34924, 0, 0, 1, 0, 0, 26124), -- Gown of Spiritual Wonder
(27667, 10, 34925, 0, 0, 1, 0, 0, 26124), -- Adorned Supernal Legwraps
(27667, 9, 34926, 0, 0, 1, 0, 0, 26124), -- Slippers of Dutiful Mending
(27667, 8, 34917, 0, 0, 1, 0, 0, 26124), -- Shroud of the Lore`nial
(27667, 7, 34918, 0, 0, 1, 0, 0, 26124), -- Legwraps of Sweltering Flame
(27667, 6, 34919, 0, 0, 1, 0, 0, 26124), -- Boots of Incantations
(52278, 18, 15198, 0, 5962, 1, 0, 0, 26124), -- Knight's Colors
(52278, 17, 15196, 0, 5962, 1, 0, 0, 26124), -- Private's Tabard
(52278, 16, 19032, 0, 5992, 1, 0, 0, 26124), -- Stormpike Battle Tabard
(52278, 15, 19506, 0, 5992, 1, 0, 0, 26124), -- Silverwing Battle Tabard
(52278, 14, 31774, 0, 0, 1, 0, 0, 26124), -- Kurenai Tabard
(52278, 13, 23999, 0, 0, 1, 0, 0, 26124), -- Honor Hold Tabard
(19049, 1, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(19197, 12, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19197, 11, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19197, 10, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19678, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19661, 2129, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19661, 2125, 90146, 0, 0, 1, 0, 0, 26124), -- Tinker's Kit
(19227, 11, 74918, 0, 0, 1, 0, 0, 26124), -- Problem Solving Pendant
(18756, 5032, 134007, 0, 0, 1, 0, 0, 26124), -- Eternal Black Diamond Ring
(18756, 5029, 134004, 1, 0, 1, 0, 0, 26124), -- Noble's Eternal Elementium Signet
(19186, 11, 82344, 0, 0, 1, 0, 0, 26124), -- Hearthglen Ambrosia
(19186, 10, 83094, 0, 0, 1, 0, 0, 26124), -- Foote Tripel
(19186, 9, 82343, 0, 0, 1, 0, 0, 26124), -- Lordaeron Lambic
(19186, 8, 83095, 0, 0, 1, 0, 0, 26124), -- Lagrave Stout
(18484, 3953, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(18484, 3942, 90146, 0, 0, 1, 0, 0, 26124); -- Tinker's Kit

UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19056 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19056 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19056 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19056 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19056 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19056 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=27692 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Warp Burger
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19038 AND `item`=27690 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Blackened Basilisk
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28557 AND `ExtendedCost`=298 AND `type`=1); -- Quickened Starfire Diamond
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28556 AND `ExtendedCost`=298 AND `type`=1); -- Swift Windfire Diamond
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28759 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Dreadweave Hood
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28760 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Silk Hood
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28575 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Wyrmhide Helm
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28574 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Dragonhide Helm
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28561 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Leather Helm
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28758 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Mail Helm
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28577 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Linked Helm
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28576 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Chain Helm
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28761 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Scaled Helm
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28560 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Lamellar Helm
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28559 AND `ExtendedCost`=194 AND `type`=1); -- Exorcist's Plate Helm
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28555 AND `ExtendedCost`=293 AND `type`=1); -- Seal of the Exorcist
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=28553 AND `ExtendedCost`=293 AND `type`=1); -- Band of the Exorcist
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=32948 AND `ExtendedCost`=1992 AND `type`=1); -- Auchenai Mana Potion
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19773 AND `item`=32947 AND `ExtendedCost`=1992 AND `type`=1); -- Auchenai Healing Potion
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=29452 AND `ExtendedCost`=0 AND `type`=1); -- Zangar Trout
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=27858 AND `ExtendedCost`=0 AND `type`=1); -- Sunspring Carp
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=27700 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Spicy Crawdad
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19296 AND `item`=27699 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Golden Fish Sticks
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=24905 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30745 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Toolbox
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1); -- Mining Sack
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30747 AND `ExtendedCost`=0 AND `type`=1); -- Gem Pouch
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30748 AND `ExtendedCost`=0 AND `type`=1); -- Enchanter's Satchel
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19042 AND `item`=22911 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Major Dreamless Sleep Potion
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19042 AND `item`=22901 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Sneaking Potion
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19042 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19042 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=3, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19234 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19245 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=21905 AND `item`=30196 AND `ExtendedCost`=1357 AND `type`=1); -- Robes of Tirisfal
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=21905 AND `item`=30210 AND `ExtendedCost`=1361 AND `type`=1); -- Mantle of Tirisfal
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=21905 AND `item`=30207 AND `ExtendedCost`=1360 AND `type`=1); -- Leggings of Tirisfal
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21905 AND `item`=30205 AND `ExtendedCost`=1358 AND `type`=1); -- Gloves of Tirisfal
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21905 AND `item`=30206 AND `ExtendedCost`=1359 AND `type`=1); -- Cowl of Tirisfal
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=20613 AND `item`=29079 AND `ExtendedCost`=1219 AND `type`=1); -- Pauldrons of the Aldor
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=20613 AND `item`=29078 AND `ExtendedCost`=1218 AND `type`=1); -- Legwraps of the Aldor
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=20613 AND `item`=29076 AND `ExtendedCost`=1217 AND `type`=1); -- Collar of the Aldor
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=20613 AND `item`=29080 AND `ExtendedCost`=1216 AND `type`=1); -- Gloves of the Aldor
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=20613 AND `item`=29077 AND `ExtendedCost`=1215 AND `type`=1); -- Vestments of the Aldor
UPDATE `npc_vendor` SET `slot`=12, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=11, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33634 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=33631 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=33631 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=33631 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=33631 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=33631 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33631 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33635 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33636 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33630 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=33639 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33639 AND `item`=22250 AND `ExtendedCost`=0 AND `type`=1); -- Herb Pouch
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19240 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19240 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19240 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19240 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19240 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19240 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5239 AND `ExtendedCost`=0 AND `type`=1); -- Blackbone Wand
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5238 AND `ExtendedCost`=0 AND `type`=1); -- Pitchwood Wand
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5347 AND `ExtendedCost`=0 AND `type`=1); -- Pestilent Wand
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5236 AND `ExtendedCost`=0 AND `type`=1); -- Combustible Wand
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5211 AND `ExtendedCost`=0 AND `type`=1); -- Dusk Wand
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5210 AND `ExtendedCost`=0 AND `type`=1); -- Burning Wand
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5209 AND `ExtendedCost`=0 AND `type`=1); -- Gloom Wand
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19236 AND `item`=5208 AND `ExtendedCost`=0 AND `type`=1); -- Smoldering Wand
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28470 AND `ExtendedCost`=0 AND `type`=1); -- Subtle Amber
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28467 AND `ExtendedCost`=0 AND `type`=1); -- Smooth Amber
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28468 AND `ExtendedCost`=0 AND `type`=1); -- Rigid Zircon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28464 AND `ExtendedCost`=0 AND `type`=1); -- Sparkling Zircon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28463 AND `ExtendedCost`=0 AND `type`=1); -- Solid Zircon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28459 AND `ExtendedCost`=0 AND `type`=1); -- Delicate Tourmaline
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28461 AND `ExtendedCost`=0 AND `type`=1); -- Brilliant Tourmaline
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19330 AND `item`=28458 AND `ExtendedCost`=0 AND `type`=1); -- Bold Tourmaline
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19239 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19239 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19232 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=33640 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=33640 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=33640 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=33640 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33640 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=50, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=49112 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Nightmare Tear
UPDATE `npc_vendor` SET `slot`=49, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47020 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Deft Ametrine
UPDATE `npc_vendor` SET `slot`=48, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47022 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Resolute Ametrine
UPDATE `npc_vendor` SET `slot`=47, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47021 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Lucent Ametrine
UPDATE `npc_vendor` SET `slot`=46, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47019 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Fierce Ametrine
UPDATE `npc_vendor` SET `slot`=45, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47018 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Resplendent Ametrine
UPDATE `npc_vendor` SET `slot`=44, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47017 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Stalwart Ametrine
UPDATE `npc_vendor` SET `slot`=43, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47015 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Champion's Ametrine
UPDATE `npc_vendor` SET `slot`=42, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47010 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Accurate Dreadstone
UPDATE `npc_vendor` SET `slot`=41, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=47007 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Reckless Ametrine
UPDATE `npc_vendor` SET `slot`=40, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46956 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Glinting Dreadstone
UPDATE `npc_vendor` SET `slot`=39, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46953 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Etched Dreadstone
UPDATE `npc_vendor` SET `slot`=38, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46952 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Willful Ametrine
UPDATE `npc_vendor` SET `slot`=37, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46951 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Veiled Dreadstone
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46950 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Potent Ametrine
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46949 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Deadly Ametrine
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46948 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Inscribed Ametrine
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46943 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Mysterious Dreadstone
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46942 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Guardian's Dreadstone
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46941 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Defender's Dreadstone
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46938 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Shifting Dreadstone
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46937 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Purified Dreadstone
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46935 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Sovereign Dreadstone
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46933 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Quick King's Amber
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46932 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Mystic King's Amber
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46929 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Smooth King's Amber
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46928 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Rigid Majestic Zircon
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46926 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Stormy Majestic Zircon
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46925 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Sparkling Majestic Zircon
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46924 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Solid Majestic Zircon
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46923 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Flashing Cardinal Ruby
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46922 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Subtle King's Amber
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46920 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Precise Cardinal Ruby
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46918 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Delicate Cardinal Ruby
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46917 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Bold Cardinal Ruby
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46916 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Brilliant Cardinal Ruby
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46915 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Turbid Eye of Zul
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46913 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Shattered Eye of Zul
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46912 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Energized Eye of Zul
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46911 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Radiant Eye of Zul
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46909 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Lightning Eye of Zul
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46905 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Misty Eye of Zul
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46904 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Forceful Eye of Zul
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46902 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Timeless Dreadstone
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46901 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Jagged Eye of Zul
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46899 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Nimble Eye of Zul
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46898 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Steady Eye of Zul
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=46897 AND `ExtendedCost`=2436 AND `type`=1); -- Design: Regal Eye of Zul
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=33637 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=33633 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=4, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=33638 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1); -- Scribe's Satchel
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=33638 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=33638 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19244 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21517 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19243 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19243 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19243 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19243 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19243 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19243 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=35345 AND `ExtendedCost`=0 AND `type`=1); -- Evoker's Silk Handguards
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=31781 AND `ExtendedCost`=0 AND `type`=1); -- Sha'tar Tabard
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=29175 AND `ExtendedCost`=0 AND `type`=1); -- Gavel of Pure Light
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=29176 AND `ExtendedCost`=0 AND `type`=1); -- Crest of the Sha'tar
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=29177 AND `ExtendedCost`=0 AND `type`=1); -- A'dal's Command
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=33153 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Gloves - Threat
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=31354 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Flask of the Titans
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=13517 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Alchemist Stone
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=28281 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Weapon - Major Healing
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=29179 AND `ExtendedCost`=0 AND `type`=1); -- Xi'ri's Gift
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=29180 AND `ExtendedCost`=0 AND `type`=1); -- Blessed Scale Girdle
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=24182 AND `ExtendedCost`=0 AND `type`=1); -- Design: Talasite Owl
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=33159 AND `ExtendedCost`=0 AND `type`=1); -- Design: Blood of Amber
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=30826 AND `ExtendedCost`=0 AND `type`=1); -- Design: Ring of Arcane Shielding
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=22915 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Primal Air to Fire
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=29717 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Drums of Battle
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=33155 AND `ExtendedCost`=0 AND `type`=1); -- Design: Kailee's Rose
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=28273 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Gloves - Major Healing
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21432 AND `item`=25904 AND `ExtendedCost`=0 AND `type`=1); -- Design: Insightful Earthstorm Diamond
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35325 AND `ExtendedCost`=0 AND `type`=1); -- Design: Forceful Talasite
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35323 AND `ExtendedCost`=0 AND `type`=1); -- Design: Reckless Noble Topaz
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35322 AND `ExtendedCost`=0 AND `type`=1); -- Design: Quick Dawnstone
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35243 AND `ExtendedCost`=0 AND `type`=1); -- Design: Sovereign Shadowsong Amethyst
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35265 AND `ExtendedCost`=0 AND `type`=1); -- Design: Stormy Empyrean Sapphire
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35247 AND `ExtendedCost`=0 AND `type`=1); -- Design: Flashing Crimson Spinel
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35242 AND `ExtendedCost`=0 AND `type`=1); -- Design: Shifting Shadowsong Amethyst
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35258 AND `ExtendedCost`=0 AND `type`=1); -- Design: Mystic Lionseye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35270 AND `ExtendedCost`=0 AND `type`=1); -- Design: Veiled Shadowsong Amethyst
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35267 AND `ExtendedCost`=0 AND `type`=1); -- Design: Inscribed Pyrestone
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35769 AND `ExtendedCost`=0 AND `type`=1); -- Design: Forceful Seaspray Emerald
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35766 AND `ExtendedCost`=0 AND `type`=1); -- Design: Steady Seaspray Emerald
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35767 AND `ExtendedCost`=0 AND `type`=1); -- Design: Reckless Pyrestone
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35768 AND `ExtendedCost`=0 AND `type`=1); -- Design: Quick Lionseye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35271 AND `ExtendedCost`=0 AND `type`=1); -- Design: Deadly Pyrestone
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35259 AND `ExtendedCost`=0 AND `type`=1); -- Design: Rigid Empyrean Sapphire
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35252 AND `ExtendedCost`=0 AND `type`=1); -- Design: Regal Seaspray Emerald
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35251 AND `ExtendedCost`=0 AND `type`=1); -- Design: Purified Shadowsong Amethyst
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35266 AND `ExtendedCost`=0 AND `type`=1); -- Design: Glinting Shadowsong Amethyst
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35239 AND `ExtendedCost`=0 AND `type`=1); -- Design: Timeless Shadowsong Amethyst
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35253 AND `ExtendedCost`=0 AND `type`=1); -- Design: Jagged Seaspray Emerald
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35254 AND `ExtendedCost`=0 AND `type`=1); -- Design: Radiant Seaspray Emerald
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35269 AND `ExtendedCost`=0 AND `type`=1); -- Design: Potent Pyrestone
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35246 AND `ExtendedCost`=0 AND `type`=1); -- Design: Delicate Crimson Spinel
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35248 AND `ExtendedCost`=0 AND `type`=1); -- Design: Brilliant Crimson Spinel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35260 AND `ExtendedCost`=0 AND `type`=1); -- Design: Smooth Lionseye
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35249 AND `ExtendedCost`=0 AND `type`=1); -- Design: Subtle Lionseye
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35263 AND `ExtendedCost`=0 AND `type`=1); -- Design: Solid Empyrean Sapphire
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35244 AND `ExtendedCost`=0 AND `type`=1); -- Design: Bold Crimson Spinel
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=27666 AND `item`=35264 AND `ExtendedCost`=0 AND `type`=1); -- Design: Sparkling Empyrean Sapphire
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=35221 AND `ExtendedCost`=0 AND `type`=1); -- Tabard of the Shattered Sun
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31775 AND `ExtendedCost`=1994 AND `type`=1); -- Sporeggar Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=32445 AND `ExtendedCost`=0 AND `type`=1); -- Skyguard Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31781 AND `ExtendedCost`=0 AND `type`=1); -- Sha'tar Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31780 AND `ExtendedCost`=0 AND `type`=1); -- Scryers Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=32828 AND `ExtendedCost`=1958 AND `type`=1); -- Ogri'la Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31778 AND `ExtendedCost`=0 AND `type`=1); -- Lower City Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31777 AND `ExtendedCost`=0 AND `type`=1); -- Keepers of Time Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31776 AND `ExtendedCost`=0 AND `type`=1); -- Consortium Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31804 AND `ExtendedCost`=0 AND `type`=1); -- Cenarion Expedition Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=31779 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=52278 AND `item`=5976 AND `ExtendedCost`=0 AND `type`=1); -- Guild Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28889 AND `ExtendedCost`=1188 AND `type`=1); -- Greater Inscription of Warding
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28888 AND `ExtendedCost`=1188 AND `type`=1); -- Greater Inscription of Vengeance
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28887 AND `ExtendedCost`=1188 AND `type`=1); -- Greater Inscription of Faith
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28886 AND `ExtendedCost`=1188 AND `type`=1); -- Greater Inscription of Discipline
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28882 AND `ExtendedCost`=1184 AND `type`=1); -- Inscription of Warding
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28885 AND `ExtendedCost`=1184 AND `type`=1); -- Inscription of Vengeance
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28878 AND `ExtendedCost`=1184 AND `type`=1); -- Inscription of Faith
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20807 AND `item`=28881 AND `ExtendedCost`=1184 AND `type`=1); -- Inscription of Discipline
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=31779 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29124 AND `ExtendedCost`=0 AND `type`=1); -- Vindicator's Brand
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29123 AND `ExtendedCost`=0 AND `type`=1); -- Medallion of the Lightbearer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29128 AND `ExtendedCost`=0 AND `type`=1); -- Lightwarden's Band
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=24295 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Golden Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=23602 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Flamebane Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29702 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blastguard Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29689 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Flamescale Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=30844 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Flameheart Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=24177 AND `ExtendedCost`=0 AND `type`=1); -- Design: Pendant of Shadow's End
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29127 AND `ExtendedCost`=0 AND `type`=1); -- Vindicator's Hauberk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29130 AND `ExtendedCost`=0 AND `type`=1); -- Auchenai Staff
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29129 AND `ExtendedCost`=0 AND `type`=1); -- Anchorite's Robes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=25721 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Vindicator's Armor Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=23604 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Flamebane Breastplate
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29703 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blastguard Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29691 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Flamescale Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=24293 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Silver Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=30843 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Flameheart Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=23603 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Flamebane Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=23145 AND `ExtendedCost`=0 AND `type`=1); -- Design: Purified Shadow Draenite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=23601 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Flamebane Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29693 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Flamescale Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=29704 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blastguard Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=30842 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Flameheart Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19321 AND `item`=23149 AND `ExtendedCost`=0 AND `type`=1); -- Design: Smooth Golden Draenite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=31780 AND `ExtendedCost`=0 AND `type`=1); -- Scryers Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29126 AND `ExtendedCost`=0 AND `type`=1); -- Seer's Signet
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29125 AND `ExtendedCost`=0 AND `type`=1); -- Retainer's Blade
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=24294 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Runic Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29698 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Clefthoof Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=23600 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Enchanted Adamantite Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29677 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Felscale Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=25722 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Magister's Armor Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29132 AND `ExtendedCost`=0 AND `type`=1); -- Scryer's Bloodgem
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29133 AND `ExtendedCost`=0 AND `type`=1); -- Seer's Cane
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29131 AND `ExtendedCost`=0 AND `type`=1); -- Retainer's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29134 AND `ExtendedCost`=0 AND `type`=1); -- Gauntlets of the Chosen
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=23599 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Enchanted Adamantite Breastplate
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29700 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Clefthoof Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29684 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Felscale Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=23598 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Enchanted Adamantite Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=22908 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Elixir of Major Firepower
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=24176 AND `ExtendedCost`=0 AND `type`=1); -- Design: Pendant of Withering
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=24292 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Mystic Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29701 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Clefthoof Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=29682 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Felscale Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=23597 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Enchanted Adamantite Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19331 AND `item`=23133 AND `ExtendedCost`=0 AND `type`=1); -- Design: Brilliant Blood Garnet
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28909 AND `ExtendedCost`=1196 AND `type`=1); -- Greater Inscription of the Orb
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28912 AND `ExtendedCost`=1196 AND `type`=1); -- Greater Inscription of the Oracle
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28911 AND `ExtendedCost`=1196 AND `type`=1); -- Greater Inscription of the Knight
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28910 AND `ExtendedCost`=1196 AND `type`=1); -- Greater Inscription of the Blade
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28903 AND `ExtendedCost`=1192 AND `type`=1); -- Inscription of the Orb
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28904 AND `ExtendedCost`=1192 AND `type`=1); -- Inscription of the Oracle
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28908 AND `ExtendedCost`=1192 AND `type`=1); -- Inscription of the Knight
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20808 AND `item`=28907 AND `ExtendedCost`=1192 AND `type`=1); -- Inscription of the Blade
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=29452 AND `ExtendedCost`=0 AND `type`=1); -- Zangar Trout
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=27858 AND `ExtendedCost`=0 AND `type`=1); -- Sunspring Carp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1); -- Striped Yellowtail
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1); -- Rockscale Cod
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1); -- Bristle Whisker Catfish
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1); -- Longjaw Mud Snapper
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19045 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1); -- Slitherskin Mackerel
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=15904 AND `ExtendedCost`=0 AND `type`=1); -- Deadly Fist Blades
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=15903 AND `ExtendedCost`=0 AND `type`=1); -- Slicing Claw
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=15905 AND `ExtendedCost`=0 AND `type`=1); -- Brass Knuckles
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19047 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `slot`=1230, `VerifiedBuild`=26124 WHERE (`entry`=19074 AND `item`=23574 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Primal Might
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19074 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23263 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=28486 AND `ExtendedCost`=0 AND `type`=1); -- Moser's Magnificent Muffin
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=30747 AND `ExtendedCost`=0 AND `type`=1); -- Gem Pouch
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=30748 AND `ExtendedCost`=0 AND `type`=1); -- Enchanter's Satchel
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=30745 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Toolbox
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1); -- Mining Sack
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=60335 AND `ExtendedCost`=0 AND `type`=1); -- Thick Hide Pack
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=5048 AND `ExtendedCost`=0 AND `type`=1); -- Blue Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19197 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19664 AND `item`=28486 AND `ExtendedCost`=0 AND `type`=1); -- Moser's Magnificent Muffin
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=35344 AND `ExtendedCost`=0 AND `type`=1); -- Evoker's Silk Cowl
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=33157 AND `ExtendedCost`=0 AND `type`=1); -- Design: Falling Star
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=31778 AND `ExtendedCost`=0 AND `type`=1); -- Lower City Tabard
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=30830 AND `ExtendedCost`=0 AND `type`=1); -- Trident of the Outcast Tribe
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=30834 AND `ExtendedCost`=0 AND `type`=1); -- Shapeshifter's Signet
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=30832 AND `ExtendedCost`=0 AND `type`=1); -- Gavel of Unearthed Secrets
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=33148 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Cloak - Dodge
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=30841 AND `ExtendedCost`=0 AND `type`=1); -- Lower City Prayerbook
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=30835 AND `ExtendedCost`=0 AND `type`=1); -- Salvager's Hauberk
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=30836 AND `ExtendedCost`=0 AND `type`=1); -- Leggings of the Skettis Exile
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=22910 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Elixir of Major Shadow Power
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=24175 AND `ExtendedCost`=0 AND `type`=1); -- Design: Pendant of Thawing
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=24179 AND `ExtendedCost`=0 AND `type`=1); -- Design: Felsteel Boar
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=30833 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Cloak of Arcane Evasion
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21655 AND `item`=23138 AND `ExtendedCost`=0 AND `type`=1); -- Design: Potent Flame Spessarite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19195 AND `item`=21219 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Sagefish Delight
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19195 AND `item`=21099 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Smoked Sagefish
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19195 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19195 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19195 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `slot`=9177, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=28282 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Shield - Major Stamina
UPDATE `npc_vendor` SET `slot`=9176, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=9175, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=9174, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=9173, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=9172, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=9171, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=9170, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=9169, `maxcount`=3, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=9168, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9167, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `slot`=9166, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22563 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Superior Wizard Oil
UPDATE `npc_vendor` SET `slot`=9165, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22565 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Large Prismatic Shard
UPDATE `npc_vendor` SET `slot`=9164, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22562 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Superior Mana Oil
UPDATE `npc_vendor` SET `slot`=9177, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=28282 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Shield - Major Stamina
UPDATE `npc_vendor` SET `slot`=9176, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=9175, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=9174, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=9173, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=9172, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=9171, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=9170, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=9169, `maxcount`=3, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=9168, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9167, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `slot`=9166, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22563 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Superior Wizard Oil
UPDATE `npc_vendor` SET `slot`=9165, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22565 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Large Prismatic Shard
UPDATE `npc_vendor` SET `slot`=9164, `VerifiedBuild`=26124 WHERE (`entry`=19663 AND `item`=22562 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Superior Mana Oil
UPDATE `npc_vendor` SET `slot`=4894, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=23590 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Maul
UPDATE `npc_vendor` SET `slot`=4893, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=23593 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Rapier
UPDATE `npc_vendor` SET `slot`=4892, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=23592 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Dagger
UPDATE `npc_vendor` SET `slot`=4891, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=23591 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Adamantite Cleaver
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19662 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19223 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19678 AND `item`=30823 AND `ExtendedCost`=0 AND `type`=1); -- Demon Warding Totem
UPDATE `npc_vendor` SET `slot`=2136, `VerifiedBuild`=26124 WHERE (`entry`=19661 AND `item`=23799 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Adamantite Rifle
UPDATE `npc_vendor` SET `slot`=2128, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19661 AND `item`=23783 AND `ExtendedCost`=0 AND `type`=1); -- Handful of Fel Iron Bolts
UPDATE `npc_vendor` SET `slot`=2127, `maxcount`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19661 AND `item`=23736 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Bomb
UPDATE `npc_vendor` SET `slot`=2126, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19661 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=2124, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19661 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=2123, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19661 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=34249 AND `ExtendedCost`=0 AND `type`=1); -- Hula Girl Doll
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27940 AND `ExtendedCost`=0 AND `type`=1); -- Marvelous Madstone of Immortality
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27944 AND `ExtendedCost`=0 AND `type`=1); -- Talisman of True Treasure Tracking
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27982 AND `ExtendedCost`=0 AND `type`=1); -- Charm of Potent and Powerful Passions
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27976 AND `ExtendedCost`=0 AND `type`=1); -- Polished Pendant of Edible Energy
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27941 AND `ExtendedCost`=0 AND `type`=1); -- Compassionate Critter's Friend
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27945 AND `ExtendedCost`=0 AND `type`=1); -- Shark's Tooth of Bona Fide Fluidic Mobility
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27979 AND `ExtendedCost`=0 AND `type`=1); -- Stone of Stupendous Springing Strides
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27992 AND `ExtendedCost`=0 AND `type`=1); -- Infallible Tikbalang Ward
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19227 AND `item`=27978 AND `ExtendedCost`=0 AND `type`=1); -- Soap on a Rope
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=21896 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Netherweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=21897 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Netherweave Tunic
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=21892 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Bolt of Imbued Netherweave
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19213 AND `item`=21893 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Imbued Netherweave Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22208 AND `item`=21919 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Primal Mooncloth Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22208 AND `item`=21917 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Primal Mooncloth Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22208 AND `item`=21918 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Primal Mooncloth Shoulders
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22208 AND `item`=21916 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Primal Mooncloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22208 AND `item`=21895 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Primal Mooncloth
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22213 AND `item`=21911 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Spellfire Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22213 AND `item`=21910 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Spellfire Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22213 AND `item`=21909 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Spellfire Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22213 AND `item`=21908 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Spellfire Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22213 AND `item`=24316 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Spellcloth
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22212 AND `item`=21915 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Ebon Shadowbag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22212 AND `item`=21913 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Frozen Shadoweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22212 AND `item`=21914 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Frozen Shadoweave Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22212 AND `item`=21912 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Frozen Shadoweave Shoulders
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22212 AND `item`=30483 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Shadowcloth
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19196 AND `item`=38518 AND `ExtendedCost`=0 AND `type`=1); -- Cro's Apple
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=23699 AND `item`=33042 AND `ExtendedCost`=0 AND `type`=1); -- Black Coffee
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19182 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=5031, `VerifiedBuild`=26124 WHERE (`entry`=18756 AND `item`=71037 AND `ExtendedCost`=0 AND `type`=1); -- Black Diamond Ring
UPDATE `npc_vendor` SET `slot`=5030, `VerifiedBuild`=26124 WHERE (`entry`=18756 AND `item`=38090 AND `ExtendedCost`=0 AND `type`=1); -- Sapphire Pinky Ring
UPDATE `npc_vendor` SET `slot`=5028, `VerifiedBuild`=26124 WHERE (`entry`=18756 AND `item`=37934 AND `ExtendedCost`=0 AND `type`=1); -- Noble's Elementium Signet
UPDATE `npc_vendor` SET `slot`=5027, `VerifiedBuild`=26124 WHERE (`entry`=18756 AND `item`=38091 AND `ExtendedCost`=0 AND `type`=1); -- Gold Eternium Band
UPDATE `npc_vendor` SET `slot`=5026, `VerifiedBuild`=26124 WHERE (`entry`=18756 AND `item`=51809 AND `ExtendedCost`=0 AND `type`=1); -- Portable Hole
UPDATE `npc_vendor` SET `slot`=5025, `VerifiedBuild`=26124 WHERE (`entry`=18756 AND `item`=38082 AND `ExtendedCost`=0 AND `type`=1); -- "Gigantique" Bag
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19186 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19186 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19186 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19186 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19186 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `slot`=3966, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=23811 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: White Smoke Flare
UPDATE `npc_vendor` SET `slot`=3965, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=23816 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Fel Iron Toolbox
UPDATE `npc_vendor` SET `slot`=3952, `maxcount`=4, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=3951, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=3950, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=4404 AND `ExtendedCost`=0 AND `type`=1); -- Silver Contact
UPDATE `npc_vendor` SET `slot`=3949, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=3948, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3947, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=3946, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=3945, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=3944, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=3943, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=3941, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=3940, `VerifiedBuild`=26124 WHERE (`entry`=18484 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer

DELETE FROM `npc_vendor` WHERE (`entry`=23363 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20986 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20891 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20891 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20891 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20890 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20890 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19053 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19053 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19053 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19053 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(23363, 16, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20986, 5, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(20891, 6, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(20891, 5, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(20891, 4, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20890, 131, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20890, 120, 90146, 0, 0, 1, 0, 0, 26124), -- Tinker's Kit
(19053, 9, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(19053, 8, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(19053, 7, 28399, 0, 0, 1, 0, 0, 26124), -- Filtered Draenic Water
(19053, 6, 159, 0, 0, 1, 0, 0, 26124); -- Refreshing Spring Water

UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=23363 AND `item`=27502 AND `ExtendedCost`=0 AND `type`=1); -- Scroll of Stamina V
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=23363 AND `item`=32742 AND `ExtendedCost`=0 AND `type`=1); -- Adversarial Bloodlines
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32770 AND `ExtendedCost`=0 AND `type`=1); -- Skyguard Silver Cross
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32771 AND `ExtendedCost`=0 AND `type`=1); -- Airman's Ribbon of Gallantry
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32445 AND `ExtendedCost`=0 AND `type`=1); -- Skyguard Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32318 AND `ExtendedCost`=0 AND `type`=1); -- Silver Riding Nether Ray
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32317 AND `ExtendedCost`=0 AND `type`=1); -- Red Riding Nether Ray
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32316 AND `ExtendedCost`=0 AND `type`=1); -- Purple Riding Nether Ray
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32314 AND `ExtendedCost`=0 AND `type`=1); -- Green Riding Nether Ray
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32319 AND `ExtendedCost`=0 AND `type`=1); -- Blue Riding Nether Ray
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=38628 AND `ExtendedCost`=0 AND `type`=1); -- Nether Ray Fry
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32539 AND `ExtendedCost`=0 AND `type`=1); -- Skyguard's Drape
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32538 AND `ExtendedCost`=0 AND `type`=1); -- Skywitch's Drape
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32721 AND `ExtendedCost`=0 AND `type`=1); -- Skyguard Rations
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23367 AND `item`=32722 AND `ExtendedCost`=0 AND `type`=1); -- Enriched Terocone Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22476 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22476 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22476 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22476 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22476 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22476 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=20986 AND `item`=29394 AND `ExtendedCost`=0 AND `type`=1); -- Lyribread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20986 AND `item`=29393 AND `ExtendedCost`=0 AND `type`=1); -- Diamond Berries
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=20986 AND `item`=29395 AND `ExtendedCost`=0 AND `type`=1); -- Ethermead
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=20986 AND `item`=29454 AND `ExtendedCost`=0 AND `type`=1); -- Silverwine
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20891 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20891 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20891 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20892 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20892 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20892 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20892 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20892 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20892 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=130, `maxcount`=4, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=129, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=128, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=4404 AND `ExtendedCost`=0 AND `type`=1); -- Silver Contact
UPDATE `npc_vendor` SET `slot`=127, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=126, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=125, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=124, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=123, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=122, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=121, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=119, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=118, `VerifiedBuild`=26124 WHERE (`entry`=20890 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20893 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=500, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30745 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Toolbox
UPDATE `npc_vendor` SET `slot`=499, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1); -- Mining Sack
UPDATE `npc_vendor` SET `slot`=498, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30747 AND `ExtendedCost`=0 AND `type`=1); -- Gem Pouch
UPDATE `npc_vendor` SET `slot`=497, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30748 AND `ExtendedCost`=0 AND `type`=1); -- Enchanter's Satchel
UPDATE `npc_vendor` SET `slot`=496, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19053 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood

DELETE FROM `npc_vendor` WHERE (`entry`=19014 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19014 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19017 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19017 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19017 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19017 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19019 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(19014, 2, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(19014, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19017, 8, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19017, 7, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19017, 6, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19017, 4, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(19019, 1, 37460, 0, 0, 1, 0, 0, 26124); -- Rope Pet Leash

UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Setting
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=60335 AND `ExtendedCost`=0 AND `type`=1); -- Thick Hide Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=81400 AND `ExtendedCost`=0 AND `type`=1); -- Pounded Rice Cake
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=58274 AND `ExtendedCost`=0 AND `type`=1); -- Fresh Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=74636 AND `ExtendedCost`=0 AND `type`=1); -- Golden Carp Consomme
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=81414 AND `ExtendedCost`=0 AND `type`=1); -- Pearl Milk Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=81406 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Barley Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=81409 AND `ExtendedCost`=0 AND `type`=1); -- Tangy Yogurt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=81401 AND `ExtendedCost`=0 AND `type`=1); -- Yak Cheese Curds
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=81415 AND `ExtendedCost`=0 AND `type`=1); -- Pandaren Plum Wine
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=62822 AND `item`=81407 AND `ExtendedCost`=0 AND `type`=1); -- Four Wind Soju
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27679 AND `ExtendedCost`=18 AND `type`=1); -- Mystic Dawnstone
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27680 AND `ExtendedCost`=7 AND `type`=1); -- Halaani Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27648 AND `ExtendedCost`=5 AND `type`=1); -- Dreamstalker Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27645 AND `ExtendedCost`=6 AND `type`=1); -- Dreamstalker Sash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27652 AND `ExtendedCost`=5 AND `type`=1); -- Stormbreaker's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27643 AND `ExtendedCost`=6 AND `type`=1); -- Stormbreaker's Girdle
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27653 AND `ExtendedCost`=5 AND `type`=1); -- Slayer's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27639 AND `ExtendedCost`=6 AND `type`=1); -- Slayer's Waistguard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27650 AND `ExtendedCost`=5 AND `type`=1); -- Shadowstalker's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27637 AND `ExtendedCost`=6 AND `type`=1); -- Shadowstalker's Sash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27649 AND `ExtendedCost`=5 AND `type`=1); -- Hierophant's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27638 AND `ExtendedCost`=6 AND `type`=1); -- Hierophant's Sash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27647 AND `ExtendedCost`=5 AND `type`=1); -- Marksman's Legguards
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27646 AND `ExtendedCost`=6 AND `type`=1); -- Marksman's Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27654 AND `ExtendedCost`=5 AND `type`=1); -- Avenger's Legplates
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27644 AND `ExtendedCost`=6 AND `type`=1); -- Avenger's Waistguard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=33783 AND `ExtendedCost`=2236 AND `type`=1); -- Design: Steady Talasite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=32071 AND `ExtendedCost`=1765 AND `type`=1); -- Recipe: Elixir of Ironskin
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27679 AND `ExtendedCost`=18 AND `type`=1); -- Mystic Dawnstone
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27680 AND `ExtendedCost`=7 AND `type`=1); -- Halaani Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27648 AND `ExtendedCost`=5 AND `type`=1); -- Dreamstalker Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27645 AND `ExtendedCost`=6 AND `type`=1); -- Dreamstalker Sash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27652 AND `ExtendedCost`=5 AND `type`=1); -- Stormbreaker's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27643 AND `ExtendedCost`=6 AND `type`=1); -- Stormbreaker's Girdle
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27653 AND `ExtendedCost`=5 AND `type`=1); -- Slayer's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27639 AND `ExtendedCost`=6 AND `type`=1); -- Slayer's Waistguard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27650 AND `ExtendedCost`=5 AND `type`=1); -- Shadowstalker's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27637 AND `ExtendedCost`=6 AND `type`=1); -- Shadowstalker's Sash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27649 AND `ExtendedCost`=5 AND `type`=1); -- Hierophant's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27638 AND `ExtendedCost`=6 AND `type`=1); -- Hierophant's Sash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27647 AND `ExtendedCost`=5 AND `type`=1); -- Marksman's Legguards
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27646 AND `ExtendedCost`=6 AND `type`=1); -- Marksman's Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27654 AND `ExtendedCost`=5 AND `type`=1); -- Avenger's Legplates
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=27644 AND `ExtendedCost`=6 AND `type`=1); -- Avenger's Waistguard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=33783 AND `ExtendedCost`=2236 AND `type`=1); -- Design: Steady Talasite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18822 AND `item`=32071 AND `ExtendedCost`=1765 AND `type`=1); -- Recipe: Elixir of Ironskin
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21487 AND `item`=30615 AND `ExtendedCost`=0 AND `type`=1); -- Halaani Whiskey
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21487 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21487 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21487 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21487 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21487 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21487 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=24208 AND `ExtendedCost`=0 AND `type`=1); -- Design: Mystic Dawnstone
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=29228 AND `ExtendedCost`=1646 AND `type`=1); -- Reins of the Dark War Talbuk
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=28915 AND `ExtendedCost`=1647 AND `type`=1); -- Reins of the Dark Riding Talbuk
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=30598 AND `ExtendedCost`=0 AND `type`=1); -- Don Amancio's Heart
UPDATE `npc_vendor` SET `slot`=10, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=30597 AND `ExtendedCost`=0 AND `type`=1); -- Halaani Claymore
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=30569 AND `ExtendedCost`=0 AND `type`=1); -- Proximo's Rudius
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=30750 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Warblade
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21485 AND `item`=30749 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Sparring Blade
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30759 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Recurve
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30757 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Light Crossbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30758 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Guardian Rifle
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30759 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Recurve
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30757 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Light Crossbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30758 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Guardian Rifle
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19021 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19012 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `slot`=1672, `VerifiedBuild`=26124 WHERE (`entry`=19017 AND `item`=21902 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Soulcloth Gloves
UPDATE `npc_vendor` SET `slot`=1671, `VerifiedBuild`=26124 WHERE (`entry`=19017 AND `item`=21894 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Bolt of Soulcloth
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19017 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19017 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=31774 AND `ExtendedCost`=0 AND `type`=1); -- Kurenai Tabard
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29231 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the White War Talbuk
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29230 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the Tan War Talbuk
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29229 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the Silver War Talbuk
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29227 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the Cobalt War Talbuk
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=31836 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the White Riding Talbuk
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=31834 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the Tan Riding Talbuk
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=31832 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the Silver Riding Talbuk
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=31830 AND `ExtendedCost`=0 AND `type`=1); -- Reins of the Cobalt Riding Talbuk
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29140 AND `ExtendedCost`=0 AND `type`=1); -- Cloak of the Ancient Spirits
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29138 AND `ExtendedCost`=0 AND `type`=1); -- Arechron's Gift
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29136 AND `ExtendedCost`=0 AND `type`=1); -- Far Seer's Helm
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29146 AND `ExtendedCost`=0 AND `type`=1); -- Band of Elemental Spirits
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29148 AND `ExtendedCost`=0 AND `type`=1); -- Blackened Leather Spaulders
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29142 AND `ExtendedCost`=0 AND `type`=1); -- Kurenai Kilt
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=30443 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Primal Fire to Earth
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29218 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Netherfury Boots
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=30444 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Reinforced Mining Bag
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=34175 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Drums of Restoration
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=34173 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Drums of Speed
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29219 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Netherfury Leggings
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=20240 AND `item`=29217 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Netherfury Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20096 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20096 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20096 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20096 AND `item`=27691 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Roasted Clefthoof
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20096 AND `item`=27698 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Poached Bluefish
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20096 AND `item`=27697 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Grilled Mudfish
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20096 AND `item`=27693 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Talbuk Steak

DELETE FROM `npc_vendor` WHERE (`entry`=18278 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18278 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23007 AND `item`=138796 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(18278, 1091, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(18278, 1079, 90146, 0, 0, 1, 0, 0, 26124), -- Tinker's Kit
(23007, 22, 138796, 0, 0, 1, 0, 0, 26124); -- Illusion: Executioner

UPDATE `npc_vendor` SET `slot`=1090, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=1089, `maxcount`=4, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=1088, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4382 AND `ExtendedCost`=0 AND `type`=1); -- Bronze Framework
UPDATE `npc_vendor` SET `slot`=1087, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4404 AND `ExtendedCost`=0 AND `type`=1); -- Silver Contact
UPDATE `npc_vendor` SET `slot`=1086, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=1085, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=1084, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=1083, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=1082, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=1081, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=1080, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=1078, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1077, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1075, `maxcount`=3, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=1074, `maxcount`=3, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=1073, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4361 AND `ExtendedCost`=0 AND `type`=1); -- Bent Copper Tube
UPDATE `npc_vendor` SET `slot`=1072, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=1071, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=1070, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=1069, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=1068, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=1067, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=1066, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=1064, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1063, `VerifiedBuild`=26124 WHERE (`entry`=18278 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=31776 AND `ExtendedCost`=0 AND `type`=1); -- Consortium Tabard
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=33622 AND `ExtendedCost`=0 AND `type`=1); -- Design: Relentless Earthstorm Diamond
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29122 AND `ExtendedCost`=0 AND `type`=1); -- Nether Runner's Cowl
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29121 AND `ExtendedCost`=0 AND `type`=1); -- Guile of Khoraazi
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29119 AND `ExtendedCost`=0 AND `type`=1); -- Haramad's Bargain
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29117 AND `ExtendedCost`=0 AND `type`=1); -- Stormspire Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29116 AND `ExtendedCost`=0 AND `type`=1); -- Nomad's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29115 AND `ExtendedCost`=0 AND `type`=1); -- Consortium Blaster
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=25734 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Fel Leather Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=25733 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Fel Leather Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=24314 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Bag of Jewels
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=23874 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Elemental Seaforium Charge
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=24178 AND `ExtendedCost`=0 AND `type`=1); -- Design: Pendant of the Null Rune
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29456 AND `ExtendedCost`=0 AND `type`=1); -- Gift of the Ethereal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=29457 AND `ExtendedCost`=0 AND `type`=1); -- Nethershard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=22552 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Weapon - Major Striking
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=33305 AND `ExtendedCost`=0 AND `type`=1); -- Design: Don Julio's Heart
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=33156 AND `ExtendedCost`=0 AND `type`=1); -- Design: Crimson Sun
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=25908 AND `ExtendedCost`=0 AND `type`=1); -- Design: Swift Skyfire Diamond
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=23155 AND `ExtendedCost`=0 AND `type`=1); -- Design: Sparkling Azure Moonstone
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=23150 AND `ExtendedCost`=0 AND `type`=1); -- Design: Subtle Golden Draenite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=25732 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Fel Leather Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=23134 AND `ExtendedCost`=0 AND `type`=1); -- Design: Delicate Blood Garnet
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=23136 AND `ExtendedCost`=0 AND `type`=1); -- Design: Reckless Flame Spessarite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=23146 AND `ExtendedCost`=0 AND `type`=1); -- Design: Shifting Shadow Draenite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23007 AND `item`=28274 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Cloak - PvP Power

DELETE FROM `npc_vendor` WHERE (`entry`=21113 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=21113 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=21113 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19497 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19497 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19497 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19497 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19498 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19498 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19498 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19498 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19498 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19498 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(21113, 8, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(21113, 7, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(21113, 6, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19497, 6, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19497, 5, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19497, 4, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19497, 2, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(19498, 6, 4470, 0, 0, 1, 0, 0, 26124), -- Simple Wood
(19498, 5, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(19498, 4, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(19498, 3, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(19498, 2, 28399, 0, 0, 1, 0, 0, 26124), -- Filtered Draenic Water
(19498, 1, 159, 0, 0, 1, 0, 0, 26124); -- Refreshing Spring Water

UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21113 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21113 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21113 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21113 AND `item`=31675 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mok'Nathal Shortribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21113 AND `item`=31674 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Crunchy Serpent
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21111 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21111 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21111 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21111 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21111 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21111 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21110 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=507, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=506, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=23768 AND `ExtendedCost`=0 AND `type`=1); -- White Smoke Flare
UPDATE `npc_vendor` SET `slot`=505, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=23783 AND `ExtendedCost`=0 AND `type`=1); -- Handful of Fel Iron Bolts
UPDATE `npc_vendor` SET `slot`=504, `maxcount`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=23736 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Bomb
UPDATE `npc_vendor` SET `slot`=503, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=502, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=501, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=500, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19495 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19495 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19495 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19495 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19495 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19495 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22469 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19497 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19497 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=463, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30751 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Axe
UPDATE `npc_vendor` SET `slot`=462, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30752 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Battleaxe
UPDATE `npc_vendor` SET `slot`=461, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30750 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Warblade
UPDATE `npc_vendor` SET `slot`=460, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30749 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Sparring Blade
UPDATE `npc_vendor` SET `slot`=459, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30754 AND `ExtendedCost`=0 AND `type`=1); -- Ancient Bone Mace
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30759 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Recurve
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30757 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Light Crossbow
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19499 AND `item`=30758 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Guardian Rifle

DELETE FROM `npc_vendor` WHERE (`entry`=22271 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=22271 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=22271 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23112 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20249 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20249 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20249 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20249 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20249 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20250 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20250 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20250 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20250 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20915 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20915 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(22271, 6, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(22271, 5, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(22271, 4, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(23112, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(20249, 5, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(20249, 4, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(20249, 3, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(20249, 2, 28399, 0, 0, 1, 0, 0, 26124), -- Filtered Draenic Water
(20249, 1, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(20250, 6, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(20250, 5, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(20250, 4, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20250, 2, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(20915, 2, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(20915, 1, 64670, 0, 0, 1, 0, 0, 26124); -- Vanishing Powder

UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22271 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22271 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22271 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22271 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22271 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22271 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22264 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22264 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22264 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22264 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22264 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22264 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23110 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23110 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23110 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23110 AND `item`=32667 AND `ExtendedCost`=0 AND `type`=1); -- Bash Ale
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23110 AND `item`=32668 AND `ExtendedCost`=0 AND `type`=1); -- Dos Ogris
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=29453 AND `ExtendedCost`=0 AND `type`=1); -- Sporeggar Mushroom
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=27859 AND `ExtendedCost`=0 AND `type`=1); -- Zangar Caps
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=8948 AND `ExtendedCost`=0 AND `type`=1); -- Dried King Bolete
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=29452 AND `ExtendedCost`=0 AND `type`=1); -- Zangar Trout
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=27858 AND `ExtendedCost`=0 AND `type`=1); -- Sunspring Carp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=32685 AND `ExtendedCost`=0 AND `type`=1); -- Ogri'la Chicken Fingers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22266 AND `item`=32686 AND `ExtendedCost`=0 AND `type`=1); -- Mingo's Fortune Giblets
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22270 AND `item`=32758 AND `ExtendedCost`=0 AND `type`=1); -- Brute Cologne
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22270 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22270 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22270 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22270 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22270 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=22270 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=33935 AND `ExtendedCost`=2272 AND `type`=1); -- Crystal Mana Potion
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=33934 AND `ExtendedCost`=2272 AND `type`=1); -- Crystal Healing Potion
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32828 AND `ExtendedCost`=1958 AND `type`=1); -- Ogri'la Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32648 AND `ExtendedCost`=1950 AND `type`=1); -- Vortex Walking Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32647 AND `ExtendedCost`=1950 AND `type`=1); -- Shard-Bound Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32651 AND `ExtendedCost`=1950 AND `type`=1); -- Crystal Orb of Enlightenment
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32645 AND `ExtendedCost`=1950 AND `type`=1); -- Crystalline Crossbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32650 AND `ExtendedCost`=1952 AND `type`=1); -- Cerulean Crystal Rod
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32652 AND `ExtendedCost`=1952 AND `type`=1); -- Ogri'la Aegis
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32654 AND `ExtendedCost`=1952 AND `type`=1); -- Crystalforged Trinket
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32653 AND `ExtendedCost`=1952 AND `type`=1); -- Apexis Cloak
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32784 AND `ExtendedCost`=1949 AND `type`=1); -- Red Ogre Brew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23428 AND `item`=32783 AND `ExtendedCost`=1948 AND `type`=1); -- Blue Ogre Brew
UPDATE `npc_vendor` SET `slot`=184, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=23208 AND `item`=23769 AND `ExtendedCost`=0 AND `type`=1); -- Red Smoke Flare
UPDATE `npc_vendor` SET `slot`=183, `VerifiedBuild`=26124 WHERE (`entry`=23208 AND `item`=23768 AND `ExtendedCost`=0 AND `type`=1); -- White Smoke Flare
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23208 AND `item`=9314 AND `ExtendedCost`=0 AND `type`=1); -- Red Streaks Firework
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23208 AND `item`=5740 AND `ExtendedCost`=0 AND `type`=1); -- Red Fireworks Rocket
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23392 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=20249 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=724 WHERE (`entry`=21112 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=723, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=21112 AND `item`=23781 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Blasting Powder
UPDATE `npc_vendor` SET `slot`=722 WHERE (`entry`=21112 AND `item`=23783 AND `ExtendedCost`=0 AND `type`=1); -- Handful of Fel Iron Bolts
UPDATE `npc_vendor` SET `slot`=721, `maxcount`=2 WHERE (`entry`=21112 AND `item`=23736 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Bomb
UPDATE `npc_vendor` SET `slot`=720 WHERE (`entry`=21112 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=719 WHERE (`entry`=21112 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=718 WHERE (`entry`=21112 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=717 WHERE (`entry`=21112 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=703, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30753 AND `ExtendedCost`=0 AND `type`=1); -- Warphorn Spear
UPDATE `npc_vendor` SET `slot`=702, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30751 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Axe
UPDATE `npc_vendor` SET `slot`=701, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30752 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Battleaxe
UPDATE `npc_vendor` SET `slot`=700, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30750 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Warblade
UPDATE `npc_vendor` SET `slot`=699, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30749 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Sparring Blade
UPDATE `npc_vendor` SET `slot`=698, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30754 AND `ExtendedCost`=0 AND `type`=1); -- Ancient Bone Mace
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=20249 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=697, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30751 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Axe
UPDATE `npc_vendor` SET `slot`=696, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30752 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Battleaxe
UPDATE `npc_vendor` SET `slot`=695, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30750 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Warblade
UPDATE `npc_vendor` SET `slot`=694, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30749 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Sparring Blade
UPDATE `npc_vendor` SET `slot`=693, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20917 AND `item`=30754 AND `ExtendedCost`=0 AND `type`=1); -- Ancient Bone Mace
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20250 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=20250 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=696, `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=31674 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Crunchy Serpent
UPDATE `npc_vendor` SET `slot`=695, `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=31675 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mok'Nathal Shortribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20916 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=716 WHERE (`entry`=21112 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=715 WHERE (`entry`=21112 AND `item`=23783 AND `ExtendedCost`=0 AND `type`=1); -- Handful of Fel Iron Bolts
UPDATE `npc_vendor` SET `slot`=714, `maxcount`=1 WHERE (`entry`=21112 AND `item`=23736 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Bomb
UPDATE `npc_vendor` SET `slot`=713 WHERE (`entry`=21112 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=712 WHERE (`entry`=21112 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=711 WHERE (`entry`=21112 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=710 WHERE (`entry`=21112 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer

UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=81923 AND `ExtendedCost`=0 AND `type`=1); -- Cobo Cola
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=81924 AND `ExtendedCost`=0 AND `type`=1); -- Carbonated Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=58257 AND `ExtendedCost`=0 AND `type`=1); -- Highland Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=58256 AND `ExtendedCost`=0 AND `type`=1); -- Sparkling Oasis Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=33445 AND `ExtendedCost`=0 AND `type`=1); -- Honeymint Tea
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=33444 AND `ExtendedCost`=0 AND `type`=1); -- Pungent Seal Whey
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=58274 AND `ExtendedCost`=0 AND `type`=1); -- Fresh Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=81920 AND `ExtendedCost`=0 AND `type`=1); -- Plump Fig
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=81919 AND `ExtendedCost`=0 AND `type`=1); -- Red Raspberry
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=58265 AND `ExtendedCost`=0 AND `type`=1); -- Highland Pomegranate
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=58264 AND `ExtendedCost`=0 AND `type`=1); -- Sour Green Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=35948 AND `ExtendedCost`=0 AND `type`=1); -- Savory Snowplum
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=35949 AND `ExtendedCost`=0 AND `type`=1); -- Tundra Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=82451 AND `ExtendedCost`=0 AND `type`=1); -- Frybread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=82450 AND `ExtendedCost`=0 AND `type`=1); -- Cornmeal Biscuit
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=58261 AND `ExtendedCost`=0 AND `type`=1); -- Buttery Wheat Roll
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=58260 AND `ExtendedCost`=0 AND `type`=1); -- Pine Nut Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=35950 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Potato Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Crusty Flatbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6740 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `PlayerConditionID`=0, `VerifiedBuild`=26124 WHERE (`entry`=49877 AND `item`=64901 AND `ExtendedCost`=0 AND `type`=1); -- Mantle of Stormwind
UPDATE `npc_vendor` SET `PlayerConditionID`=0, `VerifiedBuild`=26124 WHERE (`entry`=49877 AND `item`=64902 AND `ExtendedCost`=0 AND `type`=1); -- Cape of Stormwind
UPDATE `npc_vendor` SET `PlayerConditionID`=0, `VerifiedBuild`=26124 WHERE (`entry`=49877 AND `item`=64903 AND `ExtendedCost`=0 AND `type`=1); -- Shroud of Stormwind
UPDATE `npc_vendor` SET `PlayerConditionID`=0, `VerifiedBuild`=26124 WHERE (`entry`=49877 AND `item`=67531 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=49877 AND `item`=45574 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Tabard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=52735 AND `ExtendedCost`=3017 AND `type`=1); -- Formula: Enchant Weapon - Windwalk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=52733 AND `ExtendedCost`=3017 AND `type`=1); -- Formula: Enchant Weapon - Power Torrent
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=52736 AND `ExtendedCost`=3017 AND `type`=1); -- Formula: Enchant Weapon - Landslide
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=64415 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Gloves - Mighty Strength
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=64414 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Gloves - Greater Mastery
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=52737 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Cloak - Greater Critical Strike
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=52739 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Chest - Peerless Stats
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=52740 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Chest - Greater Stamina
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=64413 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Bracer - Greater Speed
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=52738 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Bracer - Greater Critical Strike
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=64412 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Boots - Lavawalker
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=64411 AND `ExtendedCost`=3016 AND `type`=1); -- Formula: Enchant Boots - Assassin's Step
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=67312 AND `ExtendedCost`=3326 AND `type`=1); -- Formula: Magic Lamp
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=1318 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum

DELETE FROM `npc_vendor` WHERE (`entry`=19617 AND `item`=82344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19617 AND `item`=83094 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19617 AND `item`=82343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19617 AND `item`=83095 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19575 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19575 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=58152 AND `item`=120987 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=58152 AND `item`=120988 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=58152 AND `item`=120986 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=58152 AND `item`=120985 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=58152 AND `item`=120984 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54648 AND `item`=120980 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54648 AND `item`=120976 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54648 AND `item`=120990 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=54648 AND `item`=120991 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40209 AND `item`=120992 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40209 AND `item`=120993 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40209 AND `item`=120994 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40209 AND `item`=120995 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40209 AND `item`=120996 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23396 AND `item`=120977 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23396 AND `item`=120981 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23396 AND `item`=120982 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23396 AND `item`=120983 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=107619 AND `item`=35094 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=34986 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35073 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35074 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35008 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35016 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35015 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=34989 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=34997 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35101 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=34988 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35037 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35017 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=34995 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=36737 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35109 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=34987 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35107 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=34985 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35065 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35082 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35014 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35102 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35064 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35110 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35103 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35075 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35018 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35047 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35071 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35072 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35038 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35076 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35058 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35095 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=35093 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=34996 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107619 AND `item`=44429 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=44431 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=41591 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=41592 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=35146 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35168 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=35138 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35153 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=35174 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=35144 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35159 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=35179 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=35149 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35164 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107619 AND `item`=35096 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35100 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107619 AND `item`=35098 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107619 AND `item`=35097 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107619 AND `item`=35099 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107619 AND `item`=146648 AND `ExtendedCost`=5981 AND `type`=1) OR (`entry`=107619 AND `item`=146607 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=107610 AND `item`=33755 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33661 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33735 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33736 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33681 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=34033 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33688 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33663 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33670 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33762 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33662 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34016 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33689 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34015 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33766 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34540 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33764 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34059 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34066 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33743 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33687 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33763 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33727 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34014 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33716 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34530 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33006 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=34529 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33734 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33733 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33705 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33737 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33801 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33756 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33754 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33669 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107610 AND `item`=33913 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107610 AND `item`=33914 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33912 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107610 AND `item`=33901 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107610 AND `item`=33902 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33900 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107610 AND `item`=33883 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107610 AND `item`=33884 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33882 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107610 AND `item`=33757 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33761 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107610 AND `item`=33759 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107610 AND `item`=33758 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107610 AND `item`=33760 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107610 AND `item`=146649 AND `ExtendedCost`=5981 AND `type`=1) OR (`entry`=107610 AND `item`=146637 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=107599 AND `item`=32045 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=33313 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32961 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=31978 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=31984 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=31959 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=31966 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32052 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=31958 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=31985 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32962 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32964 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32963 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32053 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32014 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32055 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32025 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=31986 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32027 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32026 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32003 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32028 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32046 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32044 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=31965 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=107599 AND `item`=32997 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32999 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32998 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32989 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32990 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32988 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32821 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32796 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32808 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32980 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32981 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32979 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=147609 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32820 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32795 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32807 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32819 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32794 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32806 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32818 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32793 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32805 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32817 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32792 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32804 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32816 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32791 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32803 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=147612 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=147611 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=147610 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32814 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32790 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32802 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32813 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32789 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32801 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32812 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32788 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32800 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32811 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32787 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32799 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32810 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32786 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32798 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32809 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32785 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32797 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=107599 AND `item`=32047 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32051 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107599 AND `item`=32049 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=107599 AND `item`=32048 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107599 AND `item`=32050 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=107599 AND `item`=146650 AND `ExtendedCost`=5981 AND `type`=1) OR (`entry`=107599 AND `item`=146627 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=54650 AND `item`=28358 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=32452 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28346 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=24550 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28299 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28298 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28295 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28302 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28309 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28320 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=32451 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=32450 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28297 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28476 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=24557 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28300 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28294 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28307 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28305 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28314 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28313 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28310 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28312 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28308 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=54650 AND `item`=28381 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=30491 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28383 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28385 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28996 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28997 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28995 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28646 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28645 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28644 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28999 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=29000 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28998 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32983 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32984 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=32982 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32986 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32987 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=32985 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28643 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28642 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28641 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28984 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28985 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28983 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28424 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28422 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28423 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28988 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28987 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28986 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=31598 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=31595 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=31594 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=31599 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=31597 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=31596 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28448 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28447 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28446 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=29006 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=29005 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=29004 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28445 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28444 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28443 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28978 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28977 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28976 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28405 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28402 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28404 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28981 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28982 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28980 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32973 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32975 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=32974 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32977 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32978 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=32976 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28411 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28410 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28409 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=29002 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=29003 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=29001 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28451 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28449 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28450 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28973 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28975 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28974 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28605 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28630 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28629 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28989 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28991 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28990 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32991 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32993 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=32992 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32994 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=32996 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=32995 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=147771 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=147613 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=147614 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=147772 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=147615 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=147616 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28638 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28640 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28639 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28992 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=28994 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=28993 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=54650 AND `item`=25854 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=25858 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=54650 AND `item`=25857 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=54650 AND `item`=25855 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=54650 AND `item`=25856 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=54650 AND `item`=146617 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=24974 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19573 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19573 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19573 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19573 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(19617, 10, 82344, 0, 0, 1, 0, 0, 26124), -- Hearthglen Ambrosia
(19617, 9, 83094, 0, 0, 1, 0, 0, 26124), -- Foote Tripel
(19617, 8, 82343, 0, 0, 1, 0, 0, 26124), -- Lordaeron Lambic
(19617, 7, 83095, 0, 0, 1, 0, 0, 26124), -- Lagrave Stout
(19575, 1169, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19575, 1165, 90146, 0, 0, 1, 0, 0, 26124), -- Tinker's Kit
(58152, 58, 120987, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Silk Cinch
(58152, 55, 120988, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Satin Waistwrap
(58152, 52, 120986, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Dreadweave Wrap
(58152, 13, 120985, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Leather Clasp
(58152, 10, 120984, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Dragonhide Belt
(54648, 45, 120980, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Lamellar Girdle
(54648, 42, 120976, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Plate Waistguard
(54648, 10, 120990, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Mail Links
(54648, 8, 120991, 0, 0, 1, 13633, 0, 26124), -- Replica Blood Guard's Chain Belt
(40209, 71, 120992, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Dragonhide Belt
(40209, 66, 120993, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Leather Clasp
(40209, 16, 120994, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Silk Cinch
(40209, 11, 120995, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Satin Belt
(40209, 6, 120996, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Dreadweave Wrap
(23396, 45, 120977, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Plate Waistguard
(23396, 42, 120981, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Lamellar Girdle
(23396, 8, 120982, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Mail Links
(23396, 5, 120983, 0, 0, 1, 13632, 0, 26124), -- Replica Knight-Lieutenant's Chain Belt
(107619, 187, 35094, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Shield Wall
(107619, 186, 34986, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Barrier
(107619, 185, 35073, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Redoubt
(107619, 184, 35074, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Reprieve
(107619, 183, 35008, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Endgame
(107619, 182, 35016, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Grimoire
(107619, 181, 35015, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Greatsword
(107619, 180, 34989, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Bonegrinder
(107619, 179, 34997, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Decapitator
(107619, 178, 35101, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Slicer
(107619, 177, 34988, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Bonecracker
(107619, 176, 35037, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Slasher
(107619, 175, 35017, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Hacker
(107619, 174, 34995, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Chopper
(107619, 173, 36737, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Hatchet
(107619, 172, 35109, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's War Staff
(107619, 171, 34987, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Battle Staff
(107619, 170, 35107, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Touch of Defeat
(107619, 169, 34985, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Baton of Light
(107619, 168, 35065, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Piercing Touch
(107619, 167, 35082, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Salvation
(107619, 166, 35014, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Gavel
(107619, 165, 35102, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Spellblade
(107619, 164, 35064, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Painsaw
(107619, 163, 35110, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Waraxe
(107619, 162, 35103, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Staff
(107619, 161, 35075, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Rifle
(107619, 160, 35018, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Heavy Crossbow
(107619, 159, 35047, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Longbow
(107619, 158, 35071, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Pummeler
(107619, 157, 35072, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Quickblade
(107619, 156, 35038, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Fleshslicer
(107619, 155, 35076, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Ripper
(107619, 154, 35058, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Mutilator
(107619, 153, 35095, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Shiv
(107619, 152, 35093, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Shanker
(107619, 151, 34996, 0, 5966, 1, 0, 0, 26124), -- Brutal Gladiator's Cleaver
(107619, 150, 44429, 0, 5962, 1, 0, 0, 26124), -- Volanthius Shroud
(107619, 149, 44431, 0, 5962, 1, 0, 0, 26124), -- Cloak of Certain Reprieve
(107619, 148, 41591, 0, 5962, 1, 0, 0, 26124), -- Sergeant's Reinforced Cape
(107619, 147, 41592, 0, 5962, 1, 0, 0, 26124), -- The Gladiator's Resolution
(107619, 145, 35146, 0, 5963, 1, 0, 0, 26124), -- Guardian's Plate Greaves
(107619, 122, 35168, 0, 5962, 1, 0, 0, 26124), -- Guardian's Dreadweave Cuffs
(107619, 121, 35138, 0, 5963, 1, 0, 0, 26124), -- Guardian's Dreadweave Stalkers
(107619, 120, 35153, 0, 5962, 1, 0, 0, 26124), -- Guardian's Dreadweave Belt
(107619, 119, 35174, 0, 5962, 1, 0, 0, 26124), -- Guardian's Mooncloth Cuffs
(107619, 118, 35144, 0, 5963, 1, 0, 0, 26124), -- Guardian's Mooncloth Slippers
(107619, 117, 35159, 0, 5962, 1, 0, 0, 26124), -- Guardian's Mooncloth Belt
(107619, 116, 35179, 0, 5962, 1, 0, 0, 26124), -- Guardian's Silk Cuffs
(107619, 115, 35149, 0, 5963, 1, 0, 0, 26124), -- Guardian's Silk Footguards
(107619, 114, 35164, 0, 5962, 1, 0, 0, 26124), -- Guardian's Silk Belt
(107619, 36, 35096, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Silk Amice
(107619, 35, 35100, 0, 5964, 1, 0, 0, 26124), -- Brutal Gladiator's Silk Trousers
(107619, 34, 35098, 0, 5963, 1, 0, 0, 26124), -- Brutal Gladiator's Silk Handguards
(107619, 33, 35097, 0, 5964, 1, 0, 0, 26124), -- Brutal Gladiator's Silk Cowl
(107619, 32, 35099, 0, 5964, 1, 0, 0, 26124), -- Brutal Gladiator's Silk Raiment
(107619, 11, 146648, 0, 5981, 1, 0, 0, 26124), -- Arsenal: Brutal Gladiator's Weapons
(107619, 10, 146607, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Brutal Gladiator's Silk Armor
(107610, 177, 33755, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Shield Wall
(107610, 176, 33661, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Barrier
(107610, 175, 33735, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Redoubt
(107610, 174, 33736, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Reprieve
(107610, 173, 33681, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Endgame
(107610, 172, 34033, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Grimoire
(107610, 171, 33688, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Greatsword
(107610, 170, 33663, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Bonegrinder
(107610, 169, 33670, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Decapitator
(107610, 168, 33762, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Slicer
(107610, 167, 33662, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Bonecracker
(107610, 166, 34016, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Slasher
(107610, 165, 33689, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Hacker
(107610, 164, 34015, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Chopper
(107610, 163, 33766, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's War Staff
(107610, 162, 34540, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Battle Staff
(107610, 161, 33764, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Touch of Defeat
(107610, 160, 34059, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Baton of Light
(107610, 159, 34066, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Piercing Touch
(107610, 158, 33743, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Salvation
(107610, 157, 33687, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Gavel
(107610, 156, 33763, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Spellblade
(107610, 155, 33727, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Painsaw
(107610, 154, 34014, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Waraxe
(107610, 153, 33716, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Staff
(107610, 152, 34530, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Rifle
(107610, 151, 33006, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Heavy Crossbow
(107610, 150, 34529, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Longbow
(107610, 149, 33734, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Quickblade
(107610, 148, 33733, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Pummeler
(107610, 147, 33705, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Fleshslicer
(107610, 146, 33737, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Ripper
(107610, 145, 33801, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Mutilator
(107610, 144, 33756, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Shiv
(107610, 143, 33754, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Shanker
(107610, 142, 33669, 0, 5966, 1, 0, 0, 26124), -- Vengeful Gladiator's Cleaver
(107610, 137, 33913, 0, 5962, 1, 0, 0, 26124), -- Vindicator's Silk Cuffs
(107610, 136, 33914, 0, 5963, 1, 0, 0, 26124), -- Vindicator's Silk Footguards
(107610, 135, 33912, 0, 5962, 1, 0, 0, 26124), -- Vindicator's Silk Belt
(107610, 122, 33901, 0, 5962, 1, 0, 0, 26124), -- Vindicator's Mooncloth Cuffs
(107610, 121, 33902, 0, 5963, 1, 0, 0, 26124), -- Vindicator's Mooncloth Slippers
(107610, 120, 33900, 0, 5962, 1, 0, 0, 26124), -- Vindicator's Mooncloth Belt
(107610, 104, 33883, 0, 5962, 1, 0, 0, 26124), -- Vindicator's Dreadweave Cuffs
(107610, 103, 33884, 0, 5963, 1, 0, 0, 26124), -- Vindicator's Dreadweave Stalkers
(107610, 102, 33882, 0, 5962, 1, 0, 0, 26124), -- Vindicator's Dreadweave Belt
(107610, 90, 33757, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Silk Amice
(107610, 89, 33761, 0, 5964, 1, 0, 0, 26124), -- Vengeful Gladiator's Silk Trousers
(107610, 88, 33759, 0, 5963, 1, 0, 0, 26124), -- Vengeful Gladiator's Silk Handguards
(107610, 87, 33758, 0, 5964, 1, 0, 0, 26124), -- Vengeful Gladiator's Silk Cowl
(107610, 86, 33760, 0, 5964, 1, 0, 0, 26124), -- Vengeful Gladiator's Silk Raiment
(107610, 10, 146649, 0, 5981, 1, 0, 0, 26124), -- Arsenal: Vengeful Gladiator's Weapons
(107610, 9, 146637, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Vengeful Gladiator's Silk Armor
(107599, 169, 32045, 0, 5963, 1, 0, 0, 26124), -- Merciless Gladiator's Shield Wall
(107599, 168, 33313, 0, 5963, 1, 0, 0, 26124), -- Merciless Gladiator's Barrier
(107599, 167, 32961, 0, 5963, 1, 0, 0, 26124), -- Merciless Gladiator's Reprieve
(107599, 166, 31978, 0, 5963, 1, 0, 0, 26124), -- Merciless Gladiator's Endgame
(107599, 165, 31984, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Greatsword
(107599, 164, 31959, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Bonegrinder
(107599, 163, 31966, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Decapitator
(107599, 162, 32052, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Slicer
(107599, 161, 31958, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Bonecracker
(107599, 160, 31985, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Hacker
(107599, 159, 32962, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Touch of Defeat
(107599, 158, 32964, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Salvation
(107599, 157, 32963, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Gavel
(107599, 156, 32053, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Spellblade
(107599, 155, 32014, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Maul
(107599, 154, 32055, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's War Staff
(107599, 153, 32025, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Painsaw
(107599, 152, 31986, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Crossbow of the Phoenix
(107599, 151, 32027, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Quickblade
(107599, 150, 32026, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Pummeler
(107599, 149, 32003, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Fleshslicer
(107599, 148, 32028, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Ripper
(107599, 147, 32046, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Shiv
(107599, 146, 32044, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Shanker
(107599, 145, 31965, 0, 5966, 1, 0, 0, 26124), -- Merciless Gladiator's Cleaver
(107599, 144, 32997, 0, 5962, 1, 0, 0, 26124), -- Veteran's Ringmail Bracers
(107599, 143, 32999, 0, 5963, 1, 0, 0, 26124), -- Veteran's Ringmail Sabatons
(107599, 142, 32998, 0, 5962, 1, 0, 0, 26124), -- Veteran's Ringmail Girdle
(107599, 141, 32989, 0, 5962, 1, 0, 0, 26124), -- Veteran's Ornamented Bracers
(107599, 140, 32990, 0, 5963, 1, 0, 0, 26124), -- Veteran's Ornamented Greaves
(107599, 139, 32988, 0, 5962, 1, 0, 0, 26124), -- Veteran's Ornamented Belt
(107599, 138, 32821, 0, 5962, 1, 0, 0, 26124), -- Veteran's Wyrmhide Bracers
(107599, 137, 32796, 0, 5963, 1, 0, 0, 26124), -- Veteran's Wyrmhide Boots
(107599, 136, 32808, 0, 5962, 1, 0, 0, 26124), -- Veteran's Wyrmhide Belt
(107599, 135, 32980, 0, 5962, 1, 0, 0, 26124), -- Veteran's Mooncloth Cuffs
(107599, 134, 32981, 0, 5963, 1, 0, 0, 26124), -- Veteran's Mooncloth Slippers
(107599, 133, 32979, 0, 5962, 1, 0, 0, 26124), -- Veteran's Mooncloth Belt
(107599, 132, 147609, 0, 5963, 1, 0, 0, 26124), -- Veteran's Satin Slippers
(107599, 131, 32820, 0, 5962, 1, 0, 0, 26124), -- Veteran's Silk Cuffs
(107599, 130, 32795, 0, 5963, 1, 0, 0, 26124), -- Veteran's Silk Footguards
(107599, 129, 32807, 0, 5962, 1, 0, 0, 26124), -- Veteran's Silk Belt
(107599, 128, 32819, 0, 5962, 1, 0, 0, 26124), -- Veteran's Scaled Bracers
(107599, 127, 32794, 0, 5963, 1, 0, 0, 26124), -- Veteran's Scaled Greaves
(107599, 126, 32806, 0, 5962, 1, 0, 0, 26124), -- Veteran's Scaled Belt
(107599, 125, 32818, 0, 5962, 1, 0, 0, 26124), -- Veteran's Plate Bracers
(107599, 124, 32793, 0, 5963, 1, 0, 0, 26124), -- Veteran's Plate Greaves
(107599, 123, 32805, 0, 5962, 1, 0, 0, 26124), -- Veteran's Plate Belt
(107599, 122, 32817, 0, 5962, 1, 0, 0, 26124), -- Veteran's Mail Bracers
(107599, 121, 32792, 0, 5963, 1, 0, 0, 26124), -- Veteran's Mail Sabatons
(107599, 120, 32804, 0, 5962, 1, 0, 0, 26124), -- Veteran's Mail Girdle
(107599, 119, 32816, 0, 5962, 1, 0, 0, 26124), -- Veteran's Linked Bracers
(107599, 118, 32791, 0, 5963, 1, 0, 0, 26124), -- Veteran's Linked Sabatons
(107599, 117, 32803, 0, 5962, 1, 0, 0, 26124), -- Veteran's Linked Girdle
(107599, 116, 147612, 0, 5962, 1, 0, 0, 26124), -- Veteran's Leather Wristguards
(107599, 115, 147611, 0, 5963, 1, 0, 0, 26124), -- Veteran's Leather Footguards
(107599, 114, 147610, 0, 5962, 1, 0, 0, 26124), -- Veteran's Leather Waistband
(107599, 113, 32814, 0, 5962, 1, 0, 0, 26124), -- Veteran's Leather Bracers
(107599, 112, 32790, 0, 5963, 1, 0, 0, 26124), -- Veteran's Leather Boots
(107599, 111, 32802, 0, 5962, 1, 0, 0, 26124), -- Veteran's Leather Belt
(107599, 110, 32813, 0, 5962, 1, 0, 0, 26124), -- Veteran's Lamellar Bracers
(107599, 109, 32789, 0, 5963, 1, 0, 0, 26124), -- Veteran's Lamellar Greaves
(107599, 108, 32801, 0, 5962, 1, 0, 0, 26124), -- Veteran's Lamellar Belt
(107599, 107, 32812, 0, 5962, 1, 0, 0, 26124), -- Veteran's Kodohide Bracers
(107599, 106, 32788, 0, 5963, 1, 0, 0, 26124), -- Veteran's Kodohide Boots
(107599, 105, 32800, 0, 5962, 1, 0, 0, 26124), -- Veteran's Kodohide Belt
(107599, 104, 32811, 0, 5962, 1, 0, 0, 26124), -- Veteran's Dreadweave Cuffs
(107599, 103, 32787, 0, 5963, 1, 0, 0, 26124), -- Veteran's Dreadweave Stalkers
(107599, 102, 32799, 0, 5962, 1, 0, 0, 26124), -- Veteran's Dreadweave Belt
(107599, 101, 32810, 0, 5962, 1, 0, 0, 26124), -- Veteran's Dragonhide Bracers
(107599, 100, 32786, 0, 5963, 1, 0, 0, 26124), -- Veteran's Dragonhide Boots
(107599, 99, 32798, 0, 5962, 1, 0, 0, 26124), -- Veteran's Dragonhide Belt
(107599, 98, 32809, 0, 5962, 1, 0, 0, 26124), -- Veteran's Chain Bracers
(107599, 97, 32785, 0, 5963, 1, 0, 0, 26124), -- Veteran's Chain Sabatons
(107599, 96, 32797, 0, 5962, 1, 0, 0, 26124), -- Veteran's Chain Girdle
(107599, 90, 32047, 0, 5963, 1, 0, 0, 26124), -- Merciless Gladiator's Silk Amice
(107599, 89, 32051, 0, 5964, 1, 0, 0, 26124), -- Merciless Gladiator's Silk Trousers
(107599, 88, 32049, 0, 5963, 1, 0, 0, 26124), -- Merciless Gladiator's Silk Handguards
(107599, 87, 32048, 0, 5964, 1, 0, 0, 26124), -- Merciless Gladiator's Silk Cowl
(107599, 86, 32050, 0, 5964, 1, 0, 0, 26124), -- Merciless Gladiator's Silk Raiment
(107599, 10, 146650, 0, 5981, 1, 0, 0, 26124), -- Arsenal: Merciless Gladiator's Weapons
(107599, 9, 146627, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Merciless Gladiator's Silk Armor
(54650, 215, 28358, 0, 5963, 1, 0, 0, 26124), -- Gladiator's Shield Wall
(54650, 214, 32452, 0, 5963, 1, 0, 0, 26124), -- Gladiator's Reprieve
(54650, 213, 28346, 0, 5963, 1, 0, 0, 26124), -- Gladiator's Endgame
(54650, 212, 24550, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Greatsword
(54650, 211, 28299, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Bonegrinder
(54650, 210, 28298, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Decapitator
(54650, 209, 28295, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Slicer
(54650, 208, 28302, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Bonecracker
(54650, 207, 28309, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Hacker
(54650, 206, 28320, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Touch of Defeat
(54650, 205, 32451, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Salvation
(54650, 204, 32450, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Gavel
(54650, 203, 28297, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Spellblade
(54650, 202, 28476, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Maul
(54650, 201, 24557, 0, 5966, 1, 0, 0, 26124), -- Gladiator's War Staff
(54650, 200, 28300, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Painsaw
(54650, 199, 28294, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Heavy Crossbow
(54650, 198, 28307, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Quickblade
(54650, 197, 28305, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Pummeler
(54650, 196, 28314, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Fleshslicer
(54650, 195, 28313, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Ripper
(54650, 194, 28310, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Shiv
(54650, 193, 28312, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Shanker
(54650, 192, 28308, 0, 5966, 1, 0, 0, 26124), -- Gladiator's Cleaver
(54650, 191, 28381, 0, 5962, 1, 0, 0, 26124), -- General's Plate Bracers
(54650, 190, 30491, 0, 5963, 1, 0, 0, 26124), -- General's Plate Greaves Tier 2
(54650, 189, 28383, 0, 5963, 1, 0, 0, 26124), -- General's Plate Greaves
(54650, 188, 28385, 0, 5962, 1, 0, 0, 26124), -- General's Plate Belt
(54650, 187, 28996, 0, 5962, 1, 0, 0, 26124), -- Marshal's Plate Bracers
(54650, 186, 28997, 0, 5963, 1, 0, 0, 26124), -- Marshal's Plate Greaves
(54650, 185, 28995, 0, 5962, 1, 0, 0, 26124), -- Marshal's Plate Belt
(54650, 184, 28646, 0, 5962, 1, 0, 0, 26124), -- General's Scaled Bracers
(54650, 183, 28645, 0, 5963, 1, 0, 0, 26124), -- General's Scaled Greaves
(54650, 182, 28644, 0, 5962, 1, 0, 0, 26124), -- General's Scaled Belt
(54650, 181, 28999, 0, 5962, 1, 0, 0, 26124); -- Marshal's Scaled Bracers

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(54650, 180, 29000, 0, 5963, 1, 0, 0, 26124), -- Marshal's Scaled Greaves
(54650, 179, 28998, 0, 5962, 1, 0, 0, 26124), -- Marshal's Scaled Belt
(54650, 178, 32983, 0, 5962, 1, 0, 0, 26124), -- General's Ornamented Bracers
(54650, 177, 32984, 0, 5963, 1, 0, 0, 26124), -- General's Ornamented Greaves
(54650, 176, 32982, 0, 5962, 1, 0, 0, 26124), -- General's Ornamented Belt
(54650, 175, 32986, 0, 5962, 1, 0, 0, 26124), -- Marshal's Ornamented Bracers
(54650, 174, 32987, 0, 5963, 1, 0, 0, 26124), -- Marshal's Ornamented Greaves
(54650, 173, 32985, 0, 5962, 1, 0, 0, 26124), -- Marshal's Ornamented Belt
(54650, 172, 28643, 0, 5962, 1, 0, 0, 26124), -- General's Lamellar Bracers
(54650, 171, 28642, 0, 5963, 1, 0, 0, 26124), -- General's Lamellar Greaves
(54650, 170, 28641, 0, 5962, 1, 0, 0, 26124), -- General's Lamellar Belt
(54650, 169, 28984, 0, 5962, 1, 0, 0, 26124), -- Marshal's Lamellar Bracers
(54650, 168, 28985, 0, 5963, 1, 0, 0, 26124), -- Marshal's Lamellar Greaves
(54650, 167, 28983, 0, 5962, 1, 0, 0, 26124), -- Marshal's Lamellar Belt
(54650, 166, 28424, 0, 5962, 1, 0, 0, 26124), -- General's Leather Bracers
(54650, 165, 28422, 0, 5963, 1, 0, 0, 26124), -- General's Leather Boots
(54650, 164, 28423, 0, 5962, 1, 0, 0, 26124), -- General's Leather Belt
(54650, 163, 28988, 0, 5962, 1, 0, 0, 26124), -- Marshal's Leather Bracers
(54650, 162, 28987, 0, 5963, 1, 0, 0, 26124), -- Marshal's Leather Boots
(54650, 161, 28986, 0, 5962, 1, 0, 0, 26124), -- Marshal's Leather Belt
(54650, 160, 31598, 0, 5962, 1, 0, 0, 26124), -- General's Kodohide Bracers
(54650, 159, 31595, 0, 5963, 1, 0, 0, 26124), -- General's Kodohide Boots
(54650, 158, 31594, 0, 5962, 1, 0, 0, 26124), -- General's Kodohide Belt
(54650, 157, 31599, 0, 5962, 1, 0, 0, 26124), -- Marshal's Kodohide Bracers
(54650, 156, 31597, 0, 5963, 1, 0, 0, 26124), -- Marshal's Kodohide Boots
(54650, 155, 31596, 0, 5962, 1, 0, 0, 26124), -- Marshal's Kodohide Belt
(54650, 154, 28448, 0, 5962, 1, 0, 0, 26124), -- General's Wyrmhide Bracers
(54650, 153, 28447, 0, 5963, 1, 0, 0, 26124), -- General's Wyrmhide Boots
(54650, 152, 28446, 0, 5962, 1, 0, 0, 26124), -- General's Wyrmhide Belt
(54650, 151, 29006, 0, 5962, 1, 0, 0, 26124), -- Marshal's Wyrmhide Bracers
(54650, 150, 29005, 0, 5963, 1, 0, 0, 26124), -- Marshal's Wyrmhide Boots
(54650, 149, 29004, 0, 5962, 1, 0, 0, 26124), -- Marshal's Wyrmhide Belt
(54650, 148, 28445, 0, 5962, 1, 0, 0, 26124), -- General's Dragonhide Bracers
(54650, 147, 28444, 0, 5963, 1, 0, 0, 26124), -- General's Dragonhide Boots
(54650, 146, 28443, 0, 5962, 1, 0, 0, 26124), -- General's Dragonhide Belt
(54650, 145, 28978, 0, 5962, 1, 0, 0, 26124), -- Marshal's Dragonhide Bracers
(54650, 144, 28977, 0, 5963, 1, 0, 0, 26124), -- Marshal's Dragonhide Boots
(54650, 143, 28976, 0, 5962, 1, 0, 0, 26124), -- Marshal's Dragonhide Belt
(54650, 142, 28405, 0, 5962, 1, 0, 0, 26124), -- General's Dreadweave Cuffs
(54650, 141, 28402, 0, 5963, 1, 0, 0, 26124), -- General's Dreadweave Stalkers
(54650, 140, 28404, 0, 5962, 1, 0, 0, 26124), -- General's Dreadweave Belt
(54650, 139, 28981, 0, 5962, 1, 0, 0, 26124), -- Marshal's Dreadweave Cuffs
(54650, 138, 28982, 0, 5963, 1, 0, 0, 26124), -- Marshal's Dreadweave Stalkers
(54650, 137, 28980, 0, 5962, 1, 0, 0, 26124), -- Marshal's Dreadweave Belt
(54650, 136, 32973, 0, 5962, 1, 0, 0, 26124), -- General's Mooncloth Cuffs
(54650, 135, 32975, 0, 5963, 1, 0, 0, 26124), -- General's Mooncloth Slippers
(54650, 134, 32974, 0, 5962, 1, 0, 0, 26124), -- General's Mooncloth Belt
(54650, 133, 32977, 0, 5962, 1, 0, 0, 26124), -- Marshal's Mooncloth Cuffs
(54650, 132, 32978, 0, 5963, 1, 0, 0, 26124), -- Marshal's Mooncloth Slippers
(54650, 131, 32976, 0, 5962, 1, 0, 0, 26124), -- Marshal's Mooncloth Belt
(54650, 130, 28411, 0, 5962, 1, 0, 0, 26124), -- General's Silk Cuffs
(54650, 129, 28410, 0, 5963, 1, 0, 0, 26124), -- General's Silk Footguards
(54650, 128, 28409, 0, 5962, 1, 0, 0, 26124), -- General's Silk Belt
(54650, 127, 29002, 0, 5962, 1, 0, 0, 26124), -- Marshal's Silk Cuffs
(54650, 126, 29003, 0, 5963, 1, 0, 0, 26124), -- Marshal's Silk Footguards
(54650, 125, 29001, 0, 5962, 1, 0, 0, 26124), -- Marshal's Silk Belt
(54650, 124, 28451, 0, 5962, 1, 0, 0, 26124), -- General's Chain Bracers
(54650, 123, 28449, 0, 5963, 1, 0, 0, 26124), -- General's Chain Sabatons
(54650, 122, 28450, 0, 5962, 1, 0, 0, 26124), -- General's Chain Girdle
(54650, 121, 28973, 0, 5962, 1, 0, 0, 26124), -- Marshal's Chain Bracers
(54650, 120, 28975, 0, 5963, 1, 0, 0, 26124), -- Marshal's Chain Sabatons
(54650, 119, 28974, 0, 5962, 1, 0, 0, 26124), -- Marshal's Chain Girdle
(54650, 118, 28605, 0, 5962, 1, 0, 0, 26124), -- General's Linked Bracers
(54650, 117, 28630, 0, 5963, 1, 0, 0, 26124), -- General's Linked Sabatons
(54650, 116, 28629, 0, 5962, 1, 0, 0, 26124), -- General's Linked Girdle
(54650, 115, 28989, 0, 5962, 1, 0, 0, 26124), -- Marshal's Linked Bracers
(54650, 114, 28991, 0, 5963, 1, 0, 0, 26124), -- Marshal's Linked Sabatons
(54650, 113, 28990, 0, 5962, 1, 0, 0, 26124), -- Marshal's Linked Girdle
(54650, 112, 32991, 0, 5962, 1, 0, 0, 26124), -- General's Ringmail Bracers
(54650, 111, 32993, 0, 5963, 1, 0, 0, 26124), -- General's Ringmail Sabatons
(54650, 110, 32992, 0, 5962, 1, 0, 0, 26124), -- General's Ringmail Girdle
(54650, 109, 32994, 0, 5962, 1, 0, 0, 26124), -- Marshal's Ringmail Bracers
(54650, 108, 32996, 0, 5963, 1, 0, 0, 26124), -- Marshal's Ringmail Sabatons
(54650, 107, 32995, 0, 5962, 1, 0, 0, 26124), -- Marshal's Ringmail Girdle
(54650, 106, 147771, 0, 5962, 1, 0, 0, 26124), -- General's Satin Cuffs
(54650, 105, 147613, 0, 5962, 1, 0, 0, 26124), -- General's Satin Cord
(54650, 104, 147614, 0, 5963, 1, 0, 0, 26124), -- General's Satin Slippers
(54650, 103, 147772, 0, 5962, 1, 0, 0, 26124), -- General's Felweave Cuffs
(54650, 102, 147615, 0, 5962, 1, 0, 0, 26124), -- General's Felweave Belt
(54650, 101, 147616, 0, 5963, 1, 0, 0, 26124), -- General's Felweave Boots
(54650, 100, 28638, 0, 5962, 1, 0, 0, 26124), -- General's Mail Bracers
(54650, 99, 28640, 0, 5963, 1, 0, 0, 26124), -- General's Mail Sabatons
(54650, 98, 28639, 0, 5962, 1, 0, 0, 26124), -- General's Mail Girdle
(54650, 97, 28992, 0, 5962, 1, 0, 0, 26124), -- Marshal's Mail Bracers
(54650, 96, 28994, 0, 5963, 1, 0, 0, 26124), -- Marshal's Mail Sabatons
(54650, 95, 28993, 0, 5962, 1, 0, 0, 26124), -- Marshal's Mail Girdle
(54650, 89, 25854, 0, 5963, 1, 0, 0, 26124), -- Gladiator's Silk Amice
(54650, 88, 25858, 0, 5964, 1, 0, 0, 26124), -- Gladiator's Silk Trousers
(54650, 87, 25857, 0, 5963, 1, 0, 0, 26124), -- Gladiator's Silk Handguards
(54650, 86, 25855, 0, 5964, 1, 0, 0, 26124), -- Gladiator's Silk Cowl
(54650, 85, 25856, 0, 5964, 1, 0, 0, 26124), -- Gladiator's Silk Raiment
(54650, 9, 146617, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Gladiator's Silk Armor
(24974, 1, 37460, 0, 0, 1, 0, 0, 26124), -- Rope Pet Leash
(19573, 6, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19573, 5, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19573, 4, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19573, 2, 3371, 0, 0, 1, 0, 0, 26124); -- Crystal Vial

UPDATE `npc_vendor` SET `slot`=56, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=28284 AND `ExtendedCost`=0 AND `type`=1); -- Don Carlos Tequila
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=4600 AND `ExtendedCost`=0 AND `type`=1); -- Cherry Grog
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `slot`=1172, `maxcount`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23737 AND `ExtendedCost`=0 AND `type`=1); -- Adamantite Grenade
UPDATE `npc_vendor` SET `slot`=1171, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23782 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Casing
UPDATE `npc_vendor` SET `slot`=1170, `maxcount`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23771 AND `ExtendedCost`=0 AND `type`=1); -- Green Smoke Flare
UPDATE `npc_vendor` SET `slot`=1168, `maxcount`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23783 AND `ExtendedCost`=0 AND `type`=1); -- Handful of Fel Iron Bolts
UPDATE `npc_vendor` SET `slot`=1167, `maxcount`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23736 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Bomb
UPDATE `npc_vendor` SET `slot`=1166, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=1164, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1163, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=101, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77889 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Silk Raiment
UPDATE `npc_vendor` SET `slot`=100, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77890 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Silk Amice
UPDATE `npc_vendor` SET `slot`=99, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77886 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Silk Cowl
UPDATE `npc_vendor` SET `slot`=98, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77901 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Satin Robes
UPDATE `npc_vendor` SET `slot`=97, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77899 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Satin Mantle
UPDATE `npc_vendor` SET `slot`=96, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77900 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Satin Cowl
UPDATE `npc_vendor` SET `slot`=95, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77919 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Dreadweave Robe
UPDATE `npc_vendor` SET `slot`=94, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77920 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Dreadweave Mantle
UPDATE `npc_vendor` SET `slot`=93, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77917 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Dreadweave Hood
UPDATE `npc_vendor` SET `slot`=92, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77891 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Silk Trousers
UPDATE `npc_vendor` SET `slot`=91, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77888 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Silk Boots
UPDATE `npc_vendor` SET `slot`=90, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77887 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Silk Handguards
UPDATE `npc_vendor` SET `slot`=89, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77902 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Satin Leggings
UPDATE `npc_vendor` SET `slot`=88, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77903 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Satin Boots
UPDATE `npc_vendor` SET `slot`=87, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77898 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Satin Gloves
UPDATE `npc_vendor` SET `slot`=86, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77921 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Dreadweave Pants
UPDATE `npc_vendor` SET `slot`=85, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77918 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Dreadweave Boots
UPDATE `npc_vendor` SET `slot`=84, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77916 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Dreadweave Gloves
UPDATE `npc_vendor` SET `slot`=83, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77779 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Silk Mantle
UPDATE `npc_vendor` SET `slot`=82, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77778 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Silk Cowl
UPDATE `npc_vendor` SET `slot`=81, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77796 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Satin Mantle
UPDATE `npc_vendor` SET `slot`=80, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77795 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Satin Hood
UPDATE `npc_vendor` SET `slot`=79, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77846 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dreadweave Spaulders
UPDATE `npc_vendor` SET `slot`=78, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77845 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dreadweave Cowl
UPDATE `npc_vendor` SET `slot`=77, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77772 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Silk Shoulderpads
UPDATE `npc_vendor` SET `slot`=76, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77776 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Silk Hood
UPDATE `npc_vendor` SET `slot`=75, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77789 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Satin Shoulderpads
UPDATE `npc_vendor` SET `slot`=74, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77792 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Satin Cowl
UPDATE `npc_vendor` SET `slot`=73, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77842 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dreadweave Shoulders
UPDATE `npc_vendor` SET `slot`=72, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77837 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dreadweave Hood
UPDATE `npc_vendor` SET `slot`=71, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77782 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Silk Legguards
UPDATE `npc_vendor` SET `slot`=70, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77781 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Silk Tunic
UPDATE `npc_vendor` SET `slot`=69, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77798 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Satin Legguards
UPDATE `npc_vendor` SET `slot`=68, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77802 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Satin Tunic
UPDATE `npc_vendor` SET `slot`=67, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77852 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dreadweave Legguards
UPDATE `npc_vendor` SET `slot`=66, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77851 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dreadweave Tunic
UPDATE `npc_vendor` SET `slot`=65, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77774 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Silk Pants
UPDATE `npc_vendor` SET `slot`=64, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77770 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Silk Robes
UPDATE `npc_vendor` SET `slot`=63, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77794 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Satin Trousers
UPDATE `npc_vendor` SET `slot`=62, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77793 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Satin Vestments
UPDATE `npc_vendor` SET `slot`=61, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77838 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dreadweave Leggings
UPDATE `npc_vendor` SET `slot`=60, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77841 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dreadweave Robe
UPDATE `npc_vendor` SET `slot`=59, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77783 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Silk Handwraps
UPDATE `npc_vendor` SET `slot`=57, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77773 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Silk Walkers
UPDATE `npc_vendor` SET `slot`=56, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77803 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Satin Handwraps
UPDATE `npc_vendor` SET `slot`=54, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77804 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Satin Walkers
UPDATE `npc_vendor` SET `slot`=53, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77849 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dreadweave Handwraps
UPDATE `npc_vendor` SET `slot`=51, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77843 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dreadweave Walkers
UPDATE `npc_vendor` SET `slot`=50, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77775 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Silk Gloves
UPDATE `npc_vendor` SET `slot`=49, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77771 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Silk Footwraps
UPDATE `npc_vendor` SET `slot`=48, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77791 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Satin Gloves
UPDATE `npc_vendor` SET `slot`=47, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77790 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Satin Boots
UPDATE `npc_vendor` SET `slot`=46, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77840 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dreadweave Gloves
UPDATE `npc_vendor` SET `slot`=45, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77839 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dreadweave Boots
UPDATE `npc_vendor` SET `slot`=44, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77786 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Silk Cuffs
UPDATE `npc_vendor` SET `slot`=43, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77788 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Silk Cuffs
UPDATE `npc_vendor` SET `slot`=42, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77907 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Leather Spaulders
UPDATE `npc_vendor` SET `slot`=41, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77908 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Leather Breastplate
UPDATE `npc_vendor` SET `slot`=40, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77909 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Leather Helm
UPDATE `npc_vendor` SET `slot`=39, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77878 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Dragonhide Epaulets
UPDATE `npc_vendor` SET `slot`=38, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77876 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Dragonhide Hauberk
UPDATE `npc_vendor` SET `slot`=37, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77874 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Dragonhide Helmet
UPDATE `npc_vendor` SET `slot`=36, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77906 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Leather Legguards
UPDATE `npc_vendor` SET `slot`=35, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77905 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Leather Mitts
UPDATE `npc_vendor` SET `slot`=34, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77904 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Leather Treads
UPDATE `npc_vendor` SET `slot`=33, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77877 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Dragonhide Leggings
UPDATE `npc_vendor` SET `slot`=32, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77879 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Dragonhide Gloves
UPDATE `npc_vendor` SET `slot`=31, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77875 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Dragonhide Boots
UPDATE `npc_vendor` SET `slot`=30, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77819 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Leather Shoulders
UPDATE `npc_vendor` SET `slot`=29, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77815 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Leather Helm
UPDATE `npc_vendor` SET `slot`=28, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77746 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dragonhide Shoulders
UPDATE `npc_vendor` SET `slot`=27, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77752 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dragonhide Headguard
UPDATE `npc_vendor` SET `slot`=26, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77806 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Leather Mantle
UPDATE `npc_vendor` SET `slot`=25, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77805 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Leather Headguard
UPDATE `npc_vendor` SET `slot`=24, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77737 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dragonhide Spaulders
UPDATE `npc_vendor` SET `slot`=23, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77739 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Dragonhide Helm
UPDATE `npc_vendor` SET `slot`=22, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77818 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Leather Legguards
UPDATE `npc_vendor` SET `slot`=21, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77821 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Leather Chestpiece
UPDATE `npc_vendor` SET `slot`=20, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77744 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dragonhide Leggings
UPDATE `npc_vendor` SET `slot`=19, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77749 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dragonhide Chestpiece
UPDATE `npc_vendor` SET `slot`=18, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77807 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Leather Leggings
UPDATE `npc_vendor` SET `slot`=17, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77808 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Leather Hauberk
UPDATE `npc_vendor` SET `slot`=16, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77740 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dragonhide Trousers
UPDATE `npc_vendor` SET `slot`=15, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77738 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Dragonhide Breastplate
UPDATE `npc_vendor` SET `slot`=14, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77816 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Leather Walkers
UPDATE `npc_vendor` SET `slot`=12, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77817 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Leather Grips
UPDATE `npc_vendor` SET `slot`=11, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77747 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dragonhide Treads
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77750 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dragonhide Grips
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77809 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Leather Treads
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77810 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Leather Vices
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77736 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dragonhide Boots
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77741 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Dragonhide Gauntlets
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77814 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Leather Armguards
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77743 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Dragonhide Armguards
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77822 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Leather Armguards
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=58152 AND `item`=77753 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Dragonhide Armguards
UPDATE `npc_vendor` SET `slot`=72, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77923 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Plate Shoulders
UPDATE `npc_vendor` SET `slot`=71, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77927 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Plate Headpiece
UPDATE `npc_vendor` SET `slot`=70, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77924 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Plate Armor
UPDATE `npc_vendor` SET `slot`=69, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77897 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Lamellar Pauldrons
UPDATE `npc_vendor` SET `slot`=68, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77894 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Lamellar Faceguard
UPDATE `npc_vendor` SET `slot`=67, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77892 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Lamellar Chestplate
UPDATE `npc_vendor` SET `slot`=66, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77926 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Plate Leggings
UPDATE `npc_vendor` SET `slot`=65, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77922 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Plate Boots
UPDATE `npc_vendor` SET `slot`=64, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77925 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Plate Gauntlets
UPDATE `npc_vendor` SET `slot`=63, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77896 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Lamellar Legplates
UPDATE `npc_vendor` SET `slot`=62, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77893 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Lamellar Boots
UPDATE `npc_vendor` SET `slot`=61, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77895 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Lamellar Gloves
UPDATE `npc_vendor` SET `slot`=60, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77868 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Plate Shoulders
UPDATE `npc_vendor` SET `slot`=59, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77869 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Plate Helm
UPDATE `npc_vendor` SET `slot`=58, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77872 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Lamellar Shoulders
UPDATE `npc_vendor` SET `slot`=57, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77871 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Lamellar Headguard
UPDATE `npc_vendor` SET `slot`=56, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77856 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Plate Pauldrons
UPDATE `npc_vendor` SET `slot`=55, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77855 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Plate Headguard
UPDATE `npc_vendor` SET `slot`=54, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77866 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Plate Leggings
UPDATE `npc_vendor` SET `slot`=53, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77865 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Plate Hauberk
UPDATE `npc_vendor` SET `slot`=52, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77854 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Plate Armor
UPDATE `npc_vendor` SET `slot`=51, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77857 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Plate Legguards
UPDATE `npc_vendor` SET `slot`=50, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77873 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Lamellar Breastplate
UPDATE `npc_vendor` SET `slot`=49, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77663 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Lamellar Leggings
UPDATE `npc_vendor` SET `slot`=48, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77862 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Plate Greaves
UPDATE `npc_vendor` SET `slot`=47, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77863 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Plate Gauntlets
UPDATE `npc_vendor` SET `slot`=46, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77928 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Lamellar Sabatons
UPDATE `npc_vendor` SET `slot`=44, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77929 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Lamellar Gauntlets
UPDATE `npc_vendor` SET `slot`=43, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77853 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Plate Boots
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77860 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Plate Gloves
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77861 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Plate Bracers
UPDATE `npc_vendor` SET `slot`=39, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77910 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Mail Spaulders
UPDATE `npc_vendor` SET `slot`=38, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77914 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Mail Armor
UPDATE `npc_vendor` SET `slot`=37, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77913 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Mail Helm
UPDATE `npc_vendor` SET `slot`=36, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77880 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Chain Shoulders
UPDATE `npc_vendor` SET `slot`=35, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77882 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Chain Chestpiece
UPDATE `npc_vendor` SET `slot`=34, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77883 AND `ExtendedCost`=0 AND `type`=1); -- Replica Warlord's Chain Helmet
UPDATE `npc_vendor` SET `slot`=33, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77915 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Mail Leggings
UPDATE `npc_vendor` SET `slot`=32, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77912 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Mail Gauntlets
UPDATE `npc_vendor` SET `slot`=31, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77911 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Mail Boots
UPDATE `npc_vendor` SET `slot`=30, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77881 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Chain Legguards
UPDATE `npc_vendor` SET `slot`=29, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77885 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Chain Gloves
UPDATE `npc_vendor` SET `slot`=28, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77884 AND `ExtendedCost`=0 AND `type`=1); -- Replica General's Chain Boots
UPDATE `npc_vendor` SET `slot`=27, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77831 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Mail Pauldrons
UPDATE `npc_vendor` SET `slot`=26, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77832 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Mail Headguard
UPDATE `npc_vendor` SET `slot`=25, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77766 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Chain Shoulders
UPDATE `npc_vendor` SET `slot`=24, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77765 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Chain Helm
UPDATE `npc_vendor` SET `slot`=23, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77826 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Mail Shoulders
UPDATE `npc_vendor` SET `slot`=22, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77827 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Mail Helm
UPDATE `npc_vendor` SET `slot`=21, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77754 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Chain Pauldrons
UPDATE `npc_vendor` SET `slot`=20, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77759 AND `ExtendedCost`=0 AND `type`=1); -- Replica Champion's Chain Headguard
UPDATE `npc_vendor` SET `slot`=19, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77829 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Mail Legguards
UPDATE `npc_vendor` SET `slot`=18, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77834 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Mail Hauberk
UPDATE `npc_vendor` SET `slot`=17, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77760 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Chain Legguards
UPDATE `npc_vendor` SET `slot`=16, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77768 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Chain Hauberk
UPDATE `npc_vendor` SET `slot`=15, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77825 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Mail Leggings
UPDATE `npc_vendor` SET `slot`=14, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77824 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Mail Chestpiece
UPDATE `npc_vendor` SET `slot`=13, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77758 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Chain Leggings
UPDATE `npc_vendor` SET `slot`=12, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77757 AND `ExtendedCost`=0 AND `type`=1); -- Replica Legionnaire's Chain Breastplate
UPDATE `npc_vendor` SET `slot`=11, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77833 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Mail Vices
UPDATE `npc_vendor` SET `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77830 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Mail Greaves
UPDATE `npc_vendor` SET `slot`=7, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77764 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Chain Vices
UPDATE `npc_vendor` SET `slot`=6, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77767 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Chain Greaves
UPDATE `npc_vendor` SET `slot`=5, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77823 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Mail Grips
UPDATE `npc_vendor` SET `slot`=4, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77828 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Mail Walkers
UPDATE `npc_vendor` SET `slot`=3, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77756 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Chain Gauntlets
UPDATE `npc_vendor` SET `slot`=2, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77755 AND `ExtendedCost`=0 AND `type`=1); -- Replica Blood Guard's Chain Boots
UPDATE `npc_vendor` SET `slot`=1, `PlayerConditionID`=13633, `VerifiedBuild`=26124 WHERE (`entry`=54648 AND `item`=77835 AND `ExtendedCost`=0 AND `type`=1); -- Replica First Sergeant's Mail Wristguards
UPDATE `npc_vendor` SET `slot`=99, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77667 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Dragonhide Spaulders
UPDATE `npc_vendor` SET `slot`=98, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77670 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Dragonhide Breastplate
UPDATE `npc_vendor` SET `slot`=97, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77671 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Dragonhide Helmet
UPDATE `npc_vendor` SET `slot`=96, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77697 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Leather Epaulets
UPDATE `npc_vendor` SET `slot`=95, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77701 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Leather Chestpiece
UPDATE `npc_vendor` SET `slot`=94, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77700 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Leather Mask
UPDATE `npc_vendor` SET `slot`=93, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77696 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Leather Leggings
UPDATE `npc_vendor` SET `slot`=92, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77698 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Leather Handgrips
UPDATE `npc_vendor` SET `slot`=91, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77699 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Leather Footguards
UPDATE `npc_vendor` SET `slot`=90, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77668 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Dragonhide Legguards
UPDATE `npc_vendor` SET `slot`=89, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77666 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Dragonhide Gauntlets
UPDATE `npc_vendor` SET `slot`=88, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77669 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Dragonhide Boots
UPDATE `npc_vendor` SET `slot`=87, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77813 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Leather Shoulders
UPDATE `npc_vendor` SET `slot`=86, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77748 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Dragonhide Shoulders
UPDATE `npc_vendor` SET `slot`=85, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77636 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Leather Spaulders
UPDATE `npc_vendor` SET `slot`=84, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77598 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Dragonhide Epaulets
UPDATE `npc_vendor` SET `slot`=83, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77820 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Leather Helm
UPDATE `npc_vendor` SET `slot`=82, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77742 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Dragonhide Headguard
UPDATE `npc_vendor` SET `slot`=81, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77635 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Leather Veil
UPDATE `npc_vendor` SET `slot`=80, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77600 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Dragonhide Shroud
UPDATE `npc_vendor` SET `slot`=79, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77812 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Leather Legguards
UPDATE `npc_vendor` SET `slot`=78, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77745 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Dragonhide Leggings
UPDATE `npc_vendor` SET `slot`=77, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77601 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Dragonhide Leggings
UPDATE `npc_vendor` SET `slot`=76, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77811 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Leather Chestpiece
UPDATE `npc_vendor` SET `slot`=75, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77602 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Dragonhide Tunic
UPDATE `npc_vendor` SET `slot`=74, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77638 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Leather Legguards
UPDATE `npc_vendor` SET `slot`=73, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77633 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Leather Armor
UPDATE `npc_vendor` SET `slot`=72, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77721 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dragonhide Treads
UPDATE `npc_vendor` SET `slot`=70, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77599 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dragonhide Footwraps
UPDATE `npc_vendor` SET `slot`=69, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77720 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dragonhide Grips
UPDATE `npc_vendor` SET `slot`=68, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77603 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dragonhide Gloves
UPDATE `npc_vendor` SET `slot`=67, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77730 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Leather Walkers
UPDATE `npc_vendor` SET `slot`=65, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77637 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Leather Boots
UPDATE `npc_vendor` SET `slot`=64, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77731 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Leather Grips
UPDATE `npc_vendor` SET `slot`=63, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77634 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Leather Gauntlets
UPDATE `npc_vendor` SET `slot`=62, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77639 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Leather Armsplints
UPDATE `npc_vendor` SET `slot`=61, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77640 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Leather Armsplints
UPDATE `npc_vendor` SET `slot`=60, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77604 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Dragonhide Armsplints
UPDATE `npc_vendor` SET `slot`=59, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77605 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Dragonhide Armsplints
UPDATE `npc_vendor` SET `slot`=58, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77678 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Silk Vestments
UPDATE `npc_vendor` SET `slot`=57, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77679 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Silk Spaulders
UPDATE `npc_vendor` SET `slot`=56, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77694 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Satin Vestments
UPDATE `npc_vendor` SET `slot`=55, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77692 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Satin Mantle
UPDATE `npc_vendor` SET `slot`=54, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77709 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Dreadweave Shoulders
UPDATE `npc_vendor` SET `slot`=53, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77712 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Dreadweave Robe
UPDATE `npc_vendor` SET `slot`=52, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77695 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Headdress
UPDATE `npc_vendor` SET `slot`=51, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77682 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Coronet
UPDATE `npc_vendor` SET `slot`=50, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77710 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Coronal
UPDATE `npc_vendor` SET `slot`=49, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77680 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Silk Leggings
UPDATE `npc_vendor` SET `slot`=48, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77681 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Silk Gloves
UPDATE `npc_vendor` SET `slot`=47, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77683 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Silk Footwraps
UPDATE `npc_vendor` SET `slot`=46, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77691 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Satin Pants
UPDATE `npc_vendor` SET `slot`=45, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77693 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Satin Gloves
UPDATE `npc_vendor` SET `slot`=44, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77690 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Satin Sandals
UPDATE `npc_vendor` SET `slot`=43, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77711 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Dreadweave Leggings
UPDATE `npc_vendor` SET `slot`=42, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77713 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Dreadweave Gloves
UPDATE `npc_vendor` SET `slot`=41, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77708 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Dreadweave Boots
UPDATE `npc_vendor` SET `slot`=40, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77850 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Dreadweave Spaulders
UPDATE `npc_vendor` SET `slot`=39, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77631 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Satin Amice
UPDATE `npc_vendor` SET `slot`=38, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77615 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Silk Spaulders
UPDATE `npc_vendor` SET `slot`=37, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77647 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Dreadweave Mantle
UPDATE `npc_vendor` SET `slot`=36, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77801 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Satin Mantle
UPDATE `npc_vendor` SET `slot`=35, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77784 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Silk Cowl
UPDATE `npc_vendor` SET `slot`=34, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77844 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Dreadweave Cowl
UPDATE `npc_vendor` SET `slot`=33, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77800 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Satin Hood
UPDATE `npc_vendor` SET `slot`=32, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77652 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Headguard
UPDATE `npc_vendor` SET `slot`=31, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77629 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Diadem
UPDATE `npc_vendor` SET `slot`=30, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77619 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Crown
UPDATE `npc_vendor` SET `slot`=29, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77618 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Silk Leggings
UPDATE `npc_vendor` SET `slot`=28, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77777 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Silk Legguards
UPDATE `npc_vendor` SET `slot`=27, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77614 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Silk Raiment
UPDATE `npc_vendor` SET `slot`=26, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77785 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Silk Tunic
UPDATE `npc_vendor` SET `slot`=25, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77628 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Satin Leggings
UPDATE `npc_vendor` SET `slot`=24, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77797 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Satin Legguards
UPDATE `npc_vendor` SET `slot`=23, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77630 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Satin Robes
UPDATE `npc_vendor` SET `slot`=22, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77799 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Satin Tunic
UPDATE `npc_vendor` SET `slot`=21, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77847 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Dreadweave Legguards
UPDATE `npc_vendor` SET `slot`=20, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77649 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Dreadweave Leggings
UPDATE `npc_vendor` SET `slot`=19, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77848 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Dreadweave Tunic
UPDATE `npc_vendor` SET `slot`=18, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77648 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Dreadweave Robe
UPDATE `npc_vendor` SET `slot`=17, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77724 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Silk Walkers
UPDATE `npc_vendor` SET `slot`=15, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77616 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Silk Boots
UPDATE `npc_vendor` SET `slot`=14, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77725 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Silk Handwraps
UPDATE `npc_vendor` SET `slot`=13, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77617 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Silk Gloves
UPDATE `npc_vendor` SET `slot`=12, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77729 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Satin Walkers
UPDATE `npc_vendor` SET `slot`=10, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77632 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Satin Boots
UPDATE `npc_vendor` SET `slot`=9, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77728 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Satin Handwraps
UPDATE `npc_vendor` SET `slot`=8, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77627 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Satin Gloves
UPDATE `npc_vendor` SET `slot`=7, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77732 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dreadweave Walkers
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77651 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dreadweave Boots
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77650 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dreadweave Gloves
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77733 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Dreadweave Handwraps
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77620 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Silk Cuffs
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=40209 AND `item`=77787 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Silk Cuffs
UPDATE `npc_vendor` SET `slot`=74, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77718 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Plate Shoulderguards
UPDATE `npc_vendor` SET `slot`=73, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77714 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Plate Armor
UPDATE `npc_vendor` SET `slot`=72, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77715 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Plate Helm
UPDATE `npc_vendor` SET `slot`=71, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77689 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Lamellar Pauldrons
UPDATE `npc_vendor` SET `slot`=70, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77687 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Lamellar Chestplate
UPDATE `npc_vendor` SET `slot`=69, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77688 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Lamellar Faceguard
UPDATE `npc_vendor` SET `slot`=68, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77717 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Plate Legguards
UPDATE `npc_vendor` SET `slot`=67, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77716 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Plate Gauntlets
UPDATE `npc_vendor` SET `slot`=66, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77719 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Plate Boots
UPDATE `npc_vendor` SET `slot`=65, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77686 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Lamellar Legplates
UPDATE `npc_vendor` SET `slot`=64, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77685 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Lamellar Gloves
UPDATE `npc_vendor` SET `slot`=63, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77684 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Lamellar Boots
UPDATE `npc_vendor` SET `slot`=62, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77859 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Plate Shoulders
UPDATE `npc_vendor` SET `slot`=61, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77665 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Lamellar Shoulders
UPDATE `npc_vendor` SET `slot`=60, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77664 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Lamellar Headguard
UPDATE `npc_vendor` SET `slot`=59, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77657 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Plate Pauldrons
UPDATE `npc_vendor` SET `slot`=58, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77867 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Plate Helmet
UPDATE `npc_vendor` SET `slot`=57, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77656 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Plate Helm
UPDATE `npc_vendor` SET `slot`=56, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77621 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Lamellar Shoulders
UPDATE `npc_vendor` SET `slot`=55, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77624 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Lamellar Headguard
UPDATE `npc_vendor` SET `slot`=54, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77661 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Lamellar Leggings
UPDATE `npc_vendor` SET `slot`=53, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77662 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Lamellar Breastplate
UPDATE `npc_vendor` SET `slot`=52, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77864 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Plate Leggings
UPDATE `npc_vendor` SET `slot`=51, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77655 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Plate Leggings
UPDATE `npc_vendor` SET `slot`=50, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77858 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Plate Hauberk
UPDATE `npc_vendor` SET `slot`=49, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77654 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Plate Chestguard
UPDATE `npc_vendor` SET `slot`=48, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77623 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Lamellar Leggings
UPDATE `npc_vendor` SET `slot`=47, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77626 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Lamellar Breastplate
UPDATE `npc_vendor` SET `slot`=46, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77735 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Plate Greaves
UPDATE `npc_vendor` SET `slot`=44, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77734 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Plate Gauntlets
UPDATE `npc_vendor` SET `slot`=43, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77726 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Lamellar Sabatons
UPDATE `npc_vendor` SET `slot`=41, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77727 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Lamellar Gauntlets
UPDATE `npc_vendor` SET `slot`=40, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77658 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Plate Boots
UPDATE `npc_vendor` SET `slot`=39, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77653 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Plate Gauntlets
UPDATE `npc_vendor` SET `slot`=38, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77625 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Lamellar Sabatons
UPDATE `npc_vendor` SET `slot`=37, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77622 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Lamellar Gauntlets
UPDATE `npc_vendor` SET `slot`=36, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77659 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Plate Wristguards
UPDATE `npc_vendor` SET `slot`=35, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77660 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Plate Wristguards
UPDATE `npc_vendor` SET `slot`=34, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77707 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Mail Armor
UPDATE `npc_vendor` SET `slot`=33, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77705 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Mail Spaulders
UPDATE `npc_vendor` SET `slot`=32, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77704 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Mail Helm
UPDATE `npc_vendor` SET `slot`=31, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77674 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Chain Breastplate
UPDATE `npc_vendor` SET `slot`=30, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77673 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Chain Spaulders
UPDATE `npc_vendor` SET `slot`=29, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77676 AND `ExtendedCost`=0 AND `type`=1); -- Replica Field Marshal's Chain Helm
UPDATE `npc_vendor` SET `slot`=28, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77706 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Mail Leggings
UPDATE `npc_vendor` SET `slot`=27, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77703 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Mail Gauntlets
UPDATE `npc_vendor` SET `slot`=26, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77702 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Mail Boots
UPDATE `npc_vendor` SET `slot`=25, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77675 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Chain Legguards
UPDATE `npc_vendor` SET `slot`=24, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77677 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Chain Grips
UPDATE `npc_vendor` SET `slot`=23, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77672 AND `ExtendedCost`=0 AND `type`=1); -- Replica Marshal's Chain Boots
UPDATE `npc_vendor` SET `slot`=22, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77762 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Chain Shoulders
UPDATE `npc_vendor` SET `slot`=21, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77645 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Mail Pauldrons
UPDATE `npc_vendor` SET `slot`=20, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77763 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Chain Helm
UPDATE `npc_vendor` SET `slot`=19, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77642 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Mail Headguard
UPDATE `npc_vendor` SET `slot`=18, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77607 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Chain Pauldrons
UPDATE `npc_vendor` SET `slot`=17, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77609 AND `ExtendedCost`=0 AND `type`=1); -- Replica Lieutenant Commander's Chain Helmet
UPDATE `npc_vendor` SET `slot`=16, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77643 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Mail Legguards
UPDATE `npc_vendor` SET `slot`=15, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77769 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Chain Legguards
UPDATE `npc_vendor` SET `slot`=14, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77611 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Chain Leggings
UPDATE `npc_vendor` SET `slot`=13, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77641 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Mail Hauberk
UPDATE `npc_vendor` SET `slot`=12, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77761 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Chain Hauberk
UPDATE `npc_vendor` SET `slot`=11, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77608 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Captain's Chain Hauberk
UPDATE `npc_vendor` SET `slot`=10, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77644 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Mail Greaves
UPDATE `npc_vendor` SET `slot`=9, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77646 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Mail Vices
UPDATE `npc_vendor` SET `slot`=7, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77723 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Chain Greaves
UPDATE `npc_vendor` SET `slot`=6, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77722 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Chain Vices
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77606 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Chain Boots
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77610 AND `ExtendedCost`=0 AND `type`=1); -- Replica Knight-Lieutenant's Chain Gauntlets
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77612 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Chain Armguards
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=23396 AND `item`=77613 AND `ExtendedCost`=0 AND `type`=1); -- Replica Sergeant Major's Chain Armguards
UPDATE `npc_vendor` SET `slot`=20, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77594 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Tome of Restoration
UPDATE `npc_vendor` SET `slot`=19, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77595 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Tome of Power
UPDATE `npc_vendor` SET `slot`=18, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77561 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Longsword
UPDATE `npc_vendor` SET `slot`=17, `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77560 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Claymore
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77558 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Punisher
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77557 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Hand Blade
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77566 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Repeater
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77565 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Bullseye
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77564 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Glaive
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77563 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Battle Hammer
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77562 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Handaxe
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77596 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Aegis
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77556 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Stave
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77555 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Hand Cannon
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77554 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Sunderer
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77553 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Warhammer
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77552 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Mageblade
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77551 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Dirk
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77550 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Swiftblade
UPDATE `npc_vendor` SET `PlayerConditionID`=13632, `VerifiedBuild`=26124 WHERE (`entry`=54649 AND `item`=77549 AND `ExtendedCost`=0 AND `type`=1); -- Replica Grand Marshal's Demolisher
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19574 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19574 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19574 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19574 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19574 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19574 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=1172, `maxcount`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23737 AND `ExtendedCost`=0 AND `type`=1); -- Adamantite Grenade
UPDATE `npc_vendor` SET `slot`=1171, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23782 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Casing
UPDATE `npc_vendor` SET `slot`=1170, `maxcount`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23771 AND `ExtendedCost`=0 AND `type`=1); -- Green Smoke Flare
UPDATE `npc_vendor` SET `slot`=1168, `maxcount`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23783 AND `ExtendedCost`=0 AND `type`=1); -- Handful of Fel Iron Bolts
UPDATE `npc_vendor` SET `slot`=1167, `maxcount`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=23736 AND `ExtendedCost`=0 AND `type`=1); -- Fel Iron Bomb
UPDATE `npc_vendor` SET `slot`=1166, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=1164, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1163, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19575 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=28344 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=28344 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=28344 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=28344 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=28344 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=28344 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19572 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=56, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=28284 AND `ExtendedCost`=0 AND `type`=1); -- Don Carlos Tequila
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=4600 AND `ExtendedCost`=0 AND `type`=1); -- Cherry Grog
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19617 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19573 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19573 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread

DELETE FROM `npc_vendor` WHERE (`entry`=20092 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20092 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20981 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19538 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19535 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19533 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19533 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19533 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20242 AND `item`=138796 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=22479 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=22479 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20194 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(20092, 14, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(20092, 13, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(20092, 12, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20092, 10, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(20092, 7, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(20092, 6, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(20092, 5, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(20092, 4, 28399, 0, 0, 1, 0, 0, 26124), -- Filtered Draenic Water
(20092, 3, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(20092, 2, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(20981, 2, 30746, 0, 0, 1, 0, 0, 26124), -- Mining Sack
(19538, 10, 52188, 0, 0, 1, 0, 0, 26124), -- Jeweler's Setting
(19535, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19533, 6, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19533, 5, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19533, 4, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20242, 22, 138796, 0, 0, 1, 0, 0, 26124), -- Illusion: Executioner
(22479, 2, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(22479, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(20194, 13, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(20194, 12, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(20194, 11, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(20194, 10, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20194, 8, 3371, 0, 0, 1, 0, 0, 26124), -- Crystal Vial
(20194, 6, 4470, 0, 0, 1, 0, 0, 26124), -- Simple Wood
(20194, 5, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(20194, 4, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(20194, 3, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(20194, 2, 28399, 0, 0, 1, 0, 0, 26124), -- Filtered Draenic Water
(20194, 1, 159, 0, 0, 1, 0, 0, 26124); -- Refreshing Spring Water

UPDATE `npc_vendor` SET `slot`=67, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=13446 AND `ExtendedCost`=0 AND `type`=1); -- Major Healing Potion
UPDATE `npc_vendor` SET `slot`=66, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=13444 AND `ExtendedCost`=0 AND `type`=1); -- Major Mana Potion
UPDATE `npc_vendor` SET `slot`=65, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=4426 AND `ExtendedCost`=0 AND `type`=1); -- Scroll of Strength III
UPDATE `npc_vendor` SET `slot`=64, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=4425 AND `ExtendedCost`=0 AND `type`=1); -- Scroll of Agility III
UPDATE `npc_vendor` SET `slot`=63, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=10308 AND `ExtendedCost`=0 AND `type`=1); -- Scroll of Intellect IV
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=65, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=4426 AND `ExtendedCost`=0 AND `type`=1); -- Scroll of Strength III
UPDATE `npc_vendor` SET `slot`=64, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=4425 AND `ExtendedCost`=0 AND `type`=1); -- Scroll of Agility III
UPDATE `npc_vendor` SET `slot`=63, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=10308 AND `ExtendedCost`=0 AND `type`=1); -- Scroll of Intellect IV
UPDATE `npc_vendor` SET `slot`=62, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=13446 AND `ExtendedCost`=0 AND `type`=1); -- Major Healing Potion
UPDATE `npc_vendor` SET `slot`=61, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=13444 AND `ExtendedCost`=0 AND `type`=1); -- Major Mana Potion
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=20092 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=90, `VerifiedBuild`=26124 WHERE (`entry`=20112 AND `item`=30755 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Fighting Claw
UPDATE `npc_vendor` SET `slot`=89, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20112 AND `item`=30751 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Light Axe
UPDATE `npc_vendor` SET `slot`=88, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20112 AND `item`=30752 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Battleaxe
UPDATE `npc_vendor` SET `slot`=87, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20112 AND `item`=30750 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Warblade
UPDATE `npc_vendor` SET `slot`=86, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20112 AND `item`=30749 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Sparring Blade
UPDATE `npc_vendor` SET `slot`=85, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=20112 AND `item`=30754 AND `ExtendedCost`=0 AND `type`=1); -- Ancient Bone Mace
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=20981 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=20981 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=20981 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20981 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=20981 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19531 AND `item`=29394 AND `ExtendedCost`=0 AND `type`=1); -- Lyribread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19531 AND `item`=29393 AND `ExtendedCost`=0 AND `type`=1); -- Diamond Berries
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19531 AND `item`=29395 AND `ExtendedCost`=0 AND `type`=1); -- Ethermead
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19531 AND `item`=29454 AND `ExtendedCost`=0 AND `type`=1); -- Silverwine
UPDATE `npc_vendor` SET `slot`=791, `VerifiedBuild`=26124 WHERE (`entry`=19536 AND `item`=29378 AND `ExtendedCost`=0 AND `type`=1); -- Starheart Baton
UPDATE `npc_vendor` SET `slot`=790, `VerifiedBuild`=26124 WHERE (`entry`=19536 AND `item`=29391 AND `ExtendedCost`=0 AND `type`=1); -- Pulse Dagger
UPDATE `npc_vendor` SET `slot`=789, `VerifiedBuild`=26124 WHERE (`entry`=19536 AND `item`=29380 AND `ExtendedCost`=0 AND `type`=1); -- Ethereum Phase Blade
UPDATE `npc_vendor` SET `slot`=788, `VerifiedBuild`=26124 WHERE (`entry`=19536 AND `item`=29372 AND `ExtendedCost`=0 AND `type`=1); -- Void-Talon
UPDATE `npc_vendor` SET `slot`=787, `VerifiedBuild`=26124 WHERE (`entry`=19536 AND `item`=29371 AND `ExtendedCost`=0 AND `type`=1); -- Nexus-Claw
UPDATE `npc_vendor` SET `slot`=786, `VerifiedBuild`=26124 WHERE (`entry`=19536 AND `item`=29377 AND `ExtendedCost`=0 AND `type`=1); -- Ethereum Phase-Spear
UPDATE `npc_vendor` SET `slot`=785, `VerifiedBuild`=26124 WHERE (`entry`=19536 AND `item`=78348 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Weapon - Executioner
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19539 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Setting
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19539 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28470 AND `ExtendedCost`=0 AND `type`=1); -- Subtle Amber
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28467 AND `ExtendedCost`=0 AND `type`=1); -- Smooth Amber
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28468 AND `ExtendedCost`=0 AND `type`=1); -- Rigid Zircon
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28464 AND `ExtendedCost`=0 AND `type`=1); -- Sparkling Zircon
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28463 AND `ExtendedCost`=0 AND `type`=1); -- Solid Zircon
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28459 AND `ExtendedCost`=0 AND `type`=1); -- Delicate Tourmaline
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28461 AND `ExtendedCost`=0 AND `type`=1); -- Brilliant Tourmaline
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19538 AND `item`=28458 AND `ExtendedCost`=0 AND `type`=1); -- Bold Tourmaline
UPDATE `npc_vendor` SET `slot`=410, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=409, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=408, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=407, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=406, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=405, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=404, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=403, `maxcount`=4, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=402, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=401, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `slot`=410, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=409, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=408, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=407, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=406, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=405, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=404, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=403, `maxcount`=4, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=402, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=401, `VerifiedBuild`=26124 WHERE (`entry`=19540 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `slot`=400, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=399, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=398, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=397, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=396, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=395, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=394, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=393, `maxcount`=2, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=392, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=391, `VerifiedBuild`=26124 WHERE (`entry`=19537 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19533 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19533 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19533 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=29363 AND `ExtendedCost`=0 AND `type`=1); -- Mana Wyrmling
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=29958 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dragonhawk Hatchling
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=29902 AND `ExtendedCost`=0 AND `type`=1); -- Red Moth Egg
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=29364 AND `ExtendedCost`=0 AND `type`=1); -- Brown Rabbit Crate
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=10392 AND `ExtendedCost`=0 AND `type`=1); -- Crimson Snake
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=10393 AND `ExtendedCost`=0 AND `type`=1); -- Undercity Cockroach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=8490 AND `ExtendedCost`=0 AND `type`=1); -- Cat Carrier (Siamese)
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20980 AND `item`=8495 AND `ExtendedCost`=0 AND `type`=1); -- Parrot Cage (Senegal)
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19534 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19534 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19534 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19534 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19534 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19534 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=82, `VerifiedBuild`=26124 WHERE (`entry`=20989 AND `item`=22829 AND `ExtendedCost`=0 AND `type`=1); -- Super Healing Potion
UPDATE `npc_vendor` SET `slot`=81, `VerifiedBuild`=26124 WHERE (`entry`=20989 AND `item`=13446 AND `ExtendedCost`=0 AND `type`=1); -- Major Healing Potion
UPDATE `npc_vendor` SET `slot`=80, `VerifiedBuild`=26124 WHERE (`entry`=20989 AND `item`=13444 AND `ExtendedCost`=0 AND `type`=1); -- Major Mana Potion
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=20989 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=31776 AND `ExtendedCost`=0 AND `type`=1); -- Consortium Tabard
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=33622 AND `ExtendedCost`=0 AND `type`=1); -- Design: Relentless Earthstorm Diamond
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29122 AND `ExtendedCost`=0 AND `type`=1); -- Nether Runner's Cowl
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29121 AND `ExtendedCost`=0 AND `type`=1); -- Guile of Khoraazi
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29119 AND `ExtendedCost`=0 AND `type`=1); -- Haramad's Bargain
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29117 AND `ExtendedCost`=0 AND `type`=1); -- Stormspire Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29116 AND `ExtendedCost`=0 AND `type`=1); -- Nomad's Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29115 AND `ExtendedCost`=0 AND `type`=1); -- Consortium Blaster
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=25734 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Fel Leather Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=25733 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Fel Leather Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=24314 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Bag of Jewels
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=23874 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Elemental Seaforium Charge
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=24178 AND `ExtendedCost`=0 AND `type`=1); -- Design: Pendant of the Null Rune
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29456 AND `ExtendedCost`=0 AND `type`=1); -- Gift of the Ethereal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=29457 AND `ExtendedCost`=0 AND `type`=1); -- Nethershard
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=22552 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Weapon - Major Striking
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=33305 AND `ExtendedCost`=0 AND `type`=1); -- Design: Don Julio's Heart
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=33156 AND `ExtendedCost`=0 AND `type`=1); -- Design: Crimson Sun
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=25908 AND `ExtendedCost`=0 AND `type`=1); -- Design: Swift Skyfire Diamond
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=23155 AND `ExtendedCost`=0 AND `type`=1); -- Design: Sparkling Azure Moonstone
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=23150 AND `ExtendedCost`=0 AND `type`=1); -- Design: Subtle Golden Draenite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=25732 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Fel Leather Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=23134 AND `ExtendedCost`=0 AND `type`=1); -- Design: Delicate Blood Garnet
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=23136 AND `ExtendedCost`=0 AND `type`=1); -- Design: Reckless Flame Spessarite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=23146 AND `ExtendedCost`=0 AND `type`=1); -- Design: Shifting Shadow Draenite
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20242 AND `item`=28274 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Cloak - PvP Power
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=22491 AND `item`=3025 AND `ExtendedCost`=0 AND `type`=1); -- BKP 42 "Ultra"
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=20194 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=20194 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=20463 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=20463 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=20463 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20463 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=20463 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=20463 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick

DELETE FROM `npc_vendor` WHERE (`entry`=19718 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23145 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23145 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19625 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19625 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19625 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19625 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19625 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=21183 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=21183 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=21183 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=21183 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19678 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19372 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19372 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19372 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=19372 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(19718, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(23145, 2, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(23145, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19625, 5, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(19625, 4, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(19625, 3, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(19625, 2, 28399, 0, 0, 1, 0, 0, 26124), -- Filtered Draenic Water
(19625, 1, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(21183, 8, 30744, 0, 0, 1, 0, 0, 26124), -- Draenic Leather Pack
(21183, 7, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(21183, 6, 27855, 0, 0, 1, 0, 0, 26124), -- Mag'har Grainbread
(21183, 5, 159, 0, 0, 1, 0, 0, 26124), -- Refreshing Spring Water
(19678, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(19372, 29, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(19372, 28, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(19372, 27, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(19372, 3, 85663, 0, 0, 1, 0, 0, 26124); -- Herbalist's Spade

UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=20, `maxcount`=1, `VerifiedBuild`=26124 WHERE (`entry`=20986 AND `item`=22578 AND `ExtendedCost`=0 AND `type`=1); -- Mote of Water
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19718 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23143 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23144 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23144 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23144 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23144 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23144 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=23144 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=29450 AND `ExtendedCost`=0 AND `type`=1); -- Telaari Grapes
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27856 AND `ExtendedCost`=0 AND `type`=1); -- Skethyl Berries
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21744 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=596, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=21901 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Imbued Netherweave Tunic
UPDATE `npc_vendor` SET `slot`=595, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=21900 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Imbued Netherweave Robe
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19521 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19518 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19520 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19625 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19517 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19517 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19517 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19517 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19517 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19517 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=30355 AND `ExtendedCost`=0 AND `type`=1); -- Grilled Shadowmoon Tuber
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19678 AND `item`=30823 AND `ExtendedCost`=0 AND `type`=1); -- Demon Warding Totem
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21183 AND `item`=30355 AND `ExtendedCost`=0 AND `type`=1); -- Grilled Shadowmoon Tuber
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1); -- War Staff
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1); -- Battle Staff
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1); -- War Maul
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1); -- War Hammer
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1); -- Morning Star
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1); -- Truncheon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19371 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19371 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19371 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=29449 AND `ExtendedCost`=0 AND `type`=1); -- Bladespire Bagel
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=29451 AND `ExtendedCost`=0 AND `type`=1); -- Clefthoof Ribs
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1); -- Smoked Talbuk Venison
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19352 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=19372 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19368 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20510 AND `item`=25527 AND `ExtendedCost`=0 AND `type`=1); -- Swift Red Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20510 AND `item`=25529 AND `ExtendedCost`=0 AND `type`=1); -- Swift Purple Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20510 AND `item`=25528 AND `ExtendedCost`=0 AND `type`=1); -- Swift Green Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20510 AND `item`=25473 AND `ExtendedCost`=0 AND `type`=1); -- Swift Blue Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20510 AND `item`=25472 AND `ExtendedCost`=0 AND `type`=1); -- Snowy Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20510 AND `item`=25470 AND `ExtendedCost`=0 AND `type`=1); -- Golden Gryphon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20510 AND `item`=25471 AND `ExtendedCost`=0 AND `type`=1); -- Ebon Gryphon
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1); -- War Staff
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1); -- Battle Staff
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1); -- War Maul
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1); -- War Hammer
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1); -- Morning Star
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19370 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1); -- Truncheon
UPDATE `npc_vendor` SET `slot`=150, `VerifiedBuild`=26124 WHERE (`entry`=19373 AND `item`=23638 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Lesser Ward of Shielding
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=19373 AND `item`=30784 AND `ExtendedCost`=0 AND `type`=1); -- Worn Mag'hari Gauntlets
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=19373 AND `item`=30781 AND `ExtendedCost`=0 AND `type`=1); -- Mag'hari Chain Vest
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=19373 AND `item`=30765 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Breastplate
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19373 AND `item`=30775 AND `ExtendedCost`=0 AND `type`=1); -- Layered Bone Shield
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=19373 AND `item`=30771 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Draenic Bracers
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=19373 AND `item`=30777 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Heavy Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19374 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19374 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19374 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19374 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19374 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=19374 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=137, `VerifiedBuild`=26124 WHERE (`entry`=19351 AND `item`=23807 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Adamantite Scope
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=19351 AND `item`=30758 AND `ExtendedCost`=0 AND `type`=1); -- Aldor Guardian Rifle
UPDATE `npc_vendor` SET `incrtime`=120 WHERE `entry`=33633 AND `maxcount`>0 AND `incrtime`=0; 
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=19617 AND `maxcount`>0 AND `incrtime`=0; 
UPDATE `npc_vendor` SET `incrtime`=1800 WHERE `entry`=18756 AND `maxcount`>0 AND `incrtime`=0; 
DELETE FROM `npc_vendor` WHERE `entry` IN (44283) AND `item` IN (116,117,118);
UPDATE `creature_template` SET `npcflag`=`npcflag`|128 WHERE `entry` IN (107599,107610,107619);
