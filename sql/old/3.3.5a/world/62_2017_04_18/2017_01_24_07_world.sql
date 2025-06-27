-- 
DELETE FROM `disables` WHERE `entry`= 45425;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(0, 45425, 64, '', '', 'Ignore LOS for Shoot (Dummy)');
