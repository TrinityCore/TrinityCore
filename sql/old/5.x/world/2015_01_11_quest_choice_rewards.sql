DROP TABLE IF EXISTS `quest_choice_rewards`;
CREATE TABLE `quest_choice_rewards` (
	`questId` MEDIUMINT(8) NOT NULL,
	`rewardItemId` MEDIUMINT(8) NOT NULL,
	`rewardItemCount` SMALLINT(5) NOT NULL DEFAULT '1',
	`class` TINYINT(3) NOT NULL DEFAULT '-1',
	PRIMARY KEY (`questId`, `rewardItemId`, `class`)
)
COMMENT='Quest Choice Rewards.\r\nIf class = -1 reward is for every class'
COLLATE='utf8_general_ci'
ENGINE=InnoDB;

DELETE FROM `quest_choice_rewards` WHERE `questId` = 31133;
INSERT INTO `quest_choice_rewards` (`questId`, `rewardItemId`, `rewardItemCount`, `class`) VALUES 
(31133, 84618, 1, 10),
(31133, 84618, 1, 11),
(31133, 84622, 1, 10),
(31133, 84620, 1, 2),
(31133, 84624, 1, 2),
(31133, 84625, 1, 2),
(31133, 84617, 1, 5),
(31133, 84622, 1, 4),
(31133, 84619, 1, 7),
(31133, 84623, 1, 7),
(31133, 84621, 1, 9),
(31133, 84624, 1, 1),
(31133, 84625, 1, 1),
(31133, 84620, 1, 11),
(31133, 84621, 1, 8),
(31133, 84623, 1, 3),
(31133, 84624, 1, 6),
(31133, 84625, 1, 6);
