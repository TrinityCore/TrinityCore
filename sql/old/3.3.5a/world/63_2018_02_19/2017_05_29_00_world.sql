DELETE FROM `command` WHERE `name` = 'debug play music';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug play music', 855, 'Syntax: .debug play music #musicId\nPlay music with #musicId.\nMusic will be played only for you. Other players will not hear this.');
