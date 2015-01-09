SET @exists = (SELECT 1 FROM `creature_loot_template` WHERE `entry`=100002);
DELETE FROM `creature_loot_template` WHERE `entry`=100002 AND @exists = 1;
DELETE FROM `creature_loot_template` WHERE `mincountOrRef`=-35069 AND @exists = 1;
INSERT INTO `creature_loot_template`(`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) SELECT `entry`,1,100,1,0,-35069,2 FROM `creature_template` WHERE `lootid` = 100002 AND @exists = 1; -- 2 selection from reference
UPDATE `creature_template` SET `lootid`=`entry` WHERE `lootid` = 100002 AND @exists = 1;
