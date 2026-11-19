ALTER TABLE `reputation_reward_rate` ADD `quest_daily_rate` FLOAT NOT NULL DEFAULT '1' AFTER `quest_rate`;
ALTER TABLE `reputation_reward_rate` ADD `quest_weekly_rate` FLOAT NOT NULL DEFAULT '1' AFTER `quest_daily_rate`;
