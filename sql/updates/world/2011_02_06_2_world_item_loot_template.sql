-- Insert loot for Gently Shaken Gift
DELETE FROM `item_loot_template` WHERE `entry`=21271;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(21271,21241,100,1,0,5,5);
