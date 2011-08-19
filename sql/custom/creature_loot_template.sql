-- Instructor Hroegar
DELETE FROM `creature_loot_template` WHERE `entry`=29915;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountofRef`,`maxcount`) VALUES 
(29915, 41843, -100, 1, 0, 1, 1),
(29915, 43089, 98, 1, 0, 1, 1),
(29915, 33470, 23, 1, 0, 1, 4),
(29915, 43851, 16, 1, 0, 1, 1),
(29915, 43852, 13, 1, 0, 1, 1),
(29915, 33454, 4, 1, 0, 1, 1),
(29915, 33445, 2, 1, 0, 1, 1),
(29915, 33447, 1.7, 1, 0, 1, 1);