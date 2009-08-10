DELETE FROM `command` WHERE `name` = 'reload autobroadcast';
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('reload autobroadcast', 3, 'Syntax: .reload autobroadcast\nReload autobroadcast table.');
