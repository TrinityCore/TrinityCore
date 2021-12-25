-- 
UPDATE `worldstates` SET `comment`='NextGuildDailyResetTime' WHERE `entry`=20006;
UPDATE `worldstates` SET `comment`='NextMonthlyQuestResetTime' WHERE `entry`=20007;
INSERT INTO `worldstates` (`entry`,`value`,`comment`) VALUES (20008,0,'NextDailyQuestResetTime');
