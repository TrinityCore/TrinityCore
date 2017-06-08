DELETE FROM `command` WHERE `name` = 'debug play music';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug play music', 318, 'Syntax: .debug play music #musicId

Play music with #musicId.
Music will be play only for you. Other players do not hear this.
Warning: client may have more 5000 sounds...');
