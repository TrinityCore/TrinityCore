DELETE FROM `npc_vendor` WHERE (`entry`=40226 AND `item`=8385 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17421 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17421 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17421 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17421 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18427 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18427 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18427 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17101 AND `item`=136377 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17553 AND `item`=82344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17553 AND `item`=83094 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17553 AND `item`=82343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17553 AND `item`=83095 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(40226, 36, 8385, 1, 0, 1, 0, 0, 26124),
(17421, 1340, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(17421, 1330, 90146, 0, 0, 1, 0, 0, 26124), -- Tinker's Kit
(17421, 4, 4541, 0, 0, 1, 0, 0, 26124), -- Freshly Baked Bread
(17421, 3, 4540, 0, 0, 1, 0, 0, 26124), -- Tough Hunk of Bread
(18427, 8, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(18427, 5, 85663, 0, 0, 1, 0, 0, 26124), -- Herbalist's Spade
(18427, 3, 52188, 0, 0, 1, 0, 0, 26124), -- Jeweler's Setting
(17101, 2, 136377, 0, 0, 1, 0, 0, 26124), -- Oversized Bobber
(17553, 9, 82344, 0, 0, 1, 0, 0, 26124), -- Hearthglen Ambrosia
(17553, 8, 83094, 0, 0, 1, 0, 0, 26124), -- Foote Tripel
(17553, 7, 82343, 0, 0, 1, 0, 0, 26124), -- Lordaeron Lambic
(17553, 6, 83095, 0, 0, 1, 0, 0, 26124); -- Lagrave Stout

UPDATE `npc_vendor` SET `slot`=1339, `maxcount`=4, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=1338, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=1337, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=1336, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=1335, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=1334, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=1333, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=1332, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=1331, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=1329, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1328, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17421 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=22647 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Crunchy Spider Surprise
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15809 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Crossbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15808 AND `ExtendedCost`=0 AND `type`=1); -- Fine Light Crossbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15807 AND `ExtendedCost`=0 AND `type`=1); -- Light Crossbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=3027 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2507 AND `ExtendedCost`=0 AND `type`=1); -- Laminated Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2506 AND `ExtendedCost`=0 AND `type`=1); -- Hornwood Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2505 AND `ExtendedCost`=0 AND `type`=1); -- Polished Shortbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2504 AND `ExtendedCost`=0 AND `type`=1); -- Worn Shortbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15809 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Crossbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15808 AND `ExtendedCost`=0 AND `type`=1); -- Fine Light Crossbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15807 AND `ExtendedCost`=0 AND `type`=1); -- Light Crossbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=3027 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2507 AND `ExtendedCost`=0 AND `type`=1); -- Laminated Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2506 AND `ExtendedCost`=0 AND `type`=1); -- Hornwood Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2505 AND `ExtendedCost`=0 AND `type`=1); -- Polished Shortbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2504 AND `ExtendedCost`=0 AND `type`=1); -- Worn Shortbow
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17101 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17101 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17101 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17101 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17246 AND `item`=21219 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Sagefish Delight
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17246 AND `item`=21099 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Smoked Sagefish
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17246 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17246 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17246 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18427 AND `item`=22647 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Crunchy Spider Surprise
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15809 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Crossbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15808 AND `ExtendedCost`=0 AND `type`=1); -- Fine Light Crossbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=15807 AND `ExtendedCost`=0 AND `type`=1); -- Light Crossbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=3027 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2507 AND `ExtendedCost`=0 AND `type`=1); -- Laminated Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2506 AND `ExtendedCost`=0 AND `type`=1); -- Hornwood Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2505 AND `ExtendedCost`=0 AND `type`=1); -- Polished Shortbow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17667 AND `item`=2504 AND `ExtendedCost`=0 AND `type`=1); -- Worn Shortbow
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17666 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=5048 AND `ExtendedCost`=0 AND `type`=1); -- Blue Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18811 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1); -- Striped Yellowtail
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1); -- Rockscale Cod
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1); -- Bristle Whisker Catfish
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1); -- Longjaw Mud Snapper
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1); -- Slitherskin Mackerel
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17553 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=21145 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple

DELETE FROM `npc_vendor` WHERE (`entry`=17489 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17489 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17489 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17490 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17490 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17490 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17446 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17222 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17222 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18810 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18810 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17486 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17486 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=17486 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4301 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4300 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4299 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4298 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4297 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4296 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4295 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4294 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4293 AND `type`=1) OR (`entry`=63077 AND `item`=98715 AND `ExtendedCost`=4292 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(17489, 10, 4542, 0, 0, 1, 0, 0, 26124), -- Moist Cornbread
(17489, 8, 4541, 0, 0, 1, 0, 0, 26124), -- Freshly Baked Bread
(17489, 2, 4540, 0, 0, 1, 0, 0, 26124), -- Tough Hunk of Bread
(17490, 19, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(17490, 18, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(17490, 3, 85663, 0, 0, 1, 0, 0, 26124), -- Herbalist's Spade
(17446, 2, 4540, 0, 0, 1, 0, 0, 26124), -- Tough Hunk of Bread
(17222, 1163, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(17222, 1151, 90146, 0, 0, 1, 0, 0, 26124), -- Tinker's Kit
(18810, 4, 4541, 0, 0, 1, 0, 0, 26124), -- Freshly Baked Bread
(18810, 3, 4540, 0, 0, 1, 0, 0, 26124), -- Tough Hunk of Bread
(17486, 29, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(17486, 5, 85663, 0, 0, 1, 0, 0, 26124), -- Herbalist's Spade
(17486, 2, 52188, 0, 0, 1, 0, 0, 26124), -- Jeweler's Setting
(63077, 10, 98715, 0, 4301, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 9, 98715, 0, 4300, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 8, 98715, 0, 4299, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 7, 98715, 0, 4298, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 6, 98715, 0, 4297, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 5, 98715, 0, 4296, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 4, 98715, 0, 4295, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 3, 98715, 0, 4294, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 2, 98715, 0, 4293, 1, 0, 0, 26124), -- Marked Flawless Battle-Stone
(63077, 1, 98715, 0, 4292, 1, 0, 0, 26124); -- Marked Flawless Battle-Stone

UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=5048 AND `ExtendedCost`=0 AND `type`=1); -- Blue Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17489 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17245 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17245 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17245 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17245 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17245 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17245 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17490 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17446 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17446 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17446 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17446 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17446 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16553 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=17485 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=1162, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=1161, `maxcount`=3, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=1160, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=4382 AND `ExtendedCost`=0 AND `type`=1); -- Bronze Framework
UPDATE `npc_vendor` SET `slot`=1159, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=4389 AND `ExtendedCost`=0 AND `type`=1); -- Gyrochronatom
UPDATE `npc_vendor` SET `slot`=1158, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=1157, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=1156, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=1155, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=1154, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=1153, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=1152, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=1150, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1149, `VerifiedBuild`=26124 WHERE (`entry`=17222 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=119, `VerifiedBuild`=26124 WHERE (`entry`=18810 AND `item`=929 AND `ExtendedCost`=0 AND `type`=1); -- Healing Potion
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=18810 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=18810 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=18810 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=18810 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=18810 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=18810 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17486 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=16, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2493 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Mallet
UPDATE `npc_vendor` SET `slot`=15, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2490 AND `ExtendedCost`=0 AND `type`=1); -- Tomahawk
UPDATE `npc_vendor` SET `slot`=14, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2488 AND `ExtendedCost`=0 AND `type`=1); -- Gladius
UPDATE `npc_vendor` SET `slot`=13, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2495 AND `ExtendedCost`=0 AND `type`=1); -- Walking Stick
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2494 AND `ExtendedCost`=0 AND `type`=1); -- Stiletto
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2491 AND `ExtendedCost`=0 AND `type`=1); -- Large Axe
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2492 AND `ExtendedCost`=0 AND `type`=1); -- Cudgel
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2489 AND `ExtendedCost`=0 AND `type`=1); -- Two-Handed Sword
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=1201 AND `ExtendedCost`=0 AND `type`=1); -- Dull Heater Shield
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=17186 AND `ExtendedCost`=0 AND `type`=1); -- Small Targe
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2397 AND `ExtendedCost`=0 AND `type`=1); -- Light Mail Gloves
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2396 AND `ExtendedCost`=0 AND `type`=1); -- Light Mail Bracers
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2395 AND `ExtendedCost`=0 AND `type`=1); -- Light Mail Boots
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2394 AND `ExtendedCost`=0 AND `type`=1); -- Light Mail Leggings
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2393 AND `ExtendedCost`=0 AND `type`=1); -- Light Mail Belt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=17930 AND `item`=2392 AND `ExtendedCost`=0 AND `type`=1); -- Light Mail Armor
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=797 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Gloves
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=1840 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Bracers
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=796 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Boots
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=798 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Pants
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=1839 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Belt
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=799 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Vest
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=793 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Gloves
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=3603 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Bracers
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=792 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Sandals
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=794 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Pants
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=3602 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Belt
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=17929 AND `item`=795 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Tunic
UPDATE `npc_vendor` SET `slot`=500, `VerifiedBuild`=26124 WHERE (`entry`=17101 AND `item`=6533 AND `ExtendedCost`=0 AND `type`=1); -- Aquadynamic Fish Attractor
UPDATE `npc_vendor` SET `slot`=499 WHERE (`entry`=17101 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=498 WHERE (`entry`=17101 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=497 WHERE (`entry`=17101 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=496 WHERE (`entry`=17101 AND `item`=136377 AND `ExtendedCost`=0 AND `type`=1); -- Oversized Bobber
UPDATE `npc_vendor` SET `slot`=495 WHERE (`entry`=17101 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=2132 AND `ExtendedCost`=0 AND `type`=1); -- Short Staff
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=2139 AND `ExtendedCost`=0 AND `type`=1); -- Dirk
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=2480 AND `ExtendedCost`=0 AND `type`=1); -- Large Club
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=2130 AND `ExtendedCost`=0 AND `type`=1); -- Club
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=2479 AND `ExtendedCost`=0 AND `type`=1); -- Broad Axe
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=2134 AND `ExtendedCost`=0 AND `type`=1); -- Hand Axe
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=1194 AND `ExtendedCost`=0 AND `type`=1); -- Bastard Sword
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=2131 AND `ExtendedCost`=0 AND `type`=1); -- Shortsword
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=15809 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Crossbow
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=15808 AND `ExtendedCost`=0 AND `type`=1); -- Fine Light Crossbow
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16919 AND `item`=15807 AND `ExtendedCost`=0 AND `type`=1); -- Light Crossbow
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=16920 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16920 AND `item`=20857 AND `ExtendedCost`=0 AND `type`=1); -- Honey Bread
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2125 AND `ExtendedCost`=0 AND `type`=1); -- Cracked Leather Gloves
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2124 AND `ExtendedCost`=0 AND `type`=1); -- Cracked Leather Bracers
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2123 AND `ExtendedCost`=0 AND `type`=1); -- Cracked Leather Boots
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2126 AND `ExtendedCost`=0 AND `type`=1); -- Cracked Leather Pants
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2122 AND `ExtendedCost`=0 AND `type`=1); -- Cracked Leather Belt
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2127 AND `ExtendedCost`=0 AND `type`=1); -- Cracked Leather Vest
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2119 AND `ExtendedCost`=0 AND `type`=1); -- Thin Cloth Gloves
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=3600 AND `ExtendedCost`=0 AND `type`=1); -- Thin Cloth Bracers
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2117 AND `ExtendedCost`=0 AND `type`=1); -- Thin Cloth Shoes
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2120 AND `ExtendedCost`=0 AND `type`=1); -- Thin Cloth Pants
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=3599 AND `ExtendedCost`=0 AND `type`=1); -- Thin Cloth Belt
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=16918 AND `item`=2121 AND `ExtendedCost`=0 AND `type`=1); -- Thin Cloth Armor
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=2129 AND `ExtendedCost`=0 AND `type`=1); -- Large Round Shield
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=17184 AND `ExtendedCost`=0 AND `type`=1); -- Small Shield
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=2385 AND `ExtendedCost`=0 AND `type`=1); -- Tarnished Chain Gloves
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=2384 AND `ExtendedCost`=0 AND `type`=1); -- Tarnished Chain Bracers
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=2383 AND `ExtendedCost`=0 AND `type`=1); -- Tarnished Chain Boots
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=2380 AND `ExtendedCost`=0 AND `type`=1); -- Tarnished Chain Belt
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=2381 AND `ExtendedCost`=0 AND `type`=1); -- Tarnished Chain Leggings
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=16917 AND `item`=2379 AND `ExtendedCost`=0 AND `type`=1); -- Tarnished Chain Vest

DELETE FROM `npc_vendor` WHERE (`entry`=15175 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15175 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15722 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15179 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15179 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15179 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15419 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15174 AND `item`=13496 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15174 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15174 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=15174 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(15175, 2, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(15175, 1, 64670, 0, 0, 1, 0, 0, 26124), -- Vanishing Powder
(15722, 1, 37460, 0, 0, 1, 0, 0, 26124), -- Rope Pet Leash
(15179, 35, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(15179, 34, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(15179, 10, 85663, 0, 0, 1, 0, 0, 26124), -- Herbalist's Spade
(15419, 2854, 38682, 0, 0, 1, 0, 0, 26124), -- Enchanting Vellum
(15174, 3281, 13496, 1, 0, 1, 0, 0, 26124), -- Recipe: Greater Nature Protection Potion
(15174, 19, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(15174, 17, 4601, 0, 0, 1, 0, 0, 26124), -- Soft Banana Bread
(15174, 16, 4542, 0, 0, 1, 0, 0, 26124); -- Moist Cornbread

UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5483 AND `item`=21219 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Sagefish Delight
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5483 AND `item`=21099 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Smoked Sagefish
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5483 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5483 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5483 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6274 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blue Overalls
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6274 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blue Overalls
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6274 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blue Overalls
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6274 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blue Overalls
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10325 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: White Wedding Dress
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6274 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blue Overalls
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10325 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: White Wedding Dress
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10325 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: White Wedding Dress
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10325 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: White Wedding Dress
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10325 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: White Wedding Dress
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10325 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: White Wedding Dress
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54605 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Illusionary Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54602 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Dreamless Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54603 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Breeches of Mended Nightmares
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54601 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Belt of the Depths
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54604 AND `ExtendedCost`=2989 AND `type`=1); -- Pattern: Flame-Ascended Pantaloons
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54598 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54597 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54596 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Fireweave Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54595 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54594 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54593 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Vicious Embersilk Cowl
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54599 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Enchanted Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=54600 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Powerful Ghostly Spellthread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=68199 AND `ExtendedCost`=2988 AND `type`=1); -- Pattern: Black Embersilk Gown
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10325 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: White Wedding Dress
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=1347 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=855, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=21952 AND `ExtendedCost`=0 AND `type`=1); -- Design: Emerald Crown of Destruction
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=22312 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Satchel of Cenarius
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=22310 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Cenarion Herb Bag
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=22683 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Gaea's Embrace
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=22774 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Sylvan Vest
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=22773 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Sylvan Crown
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=15179 AND `item`=22772 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Sylvan Shoulders
UPDATE `npc_vendor` SET `slot`=2863, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=2862, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=2861, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=2860, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=2859, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=2858, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=2857, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=2856, `maxcount`=4, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=2855, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=22308 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Runecloth Bag
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=20755 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Wizard Oil
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=15419 AND `item`=20754 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Mana Oil
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=15174 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=22766 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Ironvine Breastplate
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=22767 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Ironvine Gloves
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=22768 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Ironvine Belt
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=22214 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Light Obsidian Belt
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=22209 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Heavy Obsidian Belt
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=15176 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=176, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=15724 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Scorpid Bracers
UPDATE `npc_vendor` SET `slot`=175, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=15762 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Heavy Scorpid Helm
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=26124 WHERE (`entry`=12956 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife

DELETE FROM `npc_vendor` WHERE (`entry`=38561 AND `item`=3890 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2469 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2468 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2467 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2465 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2464 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2463 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=3889 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2434 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=3594 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2432 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2431 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=3593 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=2429 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=12706 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=12719 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=12714 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38561 AND `item`=12707 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=12959 AND `item`=15772 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=12959 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=12959 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=12959 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(38561, 18, 3890, 0, 0, 1, 0, 0, 26124), -- Studded Hat
(38561, 17, 2469, 0, 0, 1, 0, 0, 26124), -- Studded Gloves
(38561, 16, 2468, 0, 0, 1, 0, 0, 26124), -- Studded Bracers
(38561, 15, 2467, 0, 0, 1, 0, 0, 26124), -- Studded Boots
(38561, 14, 2465, 0, 0, 1, 0, 0, 26124), -- Studded Pants
(38561, 13, 2464, 0, 0, 1, 0, 0, 26124), -- Studded Belt
(38561, 12, 2463, 0, 0, 1, 0, 0, 26124), -- Studded Doublet
(38561, 11, 3889, 0, 0, 1, 0, 0, 26124), -- Russet Hat
(38561, 10, 2434, 0, 0, 1, 0, 0, 26124), -- Russet Gloves
(38561, 9, 3594, 0, 0, 1, 0, 0, 26124), -- Russet Bracers
(38561, 8, 2432, 0, 0, 1, 0, 0, 26124), -- Russet Boots
(38561, 7, 2431, 0, 0, 1, 0, 0, 26124), -- Russet Pants
(38561, 6, 3593, 0, 0, 1, 0, 0, 26124), -- Russet Belt
(38561, 5, 2429, 0, 0, 1, 0, 0, 26124), -- Russet Vest
(38561, 4, 12706, 0, 0, 1, 0, 0, 26124), -- Plans: Runic Plate Shoulders
(38561, 3, 12719, 0, 0, 1, 0, 0, 26124), -- Plans: Runic Plate Leggings
(38561, 2, 12714, 0, 0, 1, 0, 0, 26124), -- Plans: Runic Plate Helm
(38561, 1, 12707, 0, 0, 1, 0, 0, 26124), -- Plans: Runic Plate Boots
(12959, 45, 15772, 1, 0, 1, 0, 0, 26124), -- Pattern: Devilsaur Leggings
(12959, 18, 4499, 0, 0, 1, 0, 0, 26124), -- Huge Brown Sack
(12959, 16, 4601, 0, 0, 1, 0, 0, 26124), -- Soft Banana Bread
(12959, 15, 4542, 0, 0, 1, 0, 0, 26124); -- Moist Cornbread

UPDATE `npc_vendor` SET `slot`=16, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `slot`=15, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `slot`=14, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `slot`=13, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1); -- War Staff
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1); -- Battle Staff
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1); -- War Maul
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1); -- War Hammer
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1); -- Morning Star
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1); -- Truncheon
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `slot`=16, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `slot`=15, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `slot`=14, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `slot`=13, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1); -- War Staff
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1); -- Battle Staff
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1); -- War Maul
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1); -- War Hammer
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1); -- Morning Star
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1); -- Truncheon
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `slot`=44, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=15758 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Devilsaur Gauntlets
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=12959 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=16, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `slot`=15, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `slot`=14, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `slot`=13, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1); -- War Staff
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1); -- Battle Staff
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1); -- War Maul
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1); -- War Hammer
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1); -- Morning Star
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1); -- Truncheon
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `slot`=16, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `slot`=15, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `slot`=14, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `slot`=13, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1); -- War Staff
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1); -- Battle Staff
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1); -- War Maul
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1); -- War Hammer
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1); -- Morning Star
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1); -- Truncheon
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=3000 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe

DELETE FROM `npc_vendor` WHERE (`entry`=20081 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20081 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20081 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20081 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=20081 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(20081, 8, 39505, 0, 0, 1, 0, 0, 26124), -- Virtuoso Inking Set
(20081, 7, 20815, 0, 0, 1, 0, 0, 26124), -- Jeweler's Kit
(20081, 6, 39354, 0, 0, 1, 0, 0, 26124), -- Light Parchment
(20081, 2, 4565, 0, 0, 1, 0, 0, 26124), -- Simple Dagger
(20081, 1, 64670, 0, 0, 1, 0, 0, 26124); -- Vanishing Powder

UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40815 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40826 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44417 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=38714 AND `item`=4600 AND `ExtendedCost`=0 AND `type`=1); -- Cherry Grog
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=38714 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=38714 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=38714 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=38714 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=38714 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=38714 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18542 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18542 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18542 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18542 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=18542 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20082 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20082 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20082 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20082 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20082 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20082 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=20081 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=20081 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20081 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=20081 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=20081 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=20081 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=30744 AND `ExtendedCost`=0 AND `type`=1); -- Draenic Leather Pack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=27855 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Grainbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=27860 AND `ExtendedCost`=0 AND `type`=1); -- Purified Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=28399 AND `ExtendedCost`=0 AND `type`=1); -- Filtered Draenic Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=29448 AND `ExtendedCost`=0 AND `type`=1); -- Mag'har Mild Cheese
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=27857 AND `ExtendedCost`=0 AND `type`=1); -- Garadar Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=20080 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=35346 AND `ExtendedCost`=0 AND `type`=1); -- Evoker's Silk Raiment
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=31777 AND `ExtendedCost`=0 AND `type`=1); -- Keepers of Time Tabard
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=29183 AND `ExtendedCost`=0 AND `type`=1); -- Bindings of the Timewalker
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=29181 AND `ExtendedCost`=0 AND `type`=1); -- Timelapse Shard
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=29182 AND `ExtendedCost`=0 AND `type`=1); -- Riftmaker
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=33152 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Gloves - Superior Agility
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=31355 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Flask of Supreme Power
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=29185 AND `ExtendedCost`=0 AND `type`=1); -- Continuum Blade
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=29184 AND `ExtendedCost`=0 AND `type`=1); -- Timewarden's Leggings
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=33158 AND `ExtendedCost`=0 AND `type`=1); -- Design: Stone of Blades
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=24174 AND `ExtendedCost`=0 AND `type`=1); -- Design: Pendant of Frozen Flame
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=24181 AND `ExtendedCost`=0 AND `type`=1); -- Design: Living Ruby Serpent
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=28272 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Gloves - Major Spellpower
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=29713 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Drums of Panic
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=33160 AND `ExtendedCost`=0 AND `type`=1); -- Design: Facet of Eternity
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=21643 AND `item`=25910 AND `ExtendedCost`=0 AND `type`=1); -- Design: Enigmatic Skyfire Diamond
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=44398 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=43418 AND `item`=8529 AND `ExtendedCost`=0 AND `type`=1); -- Noggenfogger Elixir

DELETE FROM `npc_vendor` WHERE (`entry`=23896 AND `item`=63656 AND `type`=1) OR (`entry`=20278 AND `item`=64734 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64732 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64723 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64725 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64724 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64863 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=20278 AND `item`=64862 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=20278 AND `item`=64864 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=20278 AND `item`=64721 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64720 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64722 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=20278 AND `item`=64853 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=20278 AND `item`=64857 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=20278 AND `item`=64854 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=20278 AND `item`=64855 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=20278 AND `item`=64856 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=20278 AND `item`=146437 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=40216 AND `item`=61359 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=61360 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=61361 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=61358 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=61357 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=61346 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61339 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61326 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61344 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61336 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61332 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61333 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61325 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61350 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61351 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61342 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61341 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61338 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61329 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61343 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61340 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61354 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61355 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61353 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61345 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61335 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61331 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61330 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61328 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61327 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=61324 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=40216 AND `item`=60787 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60786 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60635 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60634 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60628 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60636 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=60630 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=60613 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=60637 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60626 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60612 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=40216 AND `item`=60467 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=60466 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=40216 AND `item`=60465 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=40216 AND `item`=60464 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=40216 AND `item`=60463 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=40216 AND `item`=146641 AND `ExtendedCost`=5981 AND `type`=1) OR (`entry`=40216 AND `item`=146537 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=69323 AND `item`=70241 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70242 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70243 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70240 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70239 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70231 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70224 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70213 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70229 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70222 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70219 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70220 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70212 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70227 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70226 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70234 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70235 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70223 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70216 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70228 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70225 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70237 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70238 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70236 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70230 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70221 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70218 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70217 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70215 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70214 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70211 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69323 AND `item`=70388 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70387 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70366 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70365 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70363 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70361 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70364 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70367 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70368 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70362 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70360 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69323 AND `item`=70303 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70301 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=69323 AND `item`=70300 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=69323 AND `item`=70299 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69323 AND `item`=70302 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=69323 AND `item`=146640 AND `ExtendedCost`=5981 AND `type`=1) OR (`entry`=69323 AND `item`=146517 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=69322 AND `item`=73446 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73468 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73458 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73465 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73469 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73475 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73476 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73477 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73447 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73448 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73451 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73452 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73449 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73457 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73466 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73464 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73450 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73459 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73467 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73462 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73456 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73460 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73463 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73470 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73472 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73473 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73453 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73454 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73461 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73455 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73474 AND `ExtendedCost`=5966 AND `type`=1) OR (`entry`=69322 AND `item`=73630 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73629 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73632 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73633 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73631 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73635 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73636 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73634 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73639 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73638 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73637 AND `ExtendedCost`=5962 AND `type`=1) OR (`entry`=69322 AND `item`=73572 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73574 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=69322 AND `item`=73575 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=69322 AND `item`=73576 AND `ExtendedCost`=5963 AND `type`=1) OR (`entry`=69322 AND `item`=73573 AND `ExtendedCost`=5964 AND `type`=1) OR (`entry`=69322 AND `item`=146639 AND `ExtendedCost`=5981 AND `type`=1) OR (`entry`=69322 AND `item`=146457 AND `ExtendedCost`=6012 AND `type`=1) OR (`entry`=5594 AND `item`=6057 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=43964 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(23896,116,63656, 1, 0, 1, 0, 0, 26124), 
(20278, 140, 64734, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Drape of Prowess
(20278, 139, 64732, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Drape of Diffusion
(20278, 135, 64723, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Cuffs of Accuracy
(20278, 134, 64725, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Cuffs of Prowess
(20278, 133, 64724, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Cuffs of Meditation
(20278, 122, 64863, 0, 5963, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Treads of Cruelty
(20278, 121, 64862, 0, 5963, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Treads of Alacrity
(20278, 120, 64864, 0, 5963, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Treads of Meditation
(20278, 107, 64721, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Cord of Cruelty
(20278, 106, 64720, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Cord of Accuracy
(20278, 105, 64722, 0, 5962, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Cord of Meditation
(20278, 90, 64853, 0, 5963, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Silk Amice
(20278, 89, 64857, 0, 5964, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Silk Trousers
(20278, 88, 64854, 0, 5964, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Silk Cowl
(20278, 87, 64855, 0, 5963, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Silk Handguards
(20278, 86, 64856, 0, 5964, 1, 0, 0, 26124), -- Bloodthirsty Gladiator's Silk Robe
(20278, 10, 146437, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Bloodthirsty Gladiator's Silk Armor
(40216, 174, 61359, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Shield Wall
(40216, 173, 61360, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Barrier
(40216, 172, 61361, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Redoubt
(40216, 171, 61358, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Reprieve
(40216, 170, 61357, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Endgame
(40216, 169, 61346, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Greatsword
(40216, 168, 61339, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Bonegrinder
(40216, 167, 61326, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Decapitator
(40216, 166, 61344, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Slicer
(40216, 165, 61336, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Bonecracker
(40216, 164, 61332, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Slasher
(40216, 163, 61333, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Right Render
(40216, 162, 61325, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Hacker
(40216, 161, 61350, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Touch of Defeat
(40216, 160, 61351, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Baton of Light
(40216, 159, 61342, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Energy Staff
(40216, 158, 61341, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Battle Staff
(40216, 157, 61338, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Gavel
(40216, 156, 61329, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Spellblade
(40216, 155, 61343, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Staff
(40216, 154, 61340, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Pike
(40216, 153, 61354, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Rifle
(40216, 152, 61355, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Heavy Crossbow
(40216, 151, 61353, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Longbow
(40216, 150, 61345, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Quickblade
(40216, 149, 61335, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Pummeler
(40216, 148, 61331, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Fleshslicer
(40216, 147, 61330, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Ripper
(40216, 146, 61328, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Shiv
(40216, 145, 61327, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Shanker
(40216, 144, 61324, 0, 5966, 1, 0, 0, 26124), -- Vicious Gladiator's Cleaver
(40216, 142, 60787, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Drape of Prowess
(40216, 141, 60786, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Drape of Diffusion
(40216, 136, 60635, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Cuffs of Meditation
(40216, 135, 60634, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Cuffs of Prowess
(40216, 134, 60628, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Cuffs of Accuracy
(40216, 121, 60636, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Treads of Meditation
(40216, 120, 60630, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Treads of Alacrity
(40216, 119, 60613, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Treads of Cruelty
(40216, 97, 60637, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Cord of Meditation
(40216, 96, 60626, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Cord of Accuracy
(40216, 95, 60612, 0, 5962, 1, 0, 0, 26124), -- Vicious Gladiator's Cord of Cruelty
(40216, 76, 60467, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Silk Amice
(40216, 75, 60466, 0, 5964, 1, 0, 0, 26124), -- Vicious Gladiator's Silk Robe
(40216, 74, 60465, 0, 5964, 1, 0, 0, 26124), -- Vicious Gladiator's Silk Trousers
(40216, 73, 60464, 0, 5964, 1, 0, 0, 26124), -- Vicious Gladiator's Silk Cowl
(40216, 72, 60463, 0, 5963, 1, 0, 0, 26124), -- Vicious Gladiator's Silk Handguards
(40216, 11, 146641, 0, 5981, 1, 0, 0, 26124), -- Arsenal: Vicious Gladiator's Weapons
(40216, 10, 146537, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Vicious Gladiator's Silk Armor
(69323, 174, 70241, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Shield Wall
(69323, 173, 70242, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Barrier
(69323, 172, 70243, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Redoubt
(69323, 171, 70240, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Reprieve
(69323, 170, 70239, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Endgame
(69323, 169, 70231, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Greatsword
(69323, 168, 70224, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Bonegrinder
(69323, 167, 70213, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Decapitator
(69323, 166, 70229, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Slicer
(69323, 165, 70222, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Bonecracker
(69323, 164, 70219, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Slasher
(69323, 163, 70220, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Right Render
(69323, 162, 70212, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Hacker
(69323, 161, 70227, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Energy Staff
(69323, 160, 70226, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Battle Staff
(69323, 159, 70234, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Touch of Defeat
(69323, 158, 70235, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Baton of Light
(69323, 157, 70223, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Gavel
(69323, 156, 70216, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Spellblade
(69323, 155, 70228, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Staff
(69323, 154, 70225, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Pike
(69323, 153, 70237, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Rifle
(69323, 152, 70238, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Heavy Crossbow
(69323, 151, 70236, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Longbow
(69323, 150, 70230, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Quickblade
(69323, 149, 70221, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Pummeler
(69323, 148, 70218, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Fleshslicer
(69323, 147, 70217, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Ripper
(69323, 146, 70215, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Shiv
(69323, 145, 70214, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Shanker
(69323, 144, 70211, 0, 5966, 1, 0, 0, 26124), -- Ruthless Gladiator's Cleaver
(69323, 142, 70388, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Drape of Prowess
(69323, 141, 70387, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Drape of Diffusion
(69323, 136, 70366, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Cuffs of Meditation
(69323, 135, 70365, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Cuffs of Prowess
(69323, 134, 70363, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Cuffs of Accuracy
(69323, 120, 70361, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Treads of Cruelty
(69323, 119, 70364, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Treads of Alacrity
(69323, 118, 70367, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Treads of Meditation
(69323, 106, 70368, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Cord of Meditation
(69323, 105, 70362, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Cord of Accuracy
(69323, 104, 70360, 0, 5962, 1, 0, 0, 26124), -- Ruthless Gladiator's Cord of Cruelty
(69323, 71, 70303, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Silk Amice
(69323, 70, 70301, 0, 5964, 1, 0, 0, 26124), -- Ruthless Gladiator's Silk Trousers
(69323, 69, 70300, 0, 5964, 1, 0, 0, 26124), -- Ruthless Gladiator's Silk Cowl
(69323, 68, 70299, 0, 5963, 1, 0, 0, 26124), -- Ruthless Gladiator's Silk Handguards
(69323, 67, 70302, 0, 5964, 1, 0, 0, 26124), -- Ruthless Gladiator's Silk Robe
(69323, 11, 146640, 0, 5981, 1, 0, 0, 26124), -- Arsenal: Ruthless Gladiator's Weapons
(69323, 10, 146517, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Ruthless Gladiator's Silk Armor
(69322, 175, 73446, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Shield Wall
(69322, 174, 73468, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Barrier
(69322, 173, 73458, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Redoubt
(69322, 172, 73465, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Reprieve
(69322, 171, 73469, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Endgame
(69322, 170, 73475, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Greatsword
(69322, 169, 73476, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Bonegrinder
(69322, 168, 73477, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Decapitator
(69322, 167, 73447, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Slicer
(69322, 166, 73448, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Bonecracker
(69322, 165, 73451, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Slasher
(69322, 164, 73452, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Right Render
(69322, 163, 73449, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Hacker
(69322, 162, 73457, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Energy Staff
(69322, 161, 73466, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Battle Staff
(69322, 160, 73464, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Touch of Defeat
(69322, 159, 73450, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Baton of Light
(69322, 158, 73459, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Gavel
(69322, 157, 73467, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Spellblade
(69322, 156, 73462, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Staff
(69322, 155, 73456, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Pike
(69322, 154, 73460, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Rifle
(69322, 153, 73463, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Heavy Crossbow
(69322, 152, 73470, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Longbow
(69322, 151, 73472, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Quickblade
(69322, 150, 73473, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Pummeler
(69322, 149, 73453, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Fleshslicer
(69322, 148, 73454, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Ripper
(69322, 147, 73461, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Shiv
(69322, 146, 73455, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Shanker
(69322, 145, 73474, 0, 5966, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Cleaver
(69322, 144, 73630, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Drape of Prowess
(69322, 143, 73629, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Drape of Diffusion
(69322, 125, 73632, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Cuffs of Prowess
(69322, 124, 73633, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Cuffs of Accuracy
(69322, 123, 73631, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Cuffs of Meditation
(69322, 122, 73635, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Treads of Alacrity
(69322, 121, 73636, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Treads of Cruelty
(69322, 120, 73634, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Treads of Meditation
(69322, 95, 73639, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Cord of Cruelty
(69322, 94, 73638, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Cord of Accuracy
(69322, 93, 73637, 0, 5962, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Cord of Meditation
(69322, 16, 73572, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Silk Amice
(69322, 15, 73574, 0, 5964, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Silk Trousers
(69322, 14, 73575, 0, 5964, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Silk Cowl
(69322, 13, 73576, 0, 5963, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Silk Handguards
(69322, 12, 73573, 0, 5964, 1, 0, 0, 26124), -- Cataclysmic Gladiator's Silk Robe
(69322, 11, 146639, 0, 5981, 1, 0, 0, 26124), -- Arsenal: Cataclysmic Gladiator's Weapons
(69322, 10, 146457, 0, 6012, 1, 0, 0, 26124), -- Ensemble: Cataclysmic Gladiator's Silk Armor
(5594, 275, 6057, 1, 0, 1, 0, 0, 26124), -- Recipe: Nature Protection Potion
(43964, 1, 64670, 0, 0, 1, 0, 0, 26124); -- Vanishing Powder

UPDATE `npc_vendor` SET `slot`=274, `VerifiedBuild`=26124 WHERE (`entry`=5594 AND `item`=12958 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Arcanite
UPDATE `npc_vendor` SET `slot`=273, `VerifiedBuild`=26124 WHERE (`entry`=5594 AND `item`=9305 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Mithril to Truesilver
UPDATE `npc_vendor` SET `slot`=272, `VerifiedBuild`=26124 WHERE (`entry`=5594 AND `item`=9304 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Iron to Gold
UPDATE `npc_vendor` SET `slot`=271, `VerifiedBuild`=26124 WHERE (`entry`=5594 AND `item`=9303 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Philosopher's Stone
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5594 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=64, `VerifiedBuild`=26124 WHERE (`entry`=8131 AND `item`=18650 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: EZ-Thro Dynamite II
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=8131 AND `item`=3025 AND `ExtendedCost`=0 AND `type`=1); -- BKP 42 "Ultra"
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=8131 AND `item`=3024 AND `ExtendedCost`=0 AND `type`=1); -- BKP 2700 "Enforcer"
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=26124 WHERE (`entry`=8131 AND `item`=3023 AND `ExtendedCost`=0 AND `type`=1); -- Large Bore Blunderbuss
UPDATE `npc_vendor` SET `slot`=99, `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=21358 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Soul Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=529, `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=37915 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Dress Shoes
UPDATE `npc_vendor` SET `slot`=528, `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=38328 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Haliscan Pantaloons
UPDATE `npc_vendor` SET `slot`=527, `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=38327 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Haliscan Jacket
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40572 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=99, `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=21358 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Soul Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=6568 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2448 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Pavise
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=17189 AND `ExtendedCost`=0 AND `type`=1); -- Metal Buckler
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=3891 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2422 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2421 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2420 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2418 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2419 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2417 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2451 AND `ExtendedCost`=0 AND `type`=1); -- Crested Heater Shield
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=17190 AND `ExtendedCost`=0 AND `type`=1); -- Ornate Buckler
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=8092 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=8091 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=8090 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=8089 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=8093 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=8088 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=8094 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=3894 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2428 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2427 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2426 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2425 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2424 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=8129 AND `item`=2423 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5411 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5411 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5411 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5411 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5411 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=5411 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=18046 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Tender Wolf Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=40589 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=9985 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=18046 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Tender Wolf Steak
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=26124 WHERE (`entry`=7733 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky

DELETE FROM `npc_vendor` WHERE (`entry`=40554 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40554 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40554 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40554 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40554 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40554 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41135 AND `item`=11023 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(40554, 6, 3857, 0, 0, 1, 0, 0, 25996), -- Coal
(40554, 5, 18567, 0, 0, 1, 0, 0, 25996), -- Elemental Flux
(40554, 4, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(40554, 3, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(40554, 2, 5956, 0, 0, 1, 0, 0, 25996), -- Blacksmith Hammer
(40554, 1, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(41135, 1, 11023, 0, 0, 1, 0, 0, 25996); -- Ancona Chicken

UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=41452 AND `item`=3027 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=41452 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41452 AND `item`=3024 AND `ExtendedCost`=0 AND `type`=1); -- BKP 2700 "Enforcer"
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=41452 AND `item`=3023 AND `ExtendedCost`=0 AND `type`=1); -- Large Bore Blunderbuss
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=41452 AND `item`=2511 AND `ExtendedCost`=0 AND `type`=1); -- Hunter's Boomstick
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=41452 AND `item`=2509 AND `ExtendedCost`=0 AND `type`=1); -- Ornate Blunderbuss
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=47383 AND `item`=7228 AND `ExtendedCost`=0 AND `type`=1); -- Tigule and Foror's Strawberry Ice Cream
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=47383 AND `item`=7228 AND `ExtendedCost`=0 AND `type`=1); -- Tigule and Foror's Strawberry Ice Cream
UPDATE `npc_vendor` SET `slot`=100, `maxcount`=5, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=9260 AND `ExtendedCost`=0 AND `type`=1); -- Volatile Rum
UPDATE `npc_vendor` SET `slot`=99, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44574 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Mulgore Firewater
UPDATE `npc_vendor` SET `slot`=98, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `slot`=97, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=40042 AND `ExtendedCost`=0 AND `type`=1); -- Caraway Burnwine
UPDATE `npc_vendor` SET `slot`=96, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44573 AND `ExtendedCost`=0 AND `type`=1); -- Cup of Frog Venom Brew
UPDATE `npc_vendor` SET `slot`=95, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `slot`=94, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=40036 AND `ExtendedCost`=0 AND `type`=1); -- Snowplum Brandy
UPDATE `npc_vendor` SET `slot`=93, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44575 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Bitter Cactus Cider
UPDATE `npc_vendor` SET `slot`=92, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `slot`=91, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44571 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Silvermoon Port
UPDATE `npc_vendor` SET `slot`=90, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `slot`=89, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=40035 AND `ExtendedCost`=0 AND `type`=1); -- Northrend Honey Mead
UPDATE `npc_vendor` SET `slot`=88, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44570 AND `ExtendedCost`=0 AND `type`=1); -- Glass of Eversong Wine
UPDATE `npc_vendor` SET `slot`=87, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=54746 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Grog
UPDATE `npc_vendor` SET `slot`=100, `maxcount`=5, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=9260 AND `ExtendedCost`=0 AND `type`=1); -- Volatile Rum
UPDATE `npc_vendor` SET `slot`=99, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44574 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Mulgore Firewater
UPDATE `npc_vendor` SET `slot`=98, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `slot`=97, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=40042 AND `ExtendedCost`=0 AND `type`=1); -- Caraway Burnwine
UPDATE `npc_vendor` SET `slot`=96, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44573 AND `ExtendedCost`=0 AND `type`=1); -- Cup of Frog Venom Brew
UPDATE `npc_vendor` SET `slot`=95, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `slot`=94, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=40036 AND `ExtendedCost`=0 AND `type`=1); -- Snowplum Brandy
UPDATE `npc_vendor` SET `slot`=93, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44575 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Bitter Cactus Cider
UPDATE `npc_vendor` SET `slot`=92, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `slot`=91, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44571 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Silvermoon Port
UPDATE `npc_vendor` SET `slot`=90, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `slot`=89, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=40035 AND `ExtendedCost`=0 AND `type`=1); -- Northrend Honey Mead
UPDATE `npc_vendor` SET `slot`=88, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=44570 AND `ExtendedCost`=0 AND `type`=1); -- Glass of Eversong Wine
UPDATE `npc_vendor` SET `slot`=87, `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40832 AND `item`=54746 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Grog

DELETE FROM `npc_vendor` WHERE (`entry`=44283 AND `item`=4797 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44283 AND `item`=4798 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44283 AND `item`=4799 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44301 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44280 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44347 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44304 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44302 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44279 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44279 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44279 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44279 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44279 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44279 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=38873 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44268 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44348 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44303 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44283 AND `item`=4816 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44283 AND `item`=4800 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44307 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44277 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44294 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=82344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=83094 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=82343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=83095 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44299 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44346 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44219 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(44283, 116, 4797, 1, 0, 1, 0, 0, 25996),
(44283, 117, 4798, 1, 0, 1, 0, 0, 25996),
(44283, 118, 4799, 1, 0, 1, 0, 0, 25996),
(44301, 20, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(44301, 19, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(44301, 18, 39354, 0, 0, 1, 0, 0, 25996), -- Light Parchment
(44301, 17, 6532, 0, 0, 1, 0, 0, 25996), -- Bright Baubles
(44301, 16, 6530, 0, 0, 1, 0, 0, 25996), -- Nightcrawlers
(44301, 15, 4400, 0, 0, 1, 0, 0, 25996), -- Heavy Stock
(44301, 14, 4399, 0, 0, 1, 0, 0, 25996), -- Wooden Stock
(44301, 13, 4289, 0, 0, 1, 0, 0, 25996), -- Salt
(44301, 12, 3371, 0, 0, 1, 0, 0, 25996), -- Crystal Vial
(44301, 11, 2324, 0, 0, 1, 0, 0, 25996), -- Bleach
(44301, 10, 3857, 0, 0, 1, 0, 0, 25996), -- Coal
(44301, 9, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(44301, 8, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(44301, 7, 2678, 0, 0, 1, 0, 0, 25996), -- Mild Spices
(44301, 6, 4291, 0, 0, 1, 0, 0, 25996), -- Silken Thread
(44301, 5, 2321, 0, 0, 1, 0, 0, 25996), -- Fine Thread
(44301, 4, 2320, 0, 0, 1, 0, 0, 25996), -- Coarse Thread
(44301, 3, 6217, 0, 0, 1, 0, 0, 25996), -- Copper Rod
(44301, 2, 5956, 0, 0, 1, 0, 0, 25996), -- Blacksmith Hammer
(44301, 1, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(44280, 647, 39354, 0, 0, 1, 0, 0, 25996), -- Light Parchment
(44280, 646, 4364, 3, 0, 1, 0, 0, 25996), -- Coarse Blasting Powder
(44280, 645, 4357, 2, 0, 1, 0, 0, 25996), -- Rough Blasting Powder
(44280, 644, 10647, 0, 0, 1, 0, 0, 25996), -- Engineer's Ink
(44280, 643, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(44280, 642, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(44280, 641, 39684, 0, 0, 1, 0, 0, 25996), -- Hair Trigger
(44280, 640, 40533, 0, 0, 1, 0, 0, 25996), -- Walnut Stock
(44280, 639, 4400, 0, 0, 1, 0, 0, 25996), -- Heavy Stock
(44280, 638, 4399, 0, 0, 1, 0, 0, 25996), -- Wooden Stock
(44280, 637, 90146, 0, 0, 1, 0, 0, 25996), -- Tinker's Kit
(44280, 636, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(44280, 635, 5956, 0, 0, 1, 0, 0, 25996), -- Blacksmith Hammer
(44347, 1, 37460, 0, 0, 1, 0, 0, 25996), -- Rope Pet Leash
(44304, 8, 4470, 0, 0, 1, 0, 0, 25996), -- Simple Wood
(44304, 7, 4497, 0, 0, 1, 0, 0, 25996), -- Heavy Brown Bag
(44304, 6, 4498, 0, 0, 1, 0, 0, 25996), -- Brown Leather Satchel
(44304, 5, 4542, 0, 0, 1, 0, 0, 25996), -- Moist Cornbread
(44304, 4, 4541, 0, 0, 1, 0, 0, 25996), -- Freshly Baked Bread
(44304, 3, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(44304, 2, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(44304, 1, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44302, 9, 4470, 0, 0, 1, 0, 0, 25996), -- Simple Wood
(44302, 8, 4499, 0, 0, 1, 0, 0, 25996), -- Huge Brown Sack
(44302, 7, 4497, 0, 0, 1, 0, 0, 25996), -- Heavy Brown Bag
(44302, 6, 4601, 0, 0, 1, 0, 0, 25996), -- Soft Banana Bread
(44302, 5, 4542, 0, 0, 1, 0, 0, 25996), -- Moist Cornbread
(44302, 4, 1645, 0, 0, 1, 0, 0, 25996), -- Moonberry Juice
(44302, 3, 1708, 0, 0, 1, 0, 0, 25996), -- Sweet Nectar
(44302, 2, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(44302, 1, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44279, 6, 3857, 0, 0, 1, 0, 0, 25996), -- Coal
(44279, 5, 18567, 0, 0, 1, 0, 0, 25996), -- Elemental Flux
(44279, 4, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(44279, 3, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(44279, 2, 5956, 0, 0, 1, 0, 0, 25996), -- Blacksmith Hammer
(44279, 1, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(38873, 17, 10290, 0, 0, 1, 0, 0, 25996), -- Pink Dye
(38873, 16, 4342, 0, 0, 1, 0, 0, 25996), -- Purple Dye
(38873, 15, 6261, 0, 0, 1, 0, 0, 25996), -- Orange Dye
(38873, 14, 4341, 0, 0, 1, 0, 0, 25996), -- Yellow Dye
(38873, 13, 4340, 0, 0, 1, 0, 0, 25996), -- Gray Dye
(38873, 12, 2605, 0, 0, 1, 0, 0, 25996), -- Green Dye
(38873, 11, 2604, 0, 0, 1, 0, 0, 25996), -- Red Dye
(38873, 10, 6260, 0, 0, 1, 0, 0, 25996), -- Blue Dye
(38873, 9, 2325, 0, 0, 1, 0, 0, 25996), -- Black Dye
(38873, 8, 38426, 0, 0, 1, 0, 0, 25996), -- Eternium Thread
(38873, 7, 14341, 0, 0, 1, 0, 0, 25996), -- Rune Thread
(38873, 6, 8343, 0, 0, 1, 0, 0, 25996), -- Heavy Silken Thread
(38873, 5, 4291, 0, 0, 1, 0, 0, 25996), -- Silken Thread
(38873, 4, 2321, 0, 0, 1, 0, 0, 25996), -- Fine Thread
(38873, 3, 2320, 0, 0, 1, 0, 0, 25996), -- Coarse Thread
(38873, 2, 4289, 0, 0, 1, 0, 0, 25996), -- Salt
(38873, 1, 7005, 0, 0, 1, 0, 0, 25996), -- Skinning Knife
(44268, 12, 8932, 0, 0, 1, 0, 0, 25996), -- Alterac Swiss
(44268, 11, 3927, 0, 0, 1, 0, 0, 25996), -- Fine Aged Cheddar
(44268, 10, 1707, 0, 0, 1, 0, 0, 25996), -- Stormwind Brie
(44268, 9, 422, 0, 0, 1, 0, 0, 25996), -- Dwarven Mild
(44268, 8, 414, 0, 0, 1, 0, 0, 25996), -- Dalaran Sharp
(44268, 7, 2070, 0, 0, 1, 0, 0, 25996), -- Darnassian Bleu
(44268, 6, 8766, 0, 0, 1, 0, 0, 25996), -- Morning Glory Dew
(44268, 5, 1645, 0, 0, 1, 0, 0, 25996), -- Moonberry Juice
(44268, 4, 1708, 0, 0, 1, 0, 0, 25996), -- Sweet Nectar
(44268, 3, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(44268, 2, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(44268, 1, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44348, 1, 37460, 0, 0, 1, 0, 0, 25996), -- Rope Pet Leash
(44303, 8, 4470, 0, 0, 1, 0, 0, 25996), -- Simple Wood
(44303, 7, 4497, 0, 0, 1, 0, 0, 25996), -- Heavy Brown Bag
(44303, 6, 4498, 0, 0, 1, 0, 0, 25996), -- Brown Leather Satchel
(44303, 5, 4542, 0, 0, 1, 0, 0, 25996), -- Moist Cornbread
(44303, 4, 4541, 0, 0, 1, 0, 0, 25996), -- Freshly Baked Bread
(44303, 3, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(44303, 2, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(44303, 1, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44283, 120, 4816, 1, 0, 1, 0, 0, 25996), -- Legionnaire's Leggings
(44283, 119, 4800, 1, 0, 1, 0, 0, 25996), -- Mighty Chain Pants
(44307, 1, 3371, 0, 0, 1, 0, 0, 25996), -- Crystal Vial
(44277, 10, 2535, 0, 0, 1, 0, 1, 25996), -- War Staff
(44277, 9, 2527, 0, 0, 1, 0, 1, 25996), -- Battle Staff
(44277, 8, 2533, 0, 0, 1, 0, 1, 25996), -- War Maul
(44277, 7, 2525, 0, 0, 1, 0, 1, 25996), -- War Hammer
(44277, 6, 2532, 0, 0, 1, 0, 1, 25996), -- Morning Star
(44277, 5, 2524, 0, 0, 1, 0, 1, 25996), -- Truncheon
(44277, 4, 2534, 0, 0, 1, 0, 1, 25996), -- Rondel
(44277, 3, 2526, 0, 0, 1, 0, 1, 25996), -- Main Gauche
(44277, 2, 2528, 0, 0, 1, 0, 1, 25996), -- Falchion
(44277, 1, 2520, 0, 0, 1, 0, 1, 25996), -- Broadsword
(44294, 8, 4470, 0, 0, 1, 0, 0, 25996), -- Simple Wood
(44294, 7, 4497, 0, 0, 1, 0, 0, 25996), -- Heavy Brown Bag
(44294, 6, 4498, 0, 0, 1, 0, 0, 25996), -- Brown Leather Satchel
(44294, 5, 4542, 0, 0, 1, 0, 0, 25996), -- Moist Cornbread
(44294, 4, 4541, 0, 0, 1, 0, 0, 25996), -- Freshly Baked Bread
(44294, 3, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(44294, 2, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(44294, 1, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44299, 9, 82344, 0, 0, 1, 0, 0, 25996), -- Hearthglen Ambrosia
(44299, 8, 83094, 0, 0, 1, 0, 0, 25996), -- Foote Tripel
(44299, 7, 82343, 0, 0, 1, 0, 0, 25996), -- Lordaeron Lambic
(44299, 6, 83095, 0, 0, 1, 0, 0, 25996), -- Lagrave Stout
(44299, 5, 2595, 0, 0, 1, 0, 0, 25996), -- Jug of Badlands Bourbon
(44299, 4, 2594, 0, 0, 1, 0, 0, 25996), -- Flagon of Dwarven Mead
(44299, 3, 2596, 0, 0, 1, 0, 0, 25996), -- Skin of Dwarven Stout
(44299, 2, 2593, 0, 0, 1, 0, 0, 25996), -- Flask of Stormwind Tawny
(44299, 1, 2723, 0, 0, 1, 0, 0, 25996), -- Bottle of Dalaran Noir
(44346, 1, 37460, 0, 0, 1, 0, 0, 25996), -- Rope Pet Leash
(44219, 12, 8766, 0, 0, 1, 0, 0, 25996), -- Morning Glory Dew
(44219, 11, 1645, 0, 0, 1, 0, 0, 25996), -- Moonberry Juice
(44219, 10, 1708, 0, 0, 1, 0, 0, 25996), -- Sweet Nectar
(44219, 9, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(44219, 8, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(44219, 7, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44219, 6, 8950, 0, 0, 1, 0, 0, 25996), -- Homemade Cherry Pie
(44219, 5, 4601, 0, 0, 1, 0, 0, 25996), -- Soft Banana Bread
(44219, 4, 4544, 0, 0, 1, 0, 0, 25996), -- Mulgore Spice Bread
(44219, 3, 4542, 0, 0, 1, 0, 0, 25996), -- Moist Cornbread
(44219, 2, 4541, 0, 0, 1, 0, 0, 25996), -- Freshly Baked Bread
(44219, 1, 4540, 0, 0, 1, 0, 0, 25996); -- Tough Hunk of Bread

UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44267 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread

DELETE FROM `npc_vendor` WHERE (`entry`=41275 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41275 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41275 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41275 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41275 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41493 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41493 AND `item`=4361 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41493 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41490 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41490 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41490 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41490 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41490 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41053 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41053 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41053 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41053 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=41053 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=43021 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(41275, 40, 4565, 0, 0, 1, 0, 0, 25996), -- Simple Dagger
(41275, 39, 64670, 0, 0, 1, 0, 0, 25996), -- Vanishing Powder
(41275, 38, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(41275, 37, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(41275, 11, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(41493, 26, 39354, 0, 0, 1, 0, 0, 25996), -- Light Parchment
(41493, 23, 4361, 2, 0, 1, 0, 0, 25996), -- Bent Copper Tube
(41493, 16, 90146, 0, 0, 1, 0, 0, 25996), -- Tinker's Kit
(41490, 40, 4565, 0, 0, 1, 0, 0, 25996), -- Simple Dagger
(41490, 39, 64670, 0, 0, 1, 0, 0, 25996), -- Vanishing Powder
(41490, 38, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(41490, 37, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(41490, 11, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(41053, 40, 4565, 0, 0, 1, 0, 0, 25996), -- Simple Dagger
(41053, 39, 64670, 0, 0, 1, 0, 0, 25996), -- Vanishing Powder
(41053, 38, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(41053, 37, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(41053, 11, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(43021, 1, 37460, 0, 0, 1, 0, 0, 25996); -- Rope Pet Leash

UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41274 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41274 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41274 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41274 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41274 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41274 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41275 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41286 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=44177 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43019 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=25, `maxcount`=3, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=24, `maxcount`=4, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=4382 AND `ExtendedCost`=0 AND `type`=1); -- Bronze Framework
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41493 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41491 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41490 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43017 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=35, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41053 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=40898 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41054 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41054 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41054 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41054 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41054 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=41054 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick

DELETE FROM `npc_vendor` WHERE (`entry`=11188 AND `item`=20008 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50092 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=50094 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3779 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3779 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3779 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11185 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11185 AND `item`=4371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11185 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11189 AND `item`=15740 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11189 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11189 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11189 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=11188 AND `item`=3928 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(11188, 6, 20008, 2, 0, 1, 0, 0, 25996), -- Living Action Potion
(50092, 12, 8766, 0, 0, 1, 0, 0, 25996), -- Morning Glory Dew
(50092, 11, 1645, 0, 0, 1, 0, 0, 25996), -- Moonberry Juice
(50092, 10, 1708, 0, 0, 1, 0, 0, 25996), -- Sweet Nectar
(50092, 9, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(50092, 8, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(50092, 7, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(50092, 6, 8952, 0, 0, 1, 0, 0, 25996), -- Roasted Quail
(50092, 5, 4599, 0, 0, 1, 0, 0, 25996), -- Cured Ham Steak
(50092, 4, 3771, 0, 0, 1, 0, 0, 25996), -- Wild Hog Shank
(50092, 3, 3770, 0, 0, 1, 0, 0, 25996), -- Mutton Chop
(50092, 2, 2287, 0, 0, 1, 0, 0, 25996), -- Haunch of Meat
(50092, 1, 117, 0, 0, 1, 0, 0, 25996), -- Tough Jerky
(50094, 17, 10290, 0, 0, 1, 0, 0, 25996), -- Pink Dye
(50094, 16, 4342, 0, 0, 1, 0, 0, 25996), -- Purple Dye
(50094, 15, 6261, 0, 0, 1, 0, 0, 25996), -- Orange Dye
(50094, 14, 4341, 0, 0, 1, 0, 0, 25996), -- Yellow Dye
(50094, 13, 4340, 0, 0, 1, 0, 0, 25996), -- Gray Dye
(50094, 12, 2605, 0, 0, 1, 0, 0, 25996), -- Green Dye
(50094, 11, 2604, 0, 0, 1, 0, 0, 25996), -- Red Dye
(50094, 10, 6260, 0, 0, 1, 0, 0, 25996), -- Blue Dye
(50094, 9, 2325, 0, 0, 1, 0, 0, 25996), -- Black Dye
(50094, 8, 38426, 0, 0, 1, 0, 0, 25996), -- Eternium Thread
(50094, 7, 14341, 0, 0, 1, 0, 0, 25996), -- Rune Thread
(50094, 6, 8343, 0, 0, 1, 0, 0, 25996), -- Heavy Silken Thread
(50094, 5, 4291, 0, 0, 1, 0, 0, 25996), -- Silken Thread
(50094, 4, 2321, 0, 0, 1, 0, 0, 25996), -- Fine Thread
(50094, 3, 2320, 0, 0, 1, 0, 0, 25996), -- Coarse Thread
(50094, 2, 4289, 0, 0, 1, 0, 0, 25996), -- Salt
(50094, 1, 7005, 0, 0, 1, 0, 0, 25996), -- Skinning Knife
(3779, 28, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(3779, 27, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(3779, 3, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(11185, 70, 39354, 0, 0, 1, 0, 0, 25996), -- Light Parchment
(11185, 67, 4371, 1, 0, 1, 0, 0, 25996), -- Bronze Tube
(11185, 59, 90146, 0, 0, 1, 0, 0, 25996), -- Tinker's Kit
(11189, 60, 15740, 1, 0, 1, 0, 0, 25996), -- Pattern: Frostsaber Boots
(11189, 30, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(11189, 29, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(11189, 5, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(11188, 11, 3928, 1, 0, 1, 0, 0, 25996); -- Superior Healing Potion

UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=11188 AND `item`=20013 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Living Action Potion
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11188 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=21031 AND `ExtendedCost`=0 AND `type`=1); -- Cabbage Kimchi
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=21033 AND `ExtendedCost`=0 AND `type`=1); -- Radish Kimchi
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=21030 AND `ExtendedCost`=0 AND `type`=1); -- Darnassus Kimchi Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=16168 AND `ExtendedCost`=0 AND `type`=1); -- Heaven Peach
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=16169 AND `ExtendedCost`=0 AND `type`=1); -- Wild Ricecake
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=16170 AND `ExtendedCost`=0 AND `type`=1); -- Steamed Mandu
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=16167 AND `ExtendedCost`=0 AND `type`=1); -- Versicolor Treat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2303 AND `item`=16166 AND `ExtendedCost`=0 AND `type`=1); -- Bean Soup
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2084 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=3779 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=109, `VerifiedBuild`=25996 WHERE (`entry`=50129 AND `item`=12836 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Frostguard
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50129 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50129 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50129 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50129 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50129 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50129 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=50126 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=78, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=18652 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Gyrofreeze Ice Reflector
UPDATE `npc_vendor` SET `slot`=77, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=16046 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Masterwork Target Dummy
UPDATE `npc_vendor` SET `slot`=76, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=18656 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Powerful Seaforium Charge
UPDATE `npc_vendor` SET `slot`=75, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=16050 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Delicate Arcanite Converter
UPDATE `npc_vendor` SET `slot`=69, `maxcount`=2, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=68, `maxcount`=3, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=66, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=65, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=64, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=63, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=62, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=61, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=60, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=58, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=57, `VerifiedBuild`=25996 WHERE (`entry`=11185 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=16110 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Monster Omelet
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1); -- Striped Yellowtail
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1); -- Rockscale Cod
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1); -- Bristle Whisker Catfish
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1); -- Longjaw Mud Snapper
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1); -- Slitherskin Mackerel
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=11187 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=52830 AND `item`=69239 AND `ExtendedCost`=0 AND `type`=1); -- Winterspring Cub
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=52830 AND `item`=69239 AND `ExtendedCost`=0 AND `type`=1); -- Winterspring Cub
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=11118 AND `item`=22324 AND `ExtendedCost`=0 AND `type`=1); -- Winter Kimchi
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11186 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11186 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11186 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11186 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11186 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1); -- Mining Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11186 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=2451 AND `ExtendedCost`=0 AND `type`=1); -- Crested Heater Shield
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=17190 AND `ExtendedCost`=0 AND `type`=1); -- Ornate Buckler
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=8092 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=8091 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=8090 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=8089 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=8093 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=8088 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=8094 AND `ExtendedCost`=0 AND `type`=1); -- Platemail Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=3894 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=2428 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=2427 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=2426 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=2425 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=2424 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11182 AND `item`=2423 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=3893 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Cap
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2475 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2474 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2473 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2472 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2471 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2470 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=3892 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Hat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2440 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=3588 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2438 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2437 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=3587 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11183 AND `item`=2435 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Armor
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=3025 AND `ExtendedCost`=0 AND `type`=1); -- BKP 42 "Ultra"
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=3024 AND `ExtendedCost`=0 AND `type`=1); -- BKP 2700 "Enforcer"
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=3023 AND `ExtendedCost`=0 AND `type`=1); -- Large Bore Blunderbuss
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1); -- War Staff
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1); -- War Maul
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1); -- Morning Star
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11184 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `slot`=63, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=21957 AND `ExtendedCost`=0 AND `type`=1); -- Design: Necklace of the Diamond Tower
UPDATE `npc_vendor` SET `slot`=61, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=16221 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Chest - Major Health
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11189 AND `item`=14526 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Mooncloth
UPDATE `npc_vendor` SET `slot`=12, `maxcount`=2, `VerifiedBuild`=25996 WHERE (`entry`=11188 AND `item`=6149 AND `ExtendedCost`=0 AND `type`=1); -- Greater Mana Potion
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11188 AND `item`=20013 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Living Action Potion
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11188 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11119 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash

DELETE FROM `npc_vendor` WHERE (`entry`=48552 AND `item`=136377 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48552 AND `item`=6365 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48555 AND `item`=82344 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48555 AND `item`=83094 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48555 AND `item`=82343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48555 AND `item`=83095 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48551 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48581 AND `item`=79740 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=48574 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(48552, 8, 136377, 0, 0, 1, 0, 0, 25996), -- Oversized Bobber
(48552, 7, 6365, 1, 0, 1, 0, 0, 25996), -- Strong Fishing Pole
(48555, 27, 82344, 0, 0, 1, 0, 0, 25996), -- Hearthglen Ambrosia
(48555, 26, 83094, 0, 0, 1, 0, 0, 25996), -- Foote Tripel
(48555, 25, 82343, 0, 0, 1, 0, 0, 25996), -- Lordaeron Lambic
(48555, 24, 83095, 0, 0, 1, 0, 0, 25996), -- Lagrave Stout
(48551, 2, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(48581, 54, 79740, 0, 0, 1, 0, 0, 25996), -- Plain Wooden Staff
(48574, 22, 85663, 0, 0, 1, 0, 0, 25996); -- Herbalist's Spade

UPDATE `npc_vendor` SET `slot`=68, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19445 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Weapon - Agility
UPDATE `npc_vendor` SET `slot`=67, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19215 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Wisdom of the Timbermaw
UPDATE `npc_vendor` SET `slot`=66, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19326 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Might of the Timbermaw
UPDATE `npc_vendor` SET `slot`=65, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19202 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Heavy Timbermaw Belt
UPDATE `npc_vendor` SET `slot`=64, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=22392 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant 2H Weapon - Agility
UPDATE `npc_vendor` SET `slot`=63, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=13484 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Earth to Water
UPDATE `npc_vendor` SET `slot`=62, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=20254 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Warbear Woolies
UPDATE `npc_vendor` SET `slot`=61, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=20253 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Warbear Harness
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19218 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Mantle of the Timbermaw
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19327 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Timbermaw Brawlers
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19204 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Heavy Timbermaw Boots
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=64, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=22392 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant 2H Weapon - Agility
UPDATE `npc_vendor` SET `slot`=63, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=13484 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Earth to Water
UPDATE `npc_vendor` SET `slot`=62, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=20254 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Warbear Woolies
UPDATE `npc_vendor` SET `slot`=61, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=20253 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Warbear Harness
UPDATE `npc_vendor` SET `slot`=60, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19445 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Weapon - Agility
UPDATE `npc_vendor` SET `slot`=59, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19215 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Wisdom of the Timbermaw
UPDATE `npc_vendor` SET `slot`=58, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19326 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Might of the Timbermaw
UPDATE `npc_vendor` SET `slot`=57, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19202 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Heavy Timbermaw Belt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19218 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Mantle of the Timbermaw
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19327 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Timbermaw Brawlers
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19204 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Heavy Timbermaw Boots
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=64, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=22392 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant 2H Weapon - Agility
UPDATE `npc_vendor` SET `slot`=63, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=13484 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Transmute Earth to Water
UPDATE `npc_vendor` SET `slot`=62, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=20254 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Warbear Woolies
UPDATE `npc_vendor` SET `slot`=61, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=20253 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Warbear Harness
UPDATE `npc_vendor` SET `slot`=60, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19445 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Weapon - Agility
UPDATE `npc_vendor` SET `slot`=59, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19215 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Wisdom of the Timbermaw
UPDATE `npc_vendor` SET `slot`=58, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19326 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Might of the Timbermaw
UPDATE `npc_vendor` SET `slot`=57, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19202 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Heavy Timbermaw Belt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19218 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Mantle of the Timbermaw
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19327 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Timbermaw Brawlers
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=19204 AND `ExtendedCost`=0 AND `type`=1); -- Plans: Heavy Timbermaw Boots
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=11557 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=12, `maxcount`=1, `VerifiedBuild`=25996 WHERE (`entry`=48552 AND `item`=6533 AND `ExtendedCost`=0 AND `type`=1); -- Aquadynamic Fish Attractor
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=48552 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=48552 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=48552 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=48552 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48258 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48258 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48258 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48258 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48258 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48258 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=2595 AND `ExtendedCost`=0 AND `type`=1); -- Jug of Badlands Bourbon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=2594 AND `ExtendedCost`=0 AND `type`=1); -- Flagon of Dwarven Mead
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=2596 AND `ExtendedCost`=0 AND `type`=1); -- Skin of Dwarven Stout
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=2593 AND `ExtendedCost`=0 AND `type`=1); -- Flask of Stormwind Tawny
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=2723 AND `ExtendedCost`=0 AND `type`=1); -- Bottle of Dalaran Noir
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48555 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=8948 AND `ExtendedCost`=0 AND `type`=1); -- Dried King Bolete
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4608 AND `ExtendedCost`=0 AND `type`=1); -- Raw Black Truffle
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4607 AND `ExtendedCost`=0 AND `type`=1); -- Delicious Cave Mold
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4606 AND `ExtendedCost`=0 AND `type`=1); -- Spongy Morel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4605 AND `ExtendedCost`=0 AND `type`=1); -- Red-Speckled Mushroom
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4604 AND `ExtendedCost`=0 AND `type`=1); -- Forest Mushroom Cap
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=2803 AND `item`=16110 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Monster Omelet
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=15315 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48553 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=543 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48551 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48580 AND `item`=21219 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Sagefish Delight
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48580 AND `item`=21099 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Smoked Sagefish
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48580 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48580 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48580 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48587 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=53, `VerifiedBuild`=25996 WHERE (`entry`=48581 AND `item`=1515 AND `ExtendedCost`=0 AND `type`=1); -- Rough Wooden Staff
UPDATE `npc_vendor` SET `slot`=52, `VerifiedBuild`=25996 WHERE (`entry`=48581 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1); -- Scribe's Satchel
UPDATE `npc_vendor` SET `slot`=51, `VerifiedBuild`=25996 WHERE (`entry`=48581 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=50, `VerifiedBuild`=25996 WHERE (`entry`=48581 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=49, `VerifiedBuild`=25996 WHERE (`entry`=48581 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48215 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48216 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48573 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48573 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48573 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48573 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48573 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48573 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48574 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1); -- Zweihander
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1); -- Falchion
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1); -- Rondel
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=48577 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48599 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48607 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=48608 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife

DELETE FROM `npc_vendor` WHERE (`entry`=14753 AND `item`=30497 AND `ExtendedCost`=5996 AND `type`=1) OR (`entry`=14753 AND `item`=22672 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14753 AND `item`=22753 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14753 AND `item`=22748 AND `ExtendedCost`=5996 AND `type`=1) OR (`entry`=14753 AND `item`=22749 AND `ExtendedCost`=5996 AND `type`=1) OR (`entry`=14753 AND `item`=22750 AND `ExtendedCost`=5996 AND `type`=1) OR (`entry`=14753 AND `item`=22752 AND `ExtendedCost`=5996 AND `type`=1) OR (`entry`=14753 AND `item`=19582 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19583 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19584 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19587 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19589 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19590 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19595 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19596 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19597 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19578 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19580 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19581 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19506 AND `ExtendedCost`=5992 AND `type`=1) OR (`entry`=14753 AND `item`=19546 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19547 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19548 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19549 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=20443 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19554 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19555 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19556 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19557 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=20440 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19562 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19563 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19564 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19565 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=20438 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19570 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19571 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19572 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=19573 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=20434 AND `ExtendedCost`=5993 AND `type`=1) OR (`entry`=14753 AND `item`=17351 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14753 AND `item`=17348 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14753 AND `item`=19514 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19516 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19515 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19517 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=20439 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19538 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19539 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19540 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19541 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=20444 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19522 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19523 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19524 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19525 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=20431 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19530 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19531 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19532 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=19533 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=20428 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=17352 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14753 AND `item`=17349 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14753 AND `item`=21565 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=14753 AND `item`=21566 AND `ExtendedCost`=5995 AND `type`=1) OR (`entry`=34601 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34601 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=2446 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=17192 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=2151 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=2150 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=2149 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=2152 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=2148 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34624 AND `item`=2153 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3969 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3954 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3954 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3954 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3970 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(14753, 74, 30497, 0, 5996, 1, 0, 0, 25996), -- Sentinel's Mail Leggings
(14753, 73, 22672, 0, 0, 1, 0, 0, 25996), -- Sentinel's Plate Legguards
(14753, 72, 22753, 0, 0, 1, 0, 0, 25996), -- Sentinel's Lamellar Legguards
(14753, 71, 22748, 0, 5996, 1, 0, 0, 25996), -- Sentinel's Chain Leggings
(14753, 70, 22749, 0, 5996, 1, 0, 0, 25996), -- Sentinel's Leather Pants
(14753, 69, 22750, 0, 5996, 1, 0, 0, 25996), -- Sentinel's Lizardhide Pants
(14753, 68, 22752, 0, 5996, 1, 0, 0, 25996), -- Sentinel's Silk Leggings
(14753, 67, 19582, 0, 5995, 1, 0, 0, 25996), -- Windtalker's Wristguards
(14753, 66, 19583, 0, 5995, 1, 0, 0, 25996), -- Windtalker's Wristguards
(14753, 65, 19584, 0, 5995, 1, 0, 0, 25996), -- Windtalker's Wristguards
(14753, 64, 19587, 0, 5995, 1, 0, 0, 25996), -- Forest Stalker's Bracers
(14753, 63, 19589, 0, 5995, 1, 0, 0, 25996), -- Forest Stalker's Bracers
(14753, 62, 19590, 0, 5995, 1, 0, 0, 25996), -- Forest Stalker's Bracers
(14753, 61, 19595, 0, 5995, 1, 0, 0, 25996), -- Dryad's Wrist Bindings
(14753, 60, 19596, 0, 5995, 1, 0, 0, 25996), -- Dryad's Wrist Bindings
(14753, 59, 19597, 0, 5995, 1, 0, 0, 25996), -- Dryad's Wrist Bindings
(14753, 58, 19578, 0, 5995, 1, 0, 0, 25996), -- Berserker Bracers
(14753, 57, 19580, 0, 5995, 1, 0, 0, 25996), -- Berserker Bracers
(14753, 56, 19581, 0, 5995, 1, 0, 0, 25996), -- Berserker Bracers
(14753, 55, 19506, 0, 5992, 1, 0, 0, 25996), -- Silverwing Battle Tabard
(14753, 54, 19546, 0, 5993, 1, 0, 0, 25996), -- Sentinel's Blade
(14753, 53, 19547, 0, 5993, 1, 0, 0, 25996), -- Sentinel's Blade
(14753, 52, 19548, 0, 5993, 1, 0, 0, 25996), -- Sentinel's Blade
(14753, 51, 19549, 0, 5993, 1, 0, 0, 25996), -- Sentinel's Blade
(14753, 50, 20443, 0, 5993, 1, 0, 0, 25996), -- Sentinel's Blade
(14753, 49, 19554, 0, 5993, 1, 0, 0, 25996), -- Protector's Sword
(14753, 48, 19555, 0, 5993, 1, 0, 0, 25996), -- Protector's Sword
(14753, 47, 19556, 0, 5993, 1, 0, 0, 25996), -- Protector's Sword
(14753, 46, 19557, 0, 5993, 1, 0, 0, 25996), -- Protector's Sword
(14753, 45, 20440, 0, 5993, 1, 0, 0, 25996), -- Protector's Sword
(14753, 44, 19562, 0, 5993, 1, 0, 0, 25996), -- Outrunner's Bow
(14753, 43, 19563, 0, 5993, 1, 0, 0, 25996), -- Outrunner's Bow
(14753, 42, 19564, 0, 5993, 1, 0, 0, 25996), -- Outrunner's Bow
(14753, 41, 19565, 0, 5993, 1, 0, 0, 25996), -- Outrunner's Bow
(14753, 40, 20438, 0, 5993, 1, 0, 0, 25996), -- Outrunner's Bow
(14753, 39, 19570, 0, 5993, 1, 0, 0, 25996), -- Lorekeeper's Staff
(14753, 38, 19571, 0, 5993, 1, 0, 0, 25996), -- Lorekeeper's Staff
(14753, 37, 19572, 0, 5993, 1, 0, 0, 25996), -- Lorekeeper's Staff
(14753, 36, 19573, 0, 5993, 1, 0, 0, 25996), -- Lorekeeper's Staff
(14753, 35, 20434, 0, 5993, 1, 0, 0, 25996), -- Lorekeeper's Staff
(14753, 34, 17351, 0, 0, 1, 0, 0, 25996), -- Major Mana Draught
(14753, 33, 17348, 0, 0, 1, 0, 0, 25996), -- Major Healing Draught
(14753, 32, 19514, 0, 5995, 1, 0, 0, 25996), -- Protector's Band
(14753, 31, 19516, 0, 5995, 1, 0, 0, 25996), -- Protector's Band
(14753, 30, 19515, 0, 5995, 1, 0, 0, 25996), -- Protector's Band
(14753, 29, 19517, 0, 5995, 1, 0, 0, 25996), -- Protector's Band
(14753, 28, 20439, 0, 5995, 1, 0, 0, 25996), -- Protector's Band
(14753, 27, 19538, 0, 5995, 1, 0, 0, 25996), -- Sentinel's Medallion
(14753, 26, 19539, 0, 5995, 1, 0, 0, 25996), -- Sentinel's Medallion
(14753, 25, 19540, 0, 5995, 1, 0, 0, 25996), -- Sentinel's Medallion
(14753, 24, 19541, 0, 5995, 1, 0, 0, 25996), -- Sentinel's Medallion
(14753, 23, 20444, 0, 5995, 1, 0, 0, 25996), -- Sentinel's Medallion
(14753, 22, 19522, 0, 5995, 1, 0, 0, 25996), -- Lorekeeper's Ring
(14753, 21, 19523, 0, 5995, 1, 0, 0, 25996), -- Lorekeeper's Ring
(14753, 20, 19524, 0, 5995, 1, 0, 0, 25996), -- Lorekeeper's Ring
(14753, 19, 19525, 0, 5995, 1, 0, 0, 25996), -- Lorekeeper's Ring
(14753, 18, 20431, 0, 5995, 1, 0, 0, 25996), -- Lorekeeper's Ring
(14753, 17, 19530, 0, 5995, 1, 0, 0, 25996), -- Caretaker's Cape
(14753, 16, 19531, 0, 5995, 1, 0, 0, 25996), -- Caretaker's Cape
(14753, 15, 19532, 0, 5995, 1, 0, 0, 25996), -- Caretaker's Cape
(14753, 14, 19533, 0, 5995, 1, 0, 0, 25996), -- Caretaker's Cape
(14753, 13, 20428, 0, 5995, 1, 0, 0, 25996), -- Caretaker's Cape
(14753, 12, 17352, 0, 0, 1, 0, 0, 25996), -- Superior Mana Draught
(14753, 11, 17349, 0, 0, 1, 0, 0, 25996), -- Superior Healing Draught
(14753, 2, 21565, 0, 5995, 1, 0, 0, 25996), -- Rune of Perfection
(14753, 1, 21566, 0, 5995, 1, 0, 0, 25996), -- Rune of Perfection
(34601, 17, 10290, 0, 0, 1, 0, 0, 25996), -- Pink Dye
(34601, 16, 4342, 0, 0, 1, 0, 0, 25996), -- Purple Dye
(34601, 15, 6261, 0, 0, 1, 0, 0, 25996), -- Orange Dye
(34601, 14, 4341, 0, 0, 1, 0, 0, 25996), -- Yellow Dye
(34601, 13, 4340, 0, 0, 1, 0, 0, 25996), -- Gray Dye
(34601, 12, 2605, 0, 0, 1, 0, 0, 25996), -- Green Dye
(34601, 11, 2604, 0, 0, 1, 0, 0, 25996), -- Red Dye
(34601, 10, 6260, 0, 0, 1, 0, 0, 25996), -- Blue Dye
(34601, 9, 2325, 0, 0, 1, 0, 0, 25996), -- Black Dye
(34601, 8, 38426, 0, 0, 1, 0, 0, 25996), -- Eternium Thread
(34601, 7, 14341, 0, 0, 1, 0, 0, 25996), -- Rune Thread
(34601, 6, 8343, 0, 0, 1, 0, 0, 25996), -- Heavy Silken Thread
(34601, 5, 4291, 0, 0, 1, 0, 0, 25996), -- Silken Thread
(34601, 4, 2321, 0, 0, 1, 0, 0, 25996), -- Fine Thread
(34601, 3, 2320, 0, 0, 1, 0, 0, 25996), -- Coarse Thread
(34601, 2, 4289, 0, 0, 1, 0, 0, 25996), -- Salt
(34601, 1, 7005, 0, 0, 1, 0, 0, 25996), -- Skinning Knife
(34624, 8, 2446, 0, 0, 1, 0, 1, 25996), -- Kite Shield
(34624, 7, 17192, 0, 0, 1, 0, 1, 25996), -- Reinforced Targe
(34624, 6, 2151, 0, 0, 1, 0, 1, 25996), -- Polished Scale Gloves
(34624, 5, 2150, 0, 0, 1, 0, 1, 25996), -- Polished Scale Bracers
(34624, 4, 2149, 0, 0, 1, 0, 1, 25996), -- Polished Scale Boots
(34624, 3, 2152, 0, 0, 1, 0, 1, 25996), -- Polished Scale Leggings
(34624, 2, 2148, 0, 0, 1, 0, 1, 25996), -- Polished Scale Belt
(34624, 1, 2153, 0, 0, 1, 0, 1, 25996), -- Polished Scale Vest
(3969, 1, 4565, 0, 0, 1, 0, 0, 25996), -- Simple Dagger
(3954, 31, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(3954, 30, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(3954, 6, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(3970, 1, 64670, 0, 0, 1, 0, 0, 25996); -- Vanishing Powder

UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=924 AND `ExtendedCost`=0 AND `type`=1); -- Maul
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=928 AND `ExtendedCost`=0 AND `type`=1); -- Long Staff
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=925 AND `ExtendedCost`=0 AND `type`=1); -- Flail
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=2026 AND `ExtendedCost`=0 AND `type`=1); -- Rock Hammer
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=2028 AND `ExtendedCost`=0 AND `type`=1); -- Hammer
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=2030 AND `ExtendedCost`=0 AND `type`=1); -- Gnarled Staff
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=854 AND `ExtendedCost`=0 AND `type`=1); -- Quarter Staff
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=1197 AND `ExtendedCost`=0 AND `type`=1); -- Giant Mace
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=17412 AND `item`=852 AND `ExtendedCost`=0 AND `type`=1); -- Mace
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14753 AND `item`=19066 AND `ExtendedCost`=0 AND `type`=1); -- Warsong Gulch Runecloth Bandage
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14753 AND `item`=19067 AND `ExtendedCost`=0 AND `type`=1); -- Warsong Gulch Mageweave Bandage
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14753 AND `item`=19068 AND `ExtendedCost`=0 AND `type`=1); -- Warsong Gulch Silk Bandage
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14753 AND `item`=19060 AND `ExtendedCost`=0 AND `type`=1); -- Warsong Gulch Enriched Ration
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14753 AND `item`=19061 AND `ExtendedCost`=0 AND `type`=1); -- Warsong Gulch Iron Ration
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14753 AND `item`=19062 AND `ExtendedCost`=0 AND `type`=1); -- Warsong Gulch Field Ration
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=8948 AND `ExtendedCost`=0 AND `type`=1); -- Dried King Bolete
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=4608 AND `ExtendedCost`=0 AND `type`=1); -- Raw Black Truffle
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=4607 AND `ExtendedCost`=0 AND `type`=1); -- Delicious Cave Mold
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=4606 AND `ExtendedCost`=0 AND `type`=1); -- Spongy Morel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=14963 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3951 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3951 AND `item`=2507 AND `ExtendedCost`=0 AND `type`=1); -- Laminated Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3951 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3951 AND `item`=2507 AND `ExtendedCost`=0 AND `type`=1); -- Laminated Recurve Bow
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1); -- Striped Yellowtail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1); -- Rockscale Cod
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1); -- Bristle Whisker Catfish
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1); -- Longjaw Mud Snapper
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6738 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1); -- Slitherskin Mackerel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3959 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=21031 AND `ExtendedCost`=0 AND `type`=1); -- Cabbage Kimchi
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=21033 AND `ExtendedCost`=0 AND `type`=1); -- Radish Kimchi
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=21030 AND `ExtendedCost`=0 AND `type`=1); -- Darnassus Kimchi Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=16168 AND `ExtendedCost`=0 AND `type`=1); -- Heaven Peach
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=16169 AND `ExtendedCost`=0 AND `type`=1); -- Wild Ricecake
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=16170 AND `ExtendedCost`=0 AND `type`=1); -- Steamed Mandu
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=16167 AND `ExtendedCost`=0 AND `type`=1); -- Versicolor Treat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3961 AND `item`=16166 AND `ExtendedCost`=0 AND `type`=1); -- Bean Soup
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=10052 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=11101 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Bracer - Lesser Strength
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=11039 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Cloak - Minor Agility
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=3954 AND `item`=20855 AND `ExtendedCost`=0 AND `type`=1); -- Design: Wicked Moonstone Ring
UPDATE `npc_vendor` SET `slot`=16, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1); -- Battle Staff
UPDATE `npc_vendor` SET `slot`=15, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1); -- Main Gauche
UPDATE `npc_vendor` SET `slot`=14, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1); -- War Hammer
UPDATE `npc_vendor` SET `slot`=13, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1); -- Truncheon
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1); -- Flamberge
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1); -- Broadsword
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=928 AND `ExtendedCost`=0 AND `type`=1); -- Long Staff
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=2209 AND `ExtendedCost`=0 AND `type`=1); -- Kris
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=924 AND `ExtendedCost`=0 AND `type`=1); -- Maul
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=925 AND `ExtendedCost`=0 AND `type`=1); -- Flail
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=926 AND `ExtendedCost`=0 AND `type`=1); -- Battle Axe
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=927 AND `ExtendedCost`=0 AND `type`=1); -- Double Axe
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=922 AND `ExtendedCost`=0 AND `type`=1); -- Dacian Falx
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=11137 AND `item`=923 AND `ExtendedCost`=0 AND `type`=1); -- Longsword
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3962 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3958 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=2158 AND `ExtendedCost`=0 AND `type`=1); -- Padded Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3592 AND `ExtendedCost`=0 AND `type`=1); -- Padded Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=2156 AND `ExtendedCost`=0 AND `type`=1); -- Padded Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=2159 AND `ExtendedCost`=0 AND `type`=1); -- Padded Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3591 AND `ExtendedCost`=0 AND `type`=1); -- Padded Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=2160 AND `ExtendedCost`=0 AND `type`=1); -- Padded Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=203 AND `ExtendedCost`=0 AND `type`=1); -- Thick Cloth Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3598 AND `ExtendedCost`=0 AND `type`=1); -- Thick Cloth Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=202 AND `ExtendedCost`=0 AND `type`=1); -- Thick Cloth Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=201 AND `ExtendedCost`=0 AND `type`=1); -- Thick Cloth Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3597 AND `ExtendedCost`=0 AND `type`=1); -- Thick Cloth Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=200 AND `ExtendedCost`=0 AND `type`=1); -- Thick Cloth Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=839 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3590 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=840 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=838 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3589 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=837 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=793 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3603 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=792 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Sandals
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=794 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=3602 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3952 AND `item`=795 AND `ExtendedCost`=0 AND `type`=1); -- Knitted Tunic
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=2145 AND `ExtendedCost`=0 AND `type`=1); -- Cuirboulli Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=2144 AND `ExtendedCost`=0 AND `type`=1); -- Cuirboulli Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=2143 AND `ExtendedCost`=0 AND `type`=1); -- Cuirboulli Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=2146 AND `ExtendedCost`=0 AND `type`=1); -- Cuirboulli Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=2142 AND `ExtendedCost`=0 AND `type`=1); -- Cuirboulli Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=2141 AND `ExtendedCost`=0 AND `type`=1); -- Cuirboulli Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=239 AND `ExtendedCost`=0 AND `type`=1); -- Cured Leather Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=1850 AND `ExtendedCost`=0 AND `type`=1); -- Cured Leather Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=238 AND `ExtendedCost`=0 AND `type`=1); -- Cured Leather Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=237 AND `ExtendedCost`=0 AND `type`=1); -- Cured Leather Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=1849 AND `ExtendedCost`=0 AND `type`=1); -- Cured Leather Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=236 AND `ExtendedCost`=0 AND `type`=1); -- Cured Leather Armor
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=844 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Gloves
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=1844 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Bracers
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=843 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Boots
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=845 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Pants
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=1843 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Belt
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=846 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Jerkin
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=797 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Gloves
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=1840 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Bracers
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=796 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Boots
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=798 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Pants
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=1839 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Belt
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=3953 AND `item`=799 AND `ExtendedCost`=0 AND `type`=1); -- Rough Leather Vest
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=928 AND `ExtendedCost`=0 AND `type`=1); -- Long Staff
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=2209 AND `ExtendedCost`=0 AND `type`=1); -- Kris
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=924 AND `ExtendedCost`=0 AND `type`=1); -- Maul
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=925 AND `ExtendedCost`=0 AND `type`=1); -- Flail
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=926 AND `ExtendedCost`=0 AND `type`=1); -- Battle Axe
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=927 AND `ExtendedCost`=0 AND `type`=1); -- Double Axe
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=922 AND `ExtendedCost`=0 AND `type`=1); -- Dacian Falx
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=33265 AND `item`=923 AND `ExtendedCost`=0 AND `type`=1); -- Longsword
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=21031 AND `ExtendedCost`=0 AND `type`=1); -- Cabbage Kimchi
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=21033 AND `ExtendedCost`=0 AND `type`=1); -- Radish Kimchi
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=21030 AND `ExtendedCost`=0 AND `type`=1); -- Darnassus Kimchi Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=16168 AND `ExtendedCost`=0 AND `type`=1); -- Heaven Peach
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=16169 AND `ExtendedCost`=0 AND `type`=1); -- Wild Ricecake
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=16170 AND `ExtendedCost`=0 AND `type`=1); -- Steamed Mandu
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=16167 AND `ExtendedCost`=0 AND `type`=1); -- Versicolor Treat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33209 AND `item`=16166 AND `ExtendedCost`=0 AND `type`=1); -- Bean Soup

UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1351 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43425 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water

DELETE FROM `npc_vendor` WHERE (`entry`=4194 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4194 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(4194, 21, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(4194, 2, 85663, 0, 0, 1, 0, 0, 25996); -- Herbalist's Spade

UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4190 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4194 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=33231 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick

DELETE FROM `npc_vendor` WHERE (`entry`=32979 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32979 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4301 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4300 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4299 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4298 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4297 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4296 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4295 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4294 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4293 AND `type`=1) OR (`entry`=63083 AND `item`=98715 AND `ExtendedCost`=4292 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32979, 21, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(32979, 2, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(63083, 10, 98715, 0, 4301, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 9, 98715, 0, 4300, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 8, 98715, 0, 4299, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 7, 98715, 0, 4298, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 6, 98715, 0, 4297, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 5, 98715, 0, 4296, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 4, 98715, 0, 4295, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 3, 98715, 0, 4294, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 2, 98715, 0, 4293, 1, 0, 0, 25996), -- Marked Flawless Battle-Stone
(63083, 1, 98715, 0, 4292, 1, 0, 0, 25996); -- Marked Flawless Battle-Stone

UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43419 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=5048 AND `ExtendedCost`=0 AND `type`=1); -- Blue Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43424 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43439 AND `item`=844 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43439 AND `item`=1844 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43439 AND `item`=843 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43439 AND `item`=845 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43439 AND `item`=1843 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43439 AND `item`=846 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Jerkin
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=32979 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=1202 AND `ExtendedCost`=0 AND `type`=1); -- Wall Shield
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=17187 AND `ExtendedCost`=0 AND `type`=1); -- Banded Buckler
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=850 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=1846 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=849 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=848 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=1845 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4187 AND `item`=847 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=10085 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=839 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=3590 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=840 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Shoes
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=838 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Pants
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=3589 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=837 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Armor
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=16060 AND `ExtendedCost`=0 AND `type`=1); -- Common White Shirt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=3428 AND `ExtendedCost`=0 AND `type`=1); -- Common Gray Shirt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43436 AND `item`=16059 AND `ExtendedCost`=0 AND `type`=1); -- Common Brown Shirt

UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=8948 AND `ExtendedCost`=0 AND `type`=1); -- Dried King Bolete
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4608 AND `ExtendedCost`=0 AND `type`=1); -- Raw Black Truffle
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4607 AND `ExtendedCost`=0 AND `type`=1); -- Delicious Cave Mold
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4606 AND `ExtendedCost`=0 AND `type`=1); -- Spongy Morel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4605 AND `ExtendedCost`=0 AND `type`=1); -- Red-Speckled Mushroom
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4604 AND `ExtendedCost`=0 AND `type`=1); -- Forest Mushroom Cap
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=36378 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43887 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43882 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43882 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43882 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43882 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43882 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43882 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43880 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43877 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=43877 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=2448 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Pavise
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=17189 AND `ExtendedCost`=0 AND `type`=1); -- Metal Buckler
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=3891 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=2422 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=2421 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=2420 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=2418 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=2419 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=1322 AND `item`=2417 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=5048 AND `ExtendedCost`=0 AND `type`=1); -- Blue Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=12960 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=11103 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=12240 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Heavy Kodo Stew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=12233 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mystery Stew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=8948 AND `ExtendedCost`=0 AND `type`=1); -- Dried King Bolete
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=4608 AND `ExtendedCost`=0 AND `type`=1); -- Raw Black Truffle
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=4607 AND `ExtendedCost`=0 AND `type`=1); -- Delicious Cave Mold
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=4606 AND `ExtendedCost`=0 AND `type`=1); -- Spongy Morel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=4605 AND `ExtendedCost`=0 AND `type`=1); -- Red-Speckled Mushroom
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=8150 AND `item`=4604 AND `ExtendedCost`=0 AND `type`=1); -- Forest Mushroom Cap
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=11104 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash

DELETE FROM `npc_vendor` WHERE (`entry`=40914 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40914 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2535 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2534 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2529 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44385 AND `item`=2528 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14637 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=14637 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(40914, 9, 4470, 0, 0, 1, 0, 0, 25996), -- Simple Wood
(40914, 8, 4499, 0, 0, 1, 0, 0, 25996), -- Huge Brown Sack
(40914, 7, 4497, 0, 0, 1, 0, 0, 25996), -- Heavy Brown Bag
(40914, 6, 4601, 0, 0, 1, 0, 0, 25996), -- Soft Banana Bread
(40914, 5, 4542, 0, 0, 1, 0, 0, 25996), -- Moist Cornbread
(40914, 4, 1645, 0, 0, 1, 0, 0, 25996), -- Moonberry Juice
(40914, 3, 1708, 0, 0, 1, 0, 0, 25996), -- Sweet Nectar
(40914, 2, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(40914, 1, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44385, 8, 2535, 0, 0, 1, 0, 1, 25996), -- War Staff
(44385, 7, 2534, 0, 0, 1, 0, 1, 25996), -- Rondel
(44385, 6, 2533, 0, 0, 1, 0, 1, 25996), -- War Maul
(44385, 5, 2532, 0, 0, 1, 0, 1, 25996), -- Morning Star
(44385, 4, 2531, 0, 0, 1, 0, 1, 25996), -- Great Axe
(44385, 3, 2530, 0, 0, 1, 0, 1, 25996), -- Francisca
(44385, 2, 2529, 0, 0, 1, 0, 1, 25996), -- Zweihander
(44385, 1, 2528, 0, 0, 1, 0, 1, 25996), -- Falchion
(14637, 13, 39354, 0, 0, 1, 0, 0, 25996), -- Light Parchment
(14637, 3, 90146, 0, 0, 1, 0, 0, 25996); -- Tinker's Kit

UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=44381 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=19027 AND `ExtendedCost`=0 AND `type`=1); -- Schematic: Snake Burst Firework
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Blasting Powder
UPDATE `npc_vendor` SET `slot`=11, `maxcount`=4, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1); -- Rough Blasting Powder
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1); -- Engineer's Ink
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1); -- Hair Trigger
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1); -- Walnut Stock
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=14637 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer

DELETE FROM `npc_vendor` WHERE (`entry`=44397 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44397 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44397 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44397 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44397 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44397 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44391 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=10059 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7947 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7947 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7947 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7942 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7942 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7942 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7942 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=7945 AND `item`=136377 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=15734 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=7451 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40226 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3700 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44382 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40968 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40967 AND `item`=3027 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=40967 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(44397, 6, 8953, 0, 0, 1, 0, 0, 25996), -- Deep Fried Plantains
(44397, 5, 4602, 0, 0, 1, 0, 0, 25996), -- Moon Harvest Pumpkin
(44397, 4, 4539, 0, 0, 1, 0, 0, 25996), -- Goldenbark Apple
(44397, 3, 4538, 0, 0, 1, 0, 0, 25996), -- Snapvine Watermelon
(44397, 2, 4537, 0, 0, 1, 0, 0, 25996), -- Tel'Abim Banana
(44397, 1, 4536, 0, 0, 1, 0, 0, 25996), -- Shiny Red Apple
(44391, 12, 8766, 0, 0, 1, 0, 0, 25996), -- Morning Glory Dew
(44391, 11, 1645, 0, 0, 1, 0, 0, 25996), -- Moonberry Juice
(44391, 10, 1708, 0, 0, 1, 0, 0, 25996), -- Sweet Nectar
(44391, 9, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(44391, 8, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(44391, 7, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(44391, 6, 8953, 0, 0, 1, 0, 0, 25996), -- Deep Fried Plantains
(44391, 5, 4602, 0, 0, 1, 0, 0, 25996), -- Moon Harvest Pumpkin
(44391, 4, 4539, 0, 0, 1, 0, 0, 25996), -- Goldenbark Apple
(44391, 3, 4538, 0, 0, 1, 0, 0, 25996), -- Snapvine Watermelon
(44391, 2, 4537, 0, 0, 1, 0, 0, 25996), -- Tel'Abim Banana
(44391, 1, 4536, 0, 0, 1, 0, 0, 25996), -- Shiny Red Apple
(10059, 1, 37460, 0, 0, 1, 0, 0, 25996), -- Rope Pet Leash
(7947, 28, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(7947, 27, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(7947, 3, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(7942, 14, 4499, 0, 0, 1, 0, 0, 25996), -- Huge Brown Sack
(7942, 13, 4601, 0, 0, 1, 0, 0, 25996), -- Soft Banana Bread
(7942, 5, 4542, 0, 0, 1, 0, 0, 25996), -- Moist Cornbread
(7942, 4, 4541, 0, 0, 1, 0, 0, 25996), -- Freshly Baked Bread
(7945, 37, 136377, 0, 0, 1, 0, 0, 25996), -- Oversized Bobber
(40226, 35, 15734, 1, 0, 1, 0, 0, 25996), -- Pattern: Living Shoulders
(40226, 34, 7451, 1, 0, 1, 0, 0, 25996), -- Pattern: Green Whelp Bracers
(40226, 17, 10290, 0, 0, 1, 0, 0, 25996), -- Pink Dye
(40226, 16, 4342, 0, 0, 1, 0, 0, 25996), -- Purple Dye
(40226, 15, 6261, 0, 0, 1, 0, 0, 25996), -- Orange Dye
(40226, 14, 4341, 0, 0, 1, 0, 0, 25996), -- Yellow Dye
(40226, 13, 4340, 0, 0, 1, 0, 0, 25996), -- Gray Dye
(40226, 12, 2605, 0, 0, 1, 0, 0, 25996), -- Green Dye
(40226, 11, 2604, 0, 0, 1, 0, 0, 25996), -- Red Dye
(40226, 10, 6260, 0, 0, 1, 0, 0, 25996), -- Blue Dye
(40226, 9, 2325, 0, 0, 1, 0, 0, 25996), -- Black Dye
(40226, 8, 38426, 0, 0, 1, 0, 0, 25996), -- Eternium Thread
(40226, 7, 14341, 0, 0, 1, 0, 0, 25996), -- Rune Thread
(40226, 6, 8343, 0, 0, 1, 0, 0, 25996), -- Heavy Silken Thread
(40226, 5, 4291, 0, 0, 1, 0, 0, 25996), -- Silken Thread
(40226, 4, 2321, 0, 0, 1, 0, 0, 25996), -- Fine Thread
(40226, 3, 2320, 0, 0, 1, 0, 0, 25996), -- Coarse Thread
(40226, 2, 4289, 0, 0, 1, 0, 0, 25996), -- Salt
(40226, 1, 7005, 0, 0, 1, 0, 0, 25996), -- Skinning Knife
(3700, 1, 64670, 0, 0, 1, 0, 0, 25996), -- Vanishing Powder
(44382, 1, 37460, 0, 0, 1, 0, 0, 25996), -- Rope Pet Leash
(40968, 12, 8766, 0, 0, 1, 0, 0, 25996), -- Morning Glory Dew
(40968, 11, 1645, 0, 0, 1, 0, 0, 25996), -- Moonberry Juice
(40968, 10, 1708, 0, 0, 1, 0, 0, 25996), -- Sweet Nectar
(40968, 9, 1205, 0, 0, 1, 0, 0, 25996), -- Melon Juice
(40968, 8, 1179, 0, 0, 1, 0, 0, 25996), -- Ice Cold Milk
(40968, 7, 159, 0, 0, 1, 0, 0, 25996), -- Refreshing Spring Water
(40968, 6, 8953, 0, 0, 1, 0, 0, 25996), -- Deep Fried Plantains
(40968, 5, 4602, 0, 0, 1, 0, 0, 25996), -- Moon Harvest Pumpkin
(40968, 4, 4539, 0, 0, 1, 0, 0, 25996), -- Goldenbark Apple
(40968, 3, 4538, 0, 0, 1, 0, 0, 25996), -- Snapvine Watermelon
(40968, 2, 4537, 0, 0, 1, 0, 0, 25996), -- Tel'Abim Banana
(40968, 1, 4536, 0, 0, 1, 0, 0, 25996), -- Shiny Red Apple
(40967, 2, 3027, 0, 0, 1, 0, 1, 25996), -- Heavy Recurve Bow
(40967, 1, 3026, 0, 0, 1, 0, 1, 25996); -- Reinforced Bow

UPDATE `npc_vendor` SET `slot`=40, `VerifiedBuild`=25996 WHERE (`entry`=8157 AND `item`=9302 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Ghost Dye
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=8157 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=13947 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Lobster Stew
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=13949 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Baked Salmon
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=12229 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Hot Wolf Ribs
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=13948 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mightfish Steak
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=7947 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=14, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=3892 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Hat
UPDATE `npc_vendor` SET `slot`=13, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2440 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Gloves
UPDATE `npc_vendor` SET `slot`=12, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=3588 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Bracers
UPDATE `npc_vendor` SET `slot`=11, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2438 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Boots
UPDATE `npc_vendor` SET `slot`=10, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2437 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Pants
UPDATE `npc_vendor` SET `slot`=9, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=3587 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Belt
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2435 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Armor
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=3889 AND `ExtendedCost`=0 AND `type`=1); -- Russet Hat
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2434 AND `ExtendedCost`=0 AND `type`=1); -- Russet Gloves
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=3594 AND `ExtendedCost`=0 AND `type`=1); -- Russet Bracers
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2432 AND `ExtendedCost`=0 AND `type`=1); -- Russet Boots
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2431 AND `ExtendedCost`=0 AND `type`=1); -- Russet Pants
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=3593 AND `ExtendedCost`=0 AND `type`=1); -- Russet Belt
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=10293 AND `item`=2429 AND `ExtendedCost`=0 AND `type`=1); -- Russet Vest
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=5048 AND `ExtendedCost`=0 AND `type`=1); -- Blue Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=7942 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=21031 AND `ExtendedCost`=0 AND `type`=1); -- Cabbage Kimchi
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=21033 AND `ExtendedCost`=0 AND `type`=1); -- Radish Kimchi
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=21030 AND `ExtendedCost`=0 AND `type`=1); -- Darnassus Kimchi Pie
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=16168 AND `ExtendedCost`=0 AND `type`=1); -- Heaven Peach
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=16169 AND `ExtendedCost`=0 AND `type`=1); -- Wild Ricecake
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=16170 AND `ExtendedCost`=0 AND `type`=1); -- Steamed Mandu
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=16167 AND `ExtendedCost`=0 AND `type`=1); -- Versicolor Treat
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=7941 AND `item`=16166 AND `ExtendedCost`=0 AND `type`=1); -- Bean Soup
UPDATE `npc_vendor` SET `slot`=41, `maxcount`=2, `VerifiedBuild`=25996 WHERE (`entry`=7945 AND `item`=6533 AND `ExtendedCost`=0 AND `type`=1); -- Aquadynamic Fish Attractor
UPDATE `npc_vendor` SET `slot`=40, `VerifiedBuild`=25996 WHERE (`entry`=7945 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=39, `VerifiedBuild`=25996 WHERE (`entry`=7945 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=38, `VerifiedBuild`=25996 WHERE (`entry`=7945 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=36, `VerifiedBuild`=25996 WHERE (`entry`=7945 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1); -- Striped Yellowtail
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1); -- Rockscale Cod
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1); -- Bristle Whisker Catfish
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1); -- Longjaw Mud Snapper
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=7943 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1); -- Slitherskin Mackerel

DELETE FROM `npc_vendor` WHERE (`entry`=4897 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4897 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4897 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=44383 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23896 AND `item`=6533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23896 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23896 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23896 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23896 AND `item`=136377 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=23896 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4896 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4941 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2527 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2526 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2525 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2524 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2521 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4886 AND `item`=2520 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4888 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4888 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4888 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4888 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4888 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=4888 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53409 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53409 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53409 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53409 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53409 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53409 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53415 AND `item`=79740 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=53415 AND `item`=1515 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(4897, 33, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(4897, 32, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(4897, 8, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(44383, 29, 39505, 0, 0, 1, 0, 0, 25996), -- Virtuoso Inking Set
(44383, 28, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(44383, 27, 6532, 0, 0, 1, 0, 0, 25996), -- Bright Baubles
(44383, 26, 6530, 0, 0, 1, 0, 0, 25996), -- Nightcrawlers
(44383, 25, 4400, 0, 0, 1, 0, 0, 25996), -- Heavy Stock
(44383, 24, 4399, 0, 0, 1, 0, 0, 25996), -- Wooden Stock
(44383, 23, 4289, 0, 0, 1, 0, 0, 25996), -- Salt
(44383, 22, 3371, 0, 0, 1, 0, 0, 25996), -- Crystal Vial
(44383, 21, 4340, 0, 0, 1, 0, 0, 25996), -- Gray Dye
(44383, 20, 4342, 0, 0, 1, 0, 0, 25996), -- Purple Dye
(44383, 19, 4341, 0, 0, 1, 0, 0, 25996), -- Yellow Dye
(44383, 18, 2325, 0, 0, 1, 0, 0, 25996), -- Black Dye
(44383, 17, 2604, 0, 0, 1, 0, 0, 25996), -- Red Dye
(44383, 16, 2324, 0, 0, 1, 0, 0, 25996), -- Bleach
(44383, 15, 3857, 0, 0, 1, 0, 0, 25996), -- Coal
(44383, 14, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(44383, 13, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(44383, 12, 2678, 0, 0, 1, 0, 0, 25996), -- Mild Spices
(44383, 11, 14341, 0, 0, 1, 0, 0, 25996), -- Rune Thread
(44383, 10, 8343, 0, 0, 1, 0, 0, 25996), -- Heavy Silken Thread
(44383, 9, 4291, 0, 0, 1, 0, 0, 25996), -- Silken Thread
(44383, 8, 2321, 0, 0, 1, 0, 0, 25996), -- Fine Thread
(44383, 7, 2320, 0, 0, 1, 0, 0, 25996), -- Coarse Thread
(44383, 6, 6217, 0, 0, 1, 0, 0, 25996), -- Copper Rod
(44383, 5, 5956, 0, 0, 1, 0, 0, 25996), -- Blacksmith Hammer
(44383, 4, 6256, 0, 0, 1, 0, 0, 25996), -- Fishing Pole
(44383, 3, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(44383, 2, 85663, 0, 0, 1, 0, 0, 25996), -- Herbalist's Spade
(44383, 1, 7005, 0, 0, 1, 0, 0, 25996), -- Skinning Knife
(23896, 115, 6533, 2, 0, 1, 0, 0, 25996), -- Aquadynamic Fish Attractor
(23896, 114, 6532, 0, 0, 1, 0, 0, 25996), -- Bright Baubles
(23896, 113, 6530, 0, 0, 1, 0, 0, 25996), -- Nightcrawlers
(23896, 112, 6529, 0, 0, 1, 0, 0, 25996), -- Shiny Bauble
(23896, 111, 136377, 0, 0, 1, 0, 0, 25996), -- Oversized Bobber
(23896, 110, 6256, 0, 0, 1, 0, 0, 25996), -- Fishing Pole
(4896, 10, 64670, 0, 0, 1, 0, 0, 25996), -- Vanishing Powder
(4941, 254, 39354, 0, 0, 1, 0, 0, 25996), -- Light Parchment
(4941, 253, 4364, 2, 0, 1, 0, 0, 25996), -- Coarse Blasting Powder
(4941, 252, 4357, 4, 0, 1, 0, 0, 25996), -- Rough Blasting Powder
(4941, 251, 10647, 0, 0, 1, 0, 0, 25996), -- Engineer's Ink
(4941, 250, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(4941, 249, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(4941, 248, 39684, 0, 0, 1, 0, 0, 25996), -- Hair Trigger
(4941, 247, 40533, 0, 0, 1, 0, 0, 25996), -- Walnut Stock
(4941, 246, 4400, 0, 0, 1, 0, 0, 25996), -- Heavy Stock
(4941, 245, 4399, 0, 0, 1, 0, 0, 25996), -- Wooden Stock
(4941, 244, 90146, 0, 0, 1, 0, 0, 25996), -- Tinker's Kit
(4941, 243, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(4941, 242, 5956, 0, 0, 1, 0, 0, 25996), -- Blacksmith Hammer
(4886, 16, 2527, 0, 0, 1, 0, 1, 25996), -- Battle Staff
(4886, 15, 2526, 0, 0, 1, 0, 1, 25996), -- Main Gauche
(4886, 14, 2525, 0, 0, 1, 0, 1, 25996), -- War Hammer
(4886, 13, 2524, 0, 0, 1, 0, 1, 25996), -- Truncheon
(4886, 12, 2523, 0, 0, 1, 0, 1, 25996), -- Bullova
(4886, 11, 2522, 0, 0, 1, 0, 1, 25996), -- Crescent Axe
(4886, 10, 2521, 0, 0, 1, 0, 1, 25996), -- Flamberge
(4886, 9, 2520, 0, 0, 1, 0, 1, 25996), -- Broadsword
(4888, 6, 3857, 0, 0, 1, 0, 0, 25996), -- Coal
(4888, 5, 18567, 0, 0, 1, 0, 0, 25996), -- Elemental Flux
(4888, 4, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(4888, 3, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(4888, 2, 5956, 0, 0, 1, 0, 0, 25996), -- Blacksmith Hammer
(4888, 1, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(53409, 6, 20815, 0, 0, 1, 0, 0, 25996), -- Jeweler's Kit
(53409, 5, 3857, 0, 0, 1, 0, 0, 25996), -- Coal
(53409, 4, 3466, 0, 0, 1, 0, 0, 25996), -- Strong Flux
(53409, 3, 2880, 0, 0, 1, 0, 0, 25996), -- Weak Flux
(53409, 2, 30746, 0, 0, 1, 0, 0, 25996), -- Mining Sack
(53409, 1, 2901, 0, 0, 1, 0, 0, 25996), -- Mining Pick
(53415, 372, 79740, 0, 0, 1, 0, 0, 25996), -- Plain Wooden Staff
(53415, 371, 1515, 0, 0, 1, 0, 0, 25996); -- Rough Wooden Staff

UPDATE `npc_vendor` SET `slot`=495, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5789 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Murloc Scale Bracers
UPDATE `npc_vendor` SET `slot`=494, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21943 AND `ExtendedCost`=0 AND `type`=1); -- Design: Truesilver Crab
UPDATE `npc_vendor` SET `slot`=493, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21941 AND `ExtendedCost`=0 AND `type`=1); -- Design: Black Pearl Panther
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12239 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Dragonbreath Chili
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12233 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mystery Stew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12228 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Roast Raptor
UPDATE `npc_vendor` SET `slot`=488, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21943 AND `ExtendedCost`=0 AND `type`=1); -- Design: Truesilver Crab
UPDATE `npc_vendor` SET `slot`=487, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21941 AND `ExtendedCost`=0 AND `type`=1); -- Design: Black Pearl Panther
UPDATE `npc_vendor` SET `slot`=484, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5789 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Murloc Scale Bracers
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12239 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Dragonbreath Chili
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12233 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mystery Stew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12228 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Roast Raptor
UPDATE `npc_vendor` SET `slot`=488, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21943 AND `ExtendedCost`=0 AND `type`=1); -- Design: Truesilver Crab
UPDATE `npc_vendor` SET `slot`=487, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21941 AND `ExtendedCost`=0 AND `type`=1); -- Design: Black Pearl Panther
UPDATE `npc_vendor` SET `slot`=484, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5789 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Murloc Scale Bracers
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12239 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Dragonbreath Chili
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12233 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mystery Stew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12228 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Roast Raptor
UPDATE `npc_vendor` SET `slot`=488, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21943 AND `ExtendedCost`=0 AND `type`=1); -- Design: Truesilver Crab
UPDATE `npc_vendor` SET `slot`=487, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21941 AND `ExtendedCost`=0 AND `type`=1); -- Design: Black Pearl Panther
UPDATE `npc_vendor` SET `slot`=484, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5789 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Murloc Scale Bracers
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12239 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Dragonbreath Chili
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12233 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mystery Stew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12228 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Roast Raptor
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=23995 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=23995 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=23995 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=23995 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=23995 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=23995 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2426 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Boots
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2420 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Boots
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2473 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Boots
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2467 AND `ExtendedCost`=0 AND `type`=1); -- Studded Boots
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2438 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Boots
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2432 AND `ExtendedCost`=0 AND `type`=1); -- Russet Boots
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=23573 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2426 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Boots
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2420 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Boots
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2473 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Boots
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2467 AND `ExtendedCost`=0 AND `type`=1); -- Studded Boots
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2438 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Boots
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2432 AND `ExtendedCost`=0 AND `type`=1); -- Russet Boots
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2531 AND `ExtendedCost`=0 AND `type`=1); -- Great Axe
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2523 AND `ExtendedCost`=0 AND `type`=1); -- Bullova
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2530 AND `ExtendedCost`=0 AND `type`=1); -- Francisca
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=23571 AND `item`=2522 AND `ExtendedCost`=0 AND `type`=1); -- Crescent Axe
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=5388 AND `item`=52188 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Setting
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=5388 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=53421 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53421 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53421 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53421 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53421 AND `item`=30746 AND `ExtendedCost`=0 AND `type`=1); -- Mining Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53421 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=21219 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Sagefish Delight
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=21099 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Smoked Sagefish
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1); -- Simple Flour
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4894 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4893 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4893 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4893 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4893 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4893 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4893 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1); -- Pink Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1); -- Orange Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1); -- Green Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1); -- Blue Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=53436 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6272 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=10047 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1); -- Rope Pet Leash
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1); -- Roasted Quail
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1); -- Cured Ham Steak
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1); -- Wild Hog Shank
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1); -- Mutton Chop
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1); -- Haunch of Meat
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1); -- Tough Jerky
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1); -- Deep Fried Plantains
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1); -- Moon Harvest Pumpkin
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1); -- Goldenbark Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1); -- Snapvine Watermelon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1); -- Tel'Abim Banana
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Red Apple
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1); -- Alterac Swiss
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1); -- Fine Aged Cheddar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1); -- Stormwind Brie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1); -- Dwarven Mild
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1); -- Dalaran Sharp
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1); -- Darnassian Bleu
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1); -- Homemade Cherry Pie
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1); -- Mulgore Spice Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1); -- Freshly Baked Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4891 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1); -- Tough Hunk of Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4889 AND `item`=3024 AND `ExtendedCost`=0 AND `type`=1); -- BKP 2700 "Enforcer"
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4889 AND `item`=3023 AND `ExtendedCost`=0 AND `type`=1); -- Large Bore Blunderbuss
UPDATE `npc_vendor` SET `slot`=193, `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=4831 AND `ExtendedCost`=0 AND `type`=1); -- Stalking Pants
UPDATE `npc_vendor` SET `slot`=192, `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=4825 AND `ExtendedCost`=0 AND `type`=1); -- Callous Axe
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=2426 AND `ExtendedCost`=0 AND `type`=1); -- Brigandine Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=2420 AND `ExtendedCost`=0 AND `type`=1); -- Augmented Chain Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=2473 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Leather Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=2467 AND `ExtendedCost`=0 AND `type`=1); -- Studded Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=2438 AND `ExtendedCost`=0 AND `type`=1); -- Embroidered Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4890 AND `item`=2432 AND `ExtendedCost`=0 AND `type`=1); -- Russet Boots
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4892 AND `item`=3027 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Recurve Bow
UPDATE `npc_vendor` SET `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4892 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=23896 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1); -- Spinefin Halibut
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=23896 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1); -- Striped Yellowtail
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=23896 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1); -- Rockscale Cod
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=23896 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1); -- Bristle Whisker Catfish
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=23896 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1); -- Longjaw Mud Snapper
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=23896 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1); -- Slitherskin Mackerel
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=4499 AND `ExtendedCost`=0 AND `type`=1); -- Huge Brown Sack
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=4497 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Brown Bag
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1); -- Soft Banana Bread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1); -- Moist Cornbread
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4896 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water
UPDATE `npc_vendor` SET `slot`=437, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21943 AND `ExtendedCost`=0 AND `type`=1); -- Design: Truesilver Crab
UPDATE `npc_vendor` SET `slot`=436, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=21941 AND `ExtendedCost`=0 AND `type`=1); -- Design: Black Pearl Panther
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12239 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Dragonbreath Chili
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12233 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Mystery Stew
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4897 AND `item`=12228 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Roast Raptor
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=4885 AND `item`=18776 AND `ExtendedCost`=0 AND `type`=1); -- Swift Palomino
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=4885 AND `item`=18778 AND `ExtendedCost`=0 AND `type`=1); -- Swift White Steed
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=4885 AND `item`=18777 AND `ExtendedCost`=0 AND `type`=1); -- Swift Brown Steed
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=4885 AND `item`=5656 AND `ExtendedCost`=0 AND `type`=1); -- Brown Horse Bridle
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=4885 AND `item`=5655 AND `ExtendedCost`=0 AND `type`=1); -- Chestnut Mare Bridle
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=4885 AND `item`=2414 AND `ExtendedCost`=0 AND `type`=1); -- Pinto Bridle
UPDATE `npc_vendor` SET `slot`=8, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=2446 AND `ExtendedCost`=0 AND `type`=1); -- Kite Shield
UPDATE `npc_vendor` SET `slot`=7, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=17192 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Targe
UPDATE `npc_vendor` SET `slot`=6, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=2151 AND `ExtendedCost`=0 AND `type`=1); -- Polished Scale Gloves
UPDATE `npc_vendor` SET `slot`=5, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=2150 AND `ExtendedCost`=0 AND `type`=1); -- Polished Scale Bracers
UPDATE `npc_vendor` SET `slot`=4, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=2149 AND `ExtendedCost`=0 AND `type`=1); -- Polished Scale Boots
UPDATE `npc_vendor` SET `slot`=3, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=2152 AND `ExtendedCost`=0 AND `type`=1); -- Polished Scale Leggings
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=2148 AND `ExtendedCost`=0 AND `type`=1); -- Polished Scale Belt
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=25996 WHERE (`entry`=4886 AND `item`=2153 AND `ExtendedCost`=0 AND `type`=1); -- Polished Scale Vest
UPDATE `npc_vendor` SET `slot`=98, `VerifiedBuild`=25996 WHERE (`entry`=4899 AND `item`=3827 AND `ExtendedCost`=0 AND `type`=1); -- Mana Potion
UPDATE `npc_vendor` SET `slot`=97, `maxcount`=3, `VerifiedBuild`=25996 WHERE (`entry`=4899 AND `item`=1710 AND `ExtendedCost`=0 AND `type`=1); -- Greater Healing Potion
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=4899 AND `item`=22250 AND `ExtendedCost`=0 AND `type`=1); -- Herb Pouch
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=4899 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=370, `maxcount`=3, `VerifiedBuild`=25996 WHERE (`entry`=53415 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1); -- Scribe's Satchel
UPDATE `npc_vendor` SET `slot`=369, `VerifiedBuild`=25996 WHERE (`entry`=53415 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=368, `VerifiedBuild`=25996 WHERE (`entry`=53415 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=367, `VerifiedBuild`=25996 WHERE (`entry`=53415 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `slot`=240, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=239, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=238, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=237, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=236, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=235, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=234, `maxcount`=2, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=233, `maxcount`=2, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=232, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=231, `VerifiedBuild`=25996 WHERE (`entry`=53410 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122666 AND `ExtendedCost`=5567 AND `type`=1); -- Eternal Woven Ivy Necklace
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122668 AND `ExtendedCost`=5567 AND `type`=1); -- Eternal Will of the Martyr
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122662 AND `ExtendedCost`=5567 AND `type`=1); -- Eternal Talisman of Evasion
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122664 AND `ExtendedCost`=5567 AND `type`=1); -- Eternal Horizon Choker
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122667 AND `ExtendedCost`=5567 AND `type`=1); -- Eternal Emberfury Talisman
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122663 AND `ExtendedCost`=5567 AND `type`=1); -- Eternal Amulet of the Redeemed
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122362 AND `ExtendedCost`=5567 AND `type`=1); -- Discerning Eye of the Beast
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122361 AND `ExtendedCost`=5567 AND `type`=1); -- Swift Hand of Justice
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122530 AND `ExtendedCost`=5567 AND `type`=1); -- Inherited Mark of Tyranny
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122371 AND `ExtendedCost`=5567 AND `type`=1); -- Inherited Insignia of the Alliance
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122391 AND `ExtendedCost`=5564 AND `type`=1); -- Flamescarred Draconian Deflector
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122392 AND `ExtendedCost`=5564 AND `type`=1); -- Weathered Observer's Shield
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122390 AND `ExtendedCost`=5564 AND `type`=1); -- Musty Tome of the Lost
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122351 AND `ExtendedCost`=5565 AND `type`=1); -- Venerable Dal'Rend's Sacred Charge
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122350 AND `ExtendedCost`=5565 AND `type`=1); -- Balanced Heartseeker
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122385 AND `ExtendedCost`=5565 AND `type`=1); -- Venerable Mass of McGowan
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122354 AND `ExtendedCost`=5565 AND `type`=1); -- Devout Aurastone Hammer
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122389 AND `ExtendedCost`=5565 AND `type`=1); -- Bloodsoaked Skullforge Reaver
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122369 AND `ExtendedCost`=5565 AND `type`=1); -- Battleworn Thrash Blade
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122367 AND `ExtendedCost`=5565 AND `type`=1); -- The Blessed Hammer of Grace
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122364 AND `ExtendedCost`=5565 AND `type`=1); -- Sharpened Scarlet Kris
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122366 AND `ExtendedCost`=5566 AND `type`=1); -- Upgraded Dwarven Hand Cannon
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122352 AND `ExtendedCost`=5566 AND `type`=1); -- Charmed Ancient Bone Bow
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122363 AND `ExtendedCost`=5566 AND `type`=1); -- Burnished Warden Staff
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122349 AND `ExtendedCost`=5566 AND `type`=1); -- Bloodied Arcanite Reaper
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122353 AND `ExtendedCost`=5566 AND `type`=1); -- Dignified Headmaster's Charge
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122386 AND `ExtendedCost`=5566 AND `type`=1); -- Repurposed Lava Dredger
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122365 AND `ExtendedCost`=5566 AND `type`=1); -- Reforged Truesilver Champion
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122368 AND `ExtendedCost`=5566 AND `type`=1); -- Grand Staff of Jordan
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=140773 AND `ExtendedCost`=5565 AND `type`=1); -- Eagletalon Spear
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122387 AND `ExtendedCost`=5563 AND `type`=1); -- Burnished Breastplate of Might
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=127010 AND `ExtendedCost`=5563 AND `type`=1); -- Pristine Lightforge Breastplate
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122381 AND `ExtendedCost`=5563 AND `type`=1); -- Polished Breastplate of Valor
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122380 AND `ExtendedCost`=5563 AND `type`=1); -- Mystical Vest of Elements
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122379 AND `ExtendedCost`=5563 AND `type`=1); -- Champion's Deathdealer Breastplate
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122382 AND `ExtendedCost`=5563 AND `type`=1); -- Preened Ironfeather Breastplate
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122383 AND `ExtendedCost`=5563 AND `type`=1); -- Stained Shadowcraft Tunic
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122384 AND `ExtendedCost`=5563 AND `type`=1); -- Tattered Dreadmist Robe
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122388 AND `ExtendedCost`=5564 AND `type`=1); -- Burnished Pauldrons of Might
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122355 AND `ExtendedCost`=5564 AND `type`=1); -- Polished Spaulders of Valor
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122373 AND `ExtendedCost`=5564 AND `type`=1); -- Pristine Lightforge Spaulders
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122372 AND `ExtendedCost`=5564 AND `type`=1); -- Strengthened Stockade Pauldrons
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122356 AND `ExtendedCost`=5564 AND `type`=1); -- Champion Herod's Shoulder
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122357 AND `ExtendedCost`=5564 AND `type`=1); -- Mystical Pauldrons of Elements
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122375 AND `ExtendedCost`=5564 AND `type`=1); -- Aged Pauldrons of The Five Thunders
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122374 AND `ExtendedCost`=5564 AND `type`=1); -- Prized Beastmaster's Mantle
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122359 AND `ExtendedCost`=5563 AND `type`=1); -- Preened Ironfeather Shoulders
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122358 AND `ExtendedCost`=5564 AND `type`=1); -- Stained Shadowcraft Spaulders
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122377 AND `ExtendedCost`=5564 AND `type`=1); -- Lasting Feralheart Spaulders
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122376 AND `ExtendedCost`=5564 AND `type`=1); -- Exceptional Stormshroud Shoulders
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122360 AND `ExtendedCost`=5564 AND `type`=1); -- Tattered Dreadmist Mantle
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122378 AND `ExtendedCost`=5564 AND `type`=1); -- Exquisite Sunderseer Mantle
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=150743 AND `ExtendedCost`=6196 AND `type`=1); -- -Unknown-
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=150746 AND `ExtendedCost`=6196 AND `type`=1); -- -Unknown-
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=151615 AND `ExtendedCost`=6194 AND `type`=1); -- -Unknown-
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=151614 AND `ExtendedCost`=6195 AND `type`=1); -- -Unknown-
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122341 AND `ExtendedCost`=5556 AND `type`=1); -- Timeworn Heirloom Scabbard
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122340 AND `ExtendedCost`=5555 AND `type`=1); -- Timeworn Heirloom Armor Casing
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122339 AND `ExtendedCost`=5546 AND `type`=1); -- Ancient Heirloom Scabbard
UPDATE `npc_vendor` SET `VerifiedBuild`=25996 WHERE (`entry`=6294 AND `item`=122338 AND `ExtendedCost`=5545 AND `type`=1); -- Ancient Heirloom Armor Casing
UPDATE `creature_template` SET `npcflag`=`npcflag`|128 WHERE `entry` IN (4941,34601,40554);
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=5594 AND `maxcount`>0 AND `incrtime`=0; 
UPDATE `npc_vendor` SET `incrtime`=10800 WHERE `entry`=11185 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=7200 WHERE `entry`=11188 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=1200 WHERE `entry`=11189 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=7500 WHERE `entry`=12959 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=15174 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=23896 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=40226 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=10800 WHERE `entry`=41493 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=44280 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=44283 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=9000 WHERE `entry`=48552 AND `maxcount`>0 AND `incrtime`=0;
UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=4941 AND `maxcount`>0 AND `incrtime`=0;
