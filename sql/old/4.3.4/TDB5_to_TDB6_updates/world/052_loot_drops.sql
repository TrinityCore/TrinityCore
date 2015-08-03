-- Quest #25063 Terrapination - Add the Turtle-Digested Key loot to the NPC
DELETE FROM `creature_loot_template` WHERE `entry` = 5431 AND `item` = 52282;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(5431, 52282, -75, 1, 0, 1, 1);
