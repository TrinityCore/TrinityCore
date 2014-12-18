DELETE FROM `command` WHERE `name`='pvpstats';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('modify xp', 797, 'Syntax: .modify xp #xp

Gives experience points to the targeted player or self.');
