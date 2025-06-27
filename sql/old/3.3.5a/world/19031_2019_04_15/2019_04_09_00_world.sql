-- 
DELETE FROM `reference_loot_template` WHERE `Entry`=11799 AND `Item` IN (45188, 45189, 4813, 5369, 45907, 779,45190);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(11799, 45188, 0, 2, 0, 32768, 1, 1, 1, ""),
(11799, 45189, 0, 2, 0, 32768, 1, 1, 1, ""),
(11799, 4813, 0, 2, 0, 32768, 1, 1, 1, ""),
(11799, 5369, 0, 2, 0, 32768, 1, 1, 1, ""),
(11799, 45907, 0, 2, 0, 32768, 1, 1, 1, ""),
(11799, 779, 0, 2, 0, 32768, 1, 1, 1, ""),
(11799, 45190, 0, 3, 0, 32768, 1, 1, 1, "");

DELETE FROM `reference_loot_template` WHERE `Entry`=11000 AND `Item` IN (6303, 6308, 6643, 6645, 6289);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(11000, 6303, 0, 15, 0, 1, 1, 1, 1, ""),
(11000, 6308, 0, 10, 0, 1, 1, 1, 1, ""),
(11000, 6643, 0, 2, 0, 1, 1, 1, 1, ""),
(11000, 6645, 0, 2, 0, 1, 1, 1, 1, ""),
(11000, 6289, 0, 25, 0, 1, 1, 1, 1, "");

DELETE FROM `skill_fishing_base_level` WHERE `entry`=4416;
INSERT INTO `skill_fishing_base_level` (`entry`,`skill`) VALUES
(4416,550);
