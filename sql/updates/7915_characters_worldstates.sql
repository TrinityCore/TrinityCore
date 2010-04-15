ALTER TABLE `worldstates` DROP COLOMUN `NextWeeklyQuestResetTime`;
INSERT INTO `worldstates` (`entry`,`value`, `comment`) VALUES (20002, 0, 'NextWeeklyQuestResetTime');
