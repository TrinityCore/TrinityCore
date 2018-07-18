DELETE FROM `worldstates` WHERE `entry` IN (20004,20007,20050);
INSERT INTO `worldstates` (`entry`, `value`, `comment`) VALUES
(20004,0,'CleaningFlags'),
(20007,0,'NextMonthlyQuestResetTime'),
(20050,0,'NextWeeklyGuildResetTime');
