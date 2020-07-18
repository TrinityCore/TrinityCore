-- Young Thistle Boar - Skinning Loot
UPDATE `creature_template` SET `skinloot`=1984 WHERE  `entry`=1984;
DELETE FROM `skinning_loot_template` WHERE `Entry`=1984;
INSERT INTO `skinning_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1984, 2934, 0, 80, 0, 1, 1, 1, 1, NULL);
