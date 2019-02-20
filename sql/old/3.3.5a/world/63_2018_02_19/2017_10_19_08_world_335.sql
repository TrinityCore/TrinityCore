-- Item should only drop from Riverpaw Mongrel (123)
DELETE FROM `reference_loot_template` WHERE `Item`=821;
-- Item should only drop from Sandcrawler  (830)
DELETE FROM `reference_loot_template` WHERE `Item`=2087;
-- Item is from crafting and should never drop
DELETE FROM `reference_loot_template` WHERE `Item`=2300;

-- Add unique drops to appropriate NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (821, 2087);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`) VALUES
(123, 821, 2.5),
(830, 2087, 2);

-- Kobold Vermin
DELETE FROM `creature_loot_template` WHERE `Entry`=6;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(6, 755, 0, 50, 0, 1, 0, 1, 1, NULL), -- Melted Candle
(6, 4536, 0, 20, 0, 1, 0, 1, 1, NULL), -- Shiny Red Apple
(6, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(6, 24073, 24073, 10, 0, 1, 0, 1, 1, NULL), -- Junk
(6, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags

-- Kobold Worker
DELETE FROM `creature_loot_template` WHERE `Entry`=257;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(257, 755, 0, 50, 0, 1, 0, 1, 1, NULL), -- Melted Candle
(257, 4536, 0, 20, 0, 1, 0, 1, 1, NULL), -- Shiny Red Apple
(257, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(257, 24073, 24073, 10, 0, 1, 0, 1, 1, NULL), -- Junk
(257, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags

-- Kobold Laborer
-- Also adds unique item missing from game
DELETE FROM `creature_loot_template` WHERE `Entry`=80;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(80, 755, 0, 50, 0, 1, 0, 1, 1, NULL), -- Melted Candle
(80, 4536, 0, 20, 0, 1, 0, 1, 1, NULL), -- Shiny Red Apple
(80, 159, 0, 10, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(80, 24073, 24073, 5, 0, 1, 0, 1, 1, NULL), -- Junk
(80, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL), -- Bags
(80, 2055, 0, 2.5, 0, 1, 0, 1, 1, NULL); -- Small Wooden Hammer (Unique)

-- Diseased Young Wolf
-- Removed drop of level 12-13 green items
DELETE FROM `creature_loot_template` WHERE `Entry`=299;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(299, 4865, 0, 5, 0, 1, 0, 1, 2, NULL), -- Ruined Pelt
(299, 7073, 0, 5, 0, 1, 0, 1, 2, NULL), -- Broken Fang
(299, 7074, 0, 5, 0, 1, 0, 1, 2, NULL), -- Chipped Claw
(299, 50432, 0, 100, 1, 1, 0, 1, 1, NULL), -- Diseased Wolf Pelt (Quest)
(299, 24073, 24073, 1, 0, 1, 0, 1, 1, NULL), -- Junk
(299, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Diseased Timber Wolf
DELETE FROM `creature_loot_template` WHERE `Entry`=69;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(69, 4865, 0, 5, 0, 1, 0, 1, 2, NULL), -- Ruined Pelt
(69, 7073, 0, 5, 0, 1, 0, 1, 2, NULL), -- Broken Fang
(69, 7074, 0, 5, 0, 1, 0, 1, 2, NULL), -- Chipped Claw
(69, 50432, 0, 100, 1, 1, 0, 1, 1, NULL), -- Diseased Wolf Pelt (Quest)
(69, 24073, 24073, 1, 0, 1, 0, 1, 1, NULL), -- Junk
(69, 11111, 11111, 0.1, 0, 1, 0, 1, 1, NULL); -- Bags

-- Defias Thug
DELETE FROM `creature_loot_template` WHERE `Entry`=38;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(38, 752, 0, 100, 1, 1, 0, 1, 1, NULL), -- Red Burlap Bandana (Quest)
(38, 2070, 0, 15, 0, 1, 0, 1, 1, NULL), -- Darnassian Bleu
(38, 159, 0, 5, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(38, 2057, 0, 1.5, 0, 1, 0, 1, 1, NULL), -- Pitted Defias Shorsword (Unique)
(38, 24073, 24073, 10, 0, 1, 0, 1, 1, NULL), -- Junk
(38, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags

-- Garrick Proudfoot
DELETE FROM `creature_loot_template` WHERE `Entry`=103;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(103, 182, 0, 100, 1, 1, 0, 1, 1, NULL),  -- Garrick's Head
(103, 2070, 0, 15, 0, 1, 0, 1, 1, NULL), -- Darnassian Bleu
(103, 159, 0, 5, 0, 1, 0, 1, 1, NULL), -- Refreshing Spring Water
(103, 24073, 24073, 10, 0, 1, 0, 1, 1, NULL), -- Junk
(103, 11111, 11111, 0.5, 0, 1, 0, 1, 1, NULL); -- Bags
