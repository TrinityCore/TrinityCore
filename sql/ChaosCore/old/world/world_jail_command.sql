/* World Command English */
DELETE FROM `command` WHERE name IN ('jail','jailinfo','unjail','jailreload');
INSERT INTO `command` (name, security, help) VALUES
('jail', 1, 'Syntax: .jail character hours reason\nJailed the \'character\' for \'hours\' with the \'reason\'.'),
('jailinfo', 0, 'Syntax: .jailinfo\nShows your jail status.'),
('unjail', 1, 'Syntax: .unjail character\nRealeases the \'character\' out of the jail.'),
('jailreload', 3, 'Syntax: .jailreload\nLoads the jail config new.');
