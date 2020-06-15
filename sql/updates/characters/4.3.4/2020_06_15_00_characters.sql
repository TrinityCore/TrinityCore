-- 
DELETE FROM `worldstates` WHERE `entry` IN (20006, 20007, 20008);
INSERT INTO `worldstates` (`entry`,`value`,`comment`) VALUES
(20006,0,'NextGuildDailyResetTime'),
(20007,0,'NextMonthlyQuestResetTime'),
(20008,0,'NextDailyQuestResetTime');
