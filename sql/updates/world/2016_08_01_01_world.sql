--
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (25343);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(25343, 40744, 0, 100, 1, 1, 0, 1, 1, 'Unfortunate Snobold contains Impure Saronite Ore');
