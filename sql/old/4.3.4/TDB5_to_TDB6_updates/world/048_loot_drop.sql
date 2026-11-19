-- Twilight Jasmine - Creates the loot
DELETE FROM `gameobject_loot_template` WHERE `entry` = 28525 AND `item` IN (52987, 52329, 63122);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(28525, 52987, 100, 1, 0, 2, 9),
(28525, 52329, 39, 1, 0, 1, 3),
(28525, 63122, 10, 1, 0, 1, 1);
