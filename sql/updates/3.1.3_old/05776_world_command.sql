DELETE FROM `command` WHERE `name` = 'account addon';
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('account addon', 3, 'Syntax: .account addon #addon\nSet expansion addon level allowed. Addon values: 0 - normal, 1 - tbc, 2 - wotlk.');
