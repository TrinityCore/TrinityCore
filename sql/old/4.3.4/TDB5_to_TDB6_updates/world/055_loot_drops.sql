-- Quest #27592 Drinks on the Rocks - Silt Crawler needs to drop quest item "Stolen Silversnap Ice"
DELETE FROM `creature_loot_template` WHERE `entry` = 922 AND `item` = 61356;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(922, 61356, -100, 1, 0, 1, 1);
