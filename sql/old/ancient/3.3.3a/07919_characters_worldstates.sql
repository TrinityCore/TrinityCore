DELETE FROM `worldstates` WHERE `entry` IN (20001,20002);
INSERT INTO `worldstates` (`entry`,`value`, `comment`) VALUES
(20001, 0, 'NextArenaPointDistributionTime'),
(20002, 0, 'NextWeeklyQuestResetTime');
