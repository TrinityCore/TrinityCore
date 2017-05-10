-- Add The Pewter Pounder to the loot template of King Gurboggle
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/55805

UPDATE `creature_template` SET `lootid`=41018 WHERE `entry`=41018;

DELETE FROM `creature_loot_template` WHERE `entry`=41018 and `item`=55805;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(41018,55805,-100,1,0,1,1);
