-- Abyssion should have the fragment in his loot template. He currently has no loot at all.
UPDATE `creature_template` SET `lootid`=44289 WHERE `entry`=44289;
DELETE FROM `creature_loot_template` WHERE `entry`=44289 and`item`=60574;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(44289,60574,-100,1,0,1,1);
