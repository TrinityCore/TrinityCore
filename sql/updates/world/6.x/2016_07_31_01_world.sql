-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (28567,25106);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28567, 34486, 0, 100, 0, 1, 0, 1, 1, 'Gameobject (TESTING) Crafty''s Special Fishing School contains Loot item Old Crafty'),
(25106, 34486, 0, 50, 0, 1, 1, 1, 1, 'Gameobject (TESTING) Rare Fish Node contains Loot item Old Crafty'),
(25106, 34484, 0, 50, 0, 1, 1, 1, 1, 'Gameobject (TESTING) Rare Fish Node contains Loot item Old Ironjaw');
