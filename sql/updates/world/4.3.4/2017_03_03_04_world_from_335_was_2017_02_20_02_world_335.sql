/*
DELETE FROM `creature_loot_template` WHERE `Item` IN (10780, 10781, 10782);
DELETE FROM `item_loot_template` WHERE `Item` IN (10780, 10781, 10782);
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(10773, 10780, 0, 100, 0, 1, 0, 1, 1), -- Mark of Hakkar
(10773, 10781, 0, 100, 0, 1, 1, 1, 1), -- Hakkari Breastplate
(10773, 10782, 0, 100, 0, 1, 2, 1, 1); -- Hakkari Shroud
*/
