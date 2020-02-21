-- Rom'Ogg Bonecrusher
UPDATE `creature_template` SET `lootId`= `entry` WHERE `entry` IN (39665, 39666);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (39665, 39666);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(39665, 55777, 0, 0, 1, 1, 1, 1),
(39665, 55778, 0, 0, 1, 1, 1, 1),
(39665, 55278, 0, 0, 1, 1, 1, 1),
(39665, 55279, 0, 0, 1, 1, 1, 1),
(39665, 55776, 0, 0, 1, 1, 1, 1),
-- Heroic
(39666, 56312, 0, 0, 1, 1, 1, 1),
(39666, 56314, 0, 0, 1, 1, 1, 1),
(39666, 56311, 0, 0, 1, 1, 1, 1),
(39666, 56313, 0, 0, 1, 1, 1, 1),
(39666, 56310, 0, 0, 1, 1, 1, 1);

-- Corla, Herald of Twilight
UPDATE `creature_template` SET `lootId`= `entry` WHERE `entry` IN (39679, 39680);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (39679, 39680);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(39679, 55267, 0, 0, 1, 1, 1, 1),
(39679, 55263, 0, 0, 1, 1, 1, 1),
(39679, 55264, 0, 0, 1, 1, 1, 1),
(39679, 55265, 0, 0, 1, 1, 1, 1),
(39679, 55266, 0, 0, 1, 1, 1, 1),
-- Heroic
(39680, 56296, 0, 0, 1, 1, 1, 1),
(39680, 56298, 0, 0, 1, 1, 1, 1),
(39680, 56297, 0, 0, 1, 1, 1, 1),
(39680, 56299, 0, 0, 1, 1, 1, 1),
(39680, 56295, 0, 0, 1, 1, 1, 1);

-- Karsh Steelbender
UPDATE `creature_template` SET `lootId`= `entry` WHERE `entry` IN (39698, 39699);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (39698, 39699);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(39698, 55272, 0, 0, 1, 1, 1, 1),
(39698, 55271, 0, 0, 1, 1, 1, 1),
(39698, 55270, 0, 0, 1, 1, 1, 1),
(39698, 55268, 0, 0, 1, 1, 1, 1),
(39698, 55269, 0, 0, 1, 1, 1, 1),
-- Heroic
(39699, 56302, 0, 0, 1, 1, 1, 1),
(39699, 56300, 0, 0, 1, 1, 1, 1),
(39699, 56304, 0, 0, 1, 1, 1, 1),
(39699, 56301, 0, 0, 1, 1, 1, 1),
(39699, 56303, 0, 0, 1, 1, 1, 1);

-- Beauty
UPDATE `creature_template` SET `lootId`= `entry` WHERE `entry` IN (39700, 39701);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (39700, 39701);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(39700, 55277, 0, 0, 1, 1, 1, 1),
(39700, 55274, 0, 0, 1, 1, 1, 1),
(39700, 55275, 0, 0, 1, 1, 1, 1),
(39700, 55273, 0, 0, 1, 1, 1, 1),
(39700, 55276, 0, 0, 1, 1, 1, 1),
-- Heroic
(39701, 56306, 0, 0, 1, 1, 1, 1),
(39701, 56308, 0, 0, 1, 1, 1, 1),
(39701, 56305, 0, 0, 1, 1, 1, 1),
(39701, 56309, 0, 0, 1, 1, 1, 1),
(39701, 56307, 0, 0, 1, 1, 1, 1);
