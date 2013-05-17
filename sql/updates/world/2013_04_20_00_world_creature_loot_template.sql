-- Insert Frozen Orb into The Prophet Tharon'ja's loot template
DELETE FROM `creature_loot_template` WHERE `entry`=31360 and `item`=43102;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(31360,43102,100,1,0,1,1);
