--
UPDATE `creature_template` SET lootid=34884 WHERE entry=34884;
DELETE FROM `creature_loot_template` WHERE entry=34884;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(34884, 117, 0, 13.95, 0, 1, 1, 1, 1, 'Tough Jerky'),
(34884, 159, 0, 7.59, 0, 1, 1, 1, 1, 'Refreshing Spring Water'),
(34884, 805, 0, 2.25, 0, 1, 1, 1, 1, 'Small Red Pouch'),
(34884, 828, 0, 1.56, 0, 1, 1, 1, 1, 'Small Blue Pouch'),
(34884, 2589, 0, 0.05, 0, 1, 1, 1, 1, 'Linen Cloth'),
(34884, 4496, 0, 1.46, 0, 1, 1, 1, 1, 'Small Brown Pouch'),
(34884, 5571, 0, 1.75, 0, 1, 1, 1, 1, 'Small Black Pouch'),
(34884, 5572, 0, 1.51, 0, 1, 1, 1, 1, 'Small Green Pouch'),
(34884, 23329, 0, 0.03, 0, 1, 1, 1, 1, 'Enriched Lasher Root'),
(34884, 23332, 0, 0.03, 0, 1, 1, 1, 1, 'Withered Lasher Root'),
(34884, 62772, 0, 0.04, 0, 1, 1, 1, 1, 'Drop of Slime');
