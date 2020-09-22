UPDATE `creature_template` SET `mingold`= 0, `maxgold`= 0, `lootid`= 0 WHERE `entry` IN (45870, 50103, 45872, 50095);
UPDATE `creature_template` SET `mingold`= 0, `maxgold`= 0, `lootid`= 0 WHERE `entry` IN (50113, 50123, 50105, 50115);

UPDATE `creature_template` SET `mingold`= 2500000, `maxgold`= 2500000, `lootid`= `entry`, `flags_extra`= `flags_extra` | 0x00200000 WHERE `entry` IN (45871, 50108);
UPDATE `creature_template` SET `mingold`= 6250000, `maxgold`= 6250000, `lootid`= `entry`, `flags_extra`= `flags_extra` | 0x00200000 WHERE `entry` IN (50098, 50118);

DELETE FROM `reference_loot_template` WHERE `Entry` IN (458710, 500980);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
-- Normal Difficulty
(458710, 63495, 0, 1, 1, 1, 1),
(458710, 63496, 0, 1, 1, 1, 1),
(458710, 63498, 0, 1, 1, 1, 1),
(458710, 63497, 0, 1, 1, 1, 1),
(458710, 63494, 0, 1, 1, 1, 1),
(458710, 63489, 0, 1, 1, 1, 1),
(458710, 63491, 0, 1, 1, 1, 1),
(458710, 63490, 0, 1, 1, 1, 1),
(458710, 63488, 0, 1, 1, 1, 1),
(458710, 63492, 0, 1, 1, 1, 1),
(458710, 63493, 0, 1, 1, 1, 1),
-- Heroic Difficulty
(500980, 65374, 0, 1, 1, 1, 1),
(500980, 65368, 0, 1, 1, 1, 1),
(500980, 65377, 0, 1, 1, 1, 1),
(500980, 65373, 0, 1, 1, 1, 1),
(500980, 65376, 0, 1, 1, 1, 1),
(500980, 65375, 0, 1, 1, 1, 1),
(500980, 65369, 0, 1, 1, 1, 1),
(500980, 65367, 0, 1, 1, 1, 1),
(500980, 65372, 0, 1, 1, 1, 1),
(500980, 65371, 0, 1, 1, 1, 1),
(500980, 65370, 0, 1, 1, 1, 1);

DELETE FROM `creature_loot_template` WHERE `Entry` IN (45871, 50108, 50098, 50118, 45870, 50103, 45872, 50095, 50113, 50123, 50105, 50115);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(45871, 458710, 458710, 100, 0, 2, 2, 1),
(50098, 458710, 458710, 100, 0, 5, 5, 1),
(50108, 500980, 500980, 100, 0, 2, 2, 1),
(50118, 500980, 500980, 100, 0, 5, 5, 1);
