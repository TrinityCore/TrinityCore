ALTER TABLE `world_quest_reward` ADD COLUMN `rewardContext` INT(11) UNSIGNED DEFAULT 0 NOT NULL AFTER `rewardCount`;
