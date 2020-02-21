-- Ascendant Lord Obsidius
UPDATE `creature_template` SET `lootId`= `entry` WHERE `entry` IN (39705, 39706);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (3970500, 3970600);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(3970500, 55782, 0, 0, 1, 1, 1, 1),
(3970500, 55788, 0, 0, 1, 1, 1, 1),
(3970500, 55783, 0, 0, 1, 1, 1, 1),
(3970500, 55785, 0, 0, 1, 1, 1, 1),
(3970500, 55781, 0, 0, 1, 1, 1, 1),
(3970500, 55786, 0, 0, 1, 1, 1, 1),
(3970500, 55779, 0, 0, 1, 1, 1, 1),
(3970500, 55780, 0, 0, 1, 1, 1, 1),
(3970500, 55784, 0, 0, 1, 1, 1, 1),
(3970500, 55787, 0, 0, 1, 1, 1, 1),
-- Heroic
(3970600, 56317, 0, 0, 1, 1, 1, 1),
(3970600, 56322, 0, 0, 1, 1, 1, 1),
(3970600, 56316, 0, 0, 1, 1, 1, 1),
(3970600, 56321, 0, 0, 1, 1, 1, 1),
(3970600, 56319, 0, 0, 1, 1, 1, 1),
(3970600, 56324, 0, 0, 1, 1, 1, 1),
(3970600, 56318, 0, 0, 1, 1, 1, 1),
(3970600, 56315, 0, 0, 1, 1, 1, 1),
(3970600, 56323, 0, 0, 1, 1, 1, 1),
(3970600, 56320, 0, 0, 1, 1, 1, 1);

DELETE FROM `creature_loot_template` WHERE `Entry` IN (39705, 39706);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal
(39705, 3970500, 3970500, 100, 0, 1, 0, 2, 2),
-- Heroic
(39706, 3970600, 3970600, 100, 0, 1, 0, 2, 2),
(39706, 52078, 0, 100, 0, 1, 1, 1, 1); -- Chaos Orb
