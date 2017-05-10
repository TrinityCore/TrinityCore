-- Thistle Boar - Skinning Loot
UPDATE `creature_template` SET `skinloot`=1985 WHERE  `entry`=1985;
DELETE FROM `skinning_loot_template` WHERE `Entry`=1985;
INSERT INTO `skinning_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1985, 2934, 0, 88, 0, 1, 1, 1, 1, NULL),
(1985, 2318, 0, 10, 0, 1, 1, 1, 1, NULL);
