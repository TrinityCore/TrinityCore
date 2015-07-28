-- Readd loot to Stinky
DELETE FROM `creature_loot_template` WHERE `entry` IN(37025,38064);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`)
VALUES
(37025,1,100,1,0,-35069,2),
(38064,1,100,1,0,-35069,2);
