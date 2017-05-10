DELETE FROM `creature_loot_template` WHERE `entry` = 37126;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(37126, 49426, 100, 1, 0, 1, 1),
(37126, 1, 100, 1, 0, -100002, 1);
UPDATE `creature_template` SET `lootid` = 37126 WHERE `entry` IN (37126,38258);
