ALTER TABLE `worldstates` DROP COLUMN `NextWeeklyQuestResetTime`;
INSERT INTO `worldstates` (`entry`,`value`, `comment`) VALUES (20002, 0, 'NextWeeklyQuestResetTime');
