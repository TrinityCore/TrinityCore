-- Quest #26485 Snapjaws, Lad! - Add the Snapjaw Gizzard loot to the NPC
DELETE FROM `creature_loot_template` WHERE `entry` = 2505 AND `item` = 58867;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(2505, 58867, -75, 1, 0, 1, 1);
