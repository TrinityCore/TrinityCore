-- The Imported Supplies needs to contain Cocoa Beans
DELETE FROM `item_loot_template` WHERE `entry` = 68689 AND `item` = 62786;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(68689, 62786, 100, 1, 0, 5, 20);
