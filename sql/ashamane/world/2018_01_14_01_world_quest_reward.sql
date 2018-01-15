DROP TABLE IF EXISTS `world_quest_reward`;
CREATE TABLE `world_quest_reward`(
    `id` INT(11) UNSIGNED NOT NULL,
    `questType` MEDIUMINT(8) UNSIGNED NOT NULL,
    `rewardType` ENUM('ITEM','CURRENCY','GOLD') NOT NULL,
    `rewardId` INT(11) UNSIGNED NOT NULL,
    `rewardCount` INT(11),
    PRIMARY KEY (`id`, `questType`, `rewardType`, `rewardId`)
);
