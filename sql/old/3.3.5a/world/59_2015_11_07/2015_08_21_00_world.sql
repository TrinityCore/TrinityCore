DELETE FROM `reference_loot_template` WHERE `Entry`=10018 AND `Item`=54469;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(10018, 54469, 0, 5, 0, 1, 3, 1, 1, NULL);
