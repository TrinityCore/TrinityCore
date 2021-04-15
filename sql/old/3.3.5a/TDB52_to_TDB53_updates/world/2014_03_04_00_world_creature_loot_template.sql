--
DELETE FROM `creature_loot_template` WHERE `entry` IN(21601,21599);
INSERT INTO `creature_loot_template` VALUES 
(21601, 23572, 100, 1, 0, 1, 1),
(21601, 25004, 100, 1, 2, -25004, 1),
(21601, 25005, 100, 1, 3, -25005, 1),
(21601, 29434, 100, 1, 0, 1, 1),
(21601, 33861, -100, 1, 0, 1, 1),
(21601, 43000, 10, 1, 1, -43000, 1),
(21601, 43003, 100, 1, 4, -43003, 1);

UPDATE `creature_template` SET `lootid`=21601, `questItem1`=33861 WHERE `entry`=21601;
UPDATE `creature_template` SET `lootid`=0, `questItem1`=0 WHERE `entry`=21599;
