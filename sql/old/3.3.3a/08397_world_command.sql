DELETE FROM `command` WHERE `name` IN ('instance open','instance close');
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('instance open', 3, 'Syntax: .instance open mapid [normal|heroic|10normal|10heroic|25normal|25heroic]'),
('instance close', 3, 'Syntax: .instance close mapid [normal|heroic|10normal|10heroic|25normal|25heroic]');
