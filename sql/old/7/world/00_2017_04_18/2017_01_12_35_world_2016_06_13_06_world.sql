DELETE FROM `gameobject_loot_template` WHERE `Entry` in(2515,2514) AND `Item`=2452;

INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(2515, 2452, 0, 40, 0, 1, 0, 1, 2, NULL),
(2514, 2452, 0, 20, 0, 1, 0, 1, 2, NULL);
