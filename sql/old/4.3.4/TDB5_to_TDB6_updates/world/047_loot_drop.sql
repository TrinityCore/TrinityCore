-- Stromvine - Creates the loot
DELETE FROM `gameobject_loot_template` WHERE `entry` = 28522 AND `item` IN (52984, 52329, 63122);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(28522, 52984, 100, 1, 0, 1, 9),
(28522, 52329, 39, 1, 0, 1, 4),
(28522, 63122, 10, 1, 0, 1, 1);
