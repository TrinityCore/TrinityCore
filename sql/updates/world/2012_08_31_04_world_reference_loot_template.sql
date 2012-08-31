-- Add new ref to ICC 5man hc Trash Ref (0.08 percent is average of values on wowhead 4.16/52)
DELETE FROM `reference_loot_template` WHERE `entry`=35073 AND `item`=9 AND `mincountOrRef`=-35075;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(35073, 9, 0.08, 1, 0, -35075, 1);