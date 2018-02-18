/*
-- Ragged Timber Wolf
DELETE FROM `creature_loot_template` WHERE `Entry`=704;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(704,   750,     0, 100, 1, 1, 0, 1, 1, "Tough Wolf Meat (quest)"),
(704,  4865,     0,  20, 0, 1, 1, 1, 2, "Ruined Pelt"),
(704,  3300,     0,  30, 0, 1, 1, 1, 2, "Rabbit's Foot"),
(704,  7074,     0,  20, 0, 1, 1, 1, 2, "Chipped Claw"),
(704,  7073,     0,  30, 0, 1, 1, 1, 2, "Broken Fang"),
(704, 24073, 24073,   1, 0, 1, 0, 1, 1, "Junk"),
(704, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags");

-- Ragged Young Wolf
DELETE FROM `creature_loot_template` WHERE `Entry`=705;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(705,   750,     0, 100, 1, 1, 0, 1, 1, "Tough Wolf Meat (quest)"),
(705,  4865,     0,  20, 0, 1, 1, 1, 2, "Ruined Pelt"),
(705,  3300,     0,  30, 0, 1, 1, 1, 2, "Rabbit's Foot"),
(705,  7074,     0,  20, 0, 1, 1, 1, 2, "Chipped Claw"),
(705,  7073,     0,  30, 0, 1, 1, 1, 2, "Broken Fang"),
(705, 24073, 24073,   1, 0, 1, 0, 1, 1, "Junk"),
(705, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags");

-- Frostmane Troll Whelp
DELETE FROM `creature_loot_template` WHERE `Entry`=706;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(706,   117,     0,  15, 0, 1, 0, 1, 1, "Tough Jerky"),
(706,   159,     0,  10, 0, 1, 0, 1, 1, "Refreshing Spring Water"),
(706,  2108,     0,   1, 0, 1, 0, 1, 1, "Frostmane Leather Vest (unique)"),
(706, 24073, 24073,   5, 0, 1, 0, 1, 1, "Junk"),
(706, 11111, 11111, 0.5, 0, 1, 0, 1, 1, "Bags");

-- Rockjaw Trogg
DELETE FROM `creature_loot_template` WHERE `Entry`=707;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(707,   117,     0,  15, 0, 1, 0, 1, 1, "Tough Jerky"),
(707,   159,     0,  10, 0, 1, 0, 1, 1, "Refreshing Spring Water"),
(707, 24073, 24073,   5, 0, 1, 0, 1, 1, "Junk"),
(707, 11111, 11111, 0.5, 0, 1, 0, 1, 1, "Bags");

-- Small Crag Boar
DELETE FROM `creature_loot_template` WHERE `Entry`=708;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(708,   117,     0,  30, 0, 1, 0, 1, 2, "Tough Jerky"),
(708,   771,     0,  30, 0, 1, 1, 1, 2, "Chipped Boar Tusk"),
(708,  4865,     0,  35, 0, 1, 1, 1, 2, "Ruined Pelt"),
(708,  7098,     0,  35, 0, 1, 1, 1, 2, "Splintered Tusk"),
(708, 24073, 24073,   2, 0, 1, 0, 1, 1, "Junk"),
(708, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags");

-- Burly Rockjaw Trogg
DELETE FROM `creature_loot_template` WHERE `Entry`=724;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(724,   117,     0,  15, 0, 1, 0, 1, 1, "Tough Jerky"),
(724,   159,     0,  10, 0, 1, 0, 1, 1, "Refreshing Spring Water"),
(724,  2787,     0,   1, 0, 1, 0, 1, 1, "Trogg Dagger (unique)"),
(724, 24073, 24073,   5, 0, 1, 0, 1, 1, "Junk"),
(724, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags");

-- Grik'nir the Cold
DELETE FROM `creature_loot_template` WHERE `Entry`=808;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(808,   117,     0,  15, 0, 1, 0, 1, 1, "Tough Jerky"),
(808,   159,     0,  10, 0, 1, 0, 1, 1, "Refreshing Spring Water"),
(808,  2004,     0, 100, 1, 1, 0, 1, 1, "Grelin Whitebeard's Journal (quest)"),
(808,  2109,     0,   1, 0, 1, 0, 1, 1, "Frostmane Chain Vest (unique)"),
(808, 24073, 24073,  35, 0, 1, 0, 1, 1, "Junk"),
(808, 11111, 11111,   1, 0, 1, 0, 1, 1, "Bags");

-- Frostmane Novice
DELETE FROM `creature_loot_template` WHERE `Entry`=946;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(946,   117,     0,  15, 0, 1, 0, 1, 1, "Tough Jerky"),
(946,   159,     0,  10, 0, 1, 0, 1, 1, "Refreshing Spring Water"),
(946,  2110,     0,   1, 0, 1, 0, 1, 1, "Light Magesmith Robe (unique)"),
(946, 24073, 24073,   5, 0, 1, 0, 1, 1, "Junk"),
(946, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags");

-- Rockjaw Raider
DELETE FROM `creature_loot_template` WHERE `Entry`=1718;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1718,   117,     0,  15, 0, 1, 0, 1, 1, "Tough Jerky"),
(1718,   159,     0,  10, 0, 1, 0, 1, 1, "Refreshing Spring Water"),
(1718,  2054,     0,   1, 0, 1, 0, 1, 1, "Trogg Hand Axe (unique)"),
(1718, 24073, 24073,   5, 0, 1, 0, 1, 1, "Junk"),
(1718, 11111, 11111, 0.1, 0, 1, 0, 1, 1, "Bags");
*/
