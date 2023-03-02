DELETE FROM `command` WHERE `permission` = '778';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
	('reset specialization', '778', 'Syntax: .reset spec ');
