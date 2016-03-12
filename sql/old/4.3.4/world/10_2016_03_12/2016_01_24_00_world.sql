--
DELETE FROM `gameobject_loot_template` WHERE `Entry`=1698;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(1698, 3255, 0, 100, 1, 1, 0, 1, 1, NULL);
