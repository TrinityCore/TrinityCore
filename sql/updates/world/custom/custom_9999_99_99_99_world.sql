DELETE FROM `command` WHERE `name`='bnetaccount listgameaccounts';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('bnetaccount listgameaccounts', 830, 'Syntax: .bnetaccount listgameaccounts $email $password\nLists all game accounts linked to battle.net $email');

DELETE FROM `trinity_string` WHERE `entry` IN (1030, 1032, 1033, 1034, 1035);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1030, 'You are attempting to create a battle.net account with wrong command, use .bnetaccount create'),
(1032, 'Battle.net account created: %s with game account %s'),
(1033, 'Battle.net account created: %s'),
(1034, '| Account Id |  Internal name   |   Display name   |'),
(1035, 'Battle.net account %s has no linked game accounts.');
