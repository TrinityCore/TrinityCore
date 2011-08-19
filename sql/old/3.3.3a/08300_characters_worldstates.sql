DELETE FROM `worldstates` WHERE `entry` IN (20003);
INSERT INTO `worldstates` (`entry`,`value`, `comment`) VALUES 
(20003, 0, 'NextBGRandomDailyResetTime');
