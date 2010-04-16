ALTER TABLE `worldstates` ADD COLUMN `NextWeeklyQuestResetTime` bigint(40) unsigned NOT NULL default '0' AFTER `value`;
