--
DELETE FROM `creature_loot_template` WHERE `Entry` IN (126,515) AND `Item` = 57756;
DELETE FROM `creature_loot_template` WHERE `Entry`= 500 AND `Item` = 57755;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(126, 57756, 0, 21, 1, 1, 0, 1, 1, NULL),
(500, 57755, 0, 29, 1, 1, 0, 1, 1, NULL),
(515, 57756, 0, 23, 1, 1, 0, 1, 1, NULL);
