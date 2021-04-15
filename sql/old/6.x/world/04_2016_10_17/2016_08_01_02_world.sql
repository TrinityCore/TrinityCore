--
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (15561, 22937);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(15561, 17411, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Steamsaw contains item Steamsaw'),
(22937, 34102, 0, 100, 1, 1, 0, 1, 3, 'Gameobject Loose Rock contains item Fjord Grub');
