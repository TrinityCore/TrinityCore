ALTER TABLE `lfg_dungeon_rewards`
	ADD COLUMN `rewardsPerPeriod` TINYINT(3) UNSIGNED DEFAULT 1 NOT NULL COMMENT 'Maximum amount that the first quest may be rewarded' AFTER `otherQuestId`;

UPDATE `lfg_dungeon_rewards` SET `rewardsPerPeriod`= 7 WHERE `dungeonId` IN (258, 259, 260, 261, 262);

DELETE FROM `lfg_dungeon_rewards` WHERE `dungeonId` IN (300, 301, 2447, 2470, 2485, 2735, 2760, 2881, 434, 416, 417);
INSERT INTO `lfg_dungeon_rewards` (`dungeonId`, `maxLevel`, `firstQuestId`, `otherQuestId`, `rewardsPerPeriod`) VALUES
(300,  85, 28907, 28908, 7),
(301,  85, 28905, 28906, 1),
(2735, 85, 29185, 29183, 1),
(2760, 85, 86553, 86553, 1),
(2881, 85, 86554, 86553, 1),
(416, 85, 30110, 30111, 1),
(417, 85, 30110, 30111, 1);
