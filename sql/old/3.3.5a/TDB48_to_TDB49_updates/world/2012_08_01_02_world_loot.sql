-- Add quest item "Bleeding Hollow Torch" to "Bleeding Hollow Peon" loot template
DELETE FROM `creature_loot_template` WHERE `entry`=16907 and `item`=31347;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(16907,31347,-50,1,0,1,1);
