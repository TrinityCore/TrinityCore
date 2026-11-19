-- Add Fresh Crawler Meat to the loot template of Pygmy Surf Crawler
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/52080
UPDATE `creature_template` SET `lootid`=39004 WHERE `entry`=39004;
DELETE FROM `creature_loot_template` WHERE `entry`=39004 and `item`=52080;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(39004,52080,-100,1,0,1,1);
