-- Crag boar
DELETE FROM `creature_loot_template` WHERE `Entry`=1125;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(1125, 2886,      0,      45, 0, 1, 1, 1, 1, "Crag Boar Rib"),
(1125, 769,       0,      35, 0, 1, 1, 1, 1, "Chunk of Boar Meat"),
(1125, 117,       0,      10, 0, 1, 1, 1, 1, "Tough Jerky"),
(1125, 771,       0,      35, 0, 1, 0, 1, 1, "Chipped Boar Tusk"),
(1125, 3171,      0,      35, 0, 1, 0, 1, 1, "Broken Boar Tusk"),
(1125, 24073, 24073,     2.5, 0, 1, 2, 1, 1, "Junk gear"),
(1125, 24700, 24700,       1, 0 ,1, 2, 1, 1, "Patterns"),
(1125, 24701, 24701,       1, 0 ,1, 2, 1, 1, "Patterns"),
(1125, 11111, 11111,     0.1, 0, 1, 3, 1, 1, "Bags");
