-- Crate of Fossil Archaeology Fragments
DELETE FROM `item_loot_template` WHERE `entry` = 87535;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUE
(87535, -393, 100, 0, 0, 5, 9);