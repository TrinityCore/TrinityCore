-- loot for Prismatic Black Diamond
DELETE FROM `spell_loot_template` WHERE `entry`=62941;
INSERT INTO `spell_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(62941, 23094, 0, 1, 1, 1, 1),
(62941, 23095, 0, 1, 1, 1, 1),
(62941, 28595, 0, 1, 1, 1, 1),
(62941, 23116, 0, 1, 1, 1, 1),
(62941, 23118, 0, 1, 1, 1, 1),
(62941, 23119, 0, 1, 1, 1, 1),
(62941, 23120, 0, 1, 1, 1, 1),
(62941, 23114, 0, 1, 1, 1, 1),
(62941, 23115, 0, 1, 1, 1, 1);
