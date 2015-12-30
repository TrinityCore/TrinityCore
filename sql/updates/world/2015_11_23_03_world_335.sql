-- Mottled Boar - Skinning Loot
UPDATE `creature_template` SET `skinloot`= 3098 WHERE  `entry` = 3098;
DELETE FROM `skinning_loot_template` WHERE `Entry`=3098;
INSERT INTO `skinning_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(3098, 2318, 0, 10, 0, 1, 1, 1, 1, NULL), -- Light Leather, 10% chance
(3098, 2934, 0, 88, 0, 1, 1, 1, 1, NULL); -- Ruined Leather Scraps, 88% chance

-- Scorpid Worker - Skinning Loot
UPDATE `creature_template` SET `skinloot`= 3124 WHERE  `entry` = 3124;
DELETE FROM `skinning_loot_template` WHERE `Entry`= 3124;
INSERT INTO `skinning_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(3124, 2318, 0, 10, 0, 1, 1, 1, 1, NULL), -- Light Leather, 10% chance
(3124, 2934, 0, 88, 0, 1, 1, 1, 1, NULL); -- Ruined Leather Scraps, 88% chance
