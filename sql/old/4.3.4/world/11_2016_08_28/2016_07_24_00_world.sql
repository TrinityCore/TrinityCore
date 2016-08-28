--
UPDATE `creature_loot_template` SET `Chance`=31, `QuestRequired`=1 WHERE `entry`=18341 AND `item`=28558;

DELETE FROM `creature_loot_template` WHERE `entry`=18341 AND `item`=72126;
INSERT INTO `creature_loot_template` VALUES
(18341, 72126, 0, 100, 1, 1, 0, 1, 1, "");
