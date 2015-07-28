-- Quest #24933 Chicken of the Desert - Add the Hyena Chunk loot to the NPC
DELETE FROM `creature_loot_template` WHERE `entry` = 5427 AND `item` = 51778;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(5427, 51778, -75, 1, 0, 1, 1);
