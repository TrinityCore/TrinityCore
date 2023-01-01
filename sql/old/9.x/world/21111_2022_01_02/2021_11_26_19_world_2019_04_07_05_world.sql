-- 
DELETE FROM `skill_fishing_base_level` WHERE `entry`=4493;
INSERT INTO `skill_fishing_base_level` (`entry`,`skill`) VALUES
(4493,550);
DELETE FROM `fishing_loot_template` WHERE `entry`=4493;
INSERT INTO `fishing_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(4493, 7078, 0, 4, 0, 1, 0, 1, 1, "The Obsidian Sanctum"),
(4493, 6297, 0, 100, 0, 32768, 0, 1, 1, "The Obsidian Sanctum"),
(4493, 3857, 0, 96, 0, 1, 0, 1, 1, "The Obsidian Sanctum");
