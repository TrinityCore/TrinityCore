-- Replace Furious Weapon drop with drop that should be in the Cache of Living Stone
UPDATE `reference_loot_template` SET `item` =45695 WHERE (`entry` =34361 AND `item` =45965);
-- add missing Recipe: Mighty Shadow Protection Potion on Cultist Shard Watcher
DELETE FROM `creature_loot_template` WHERE `entry`=32349 AND `item`=44568;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(32349,44568,0.5,1,0,1,1);
