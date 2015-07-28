-- Quest #25021 Blood to Thrive - Add the Fistful of Blood loot to the NPC
DELETE FROM `creature_loot_template` WHERE `entry` IN (5646, 5647, 5645) AND `item` = 52064;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(5646, 52064, -90, 1, 0, 1, 1),
(5647, 52064, -90, 1, 0, 1, 1),
(5645, 52064, -90, 1, 0, 1, 1);
