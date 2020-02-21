DELETE FROM `command` WHERE `name` LIKE '%battlenetaccount%';
DELETE FROM `command` WHERE `name` LIKE '%bnetaccount%';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('bnetaccount', 207, 'Syntax: .bnetaccount $subcommand\nType .bnetaccount to see the list of possible subcommands or .help account set $subcommand to see info on subcommands.'),
('bnetaccount create', 208, 'Syntax: .bnetaccount create $account $password\nCreate battle.net account and set password to it. Account must contain the @ symbol.'),
('bnetaccount lock country', 209, 'Syntax: .bnetaccount lock country [on|off]\nAllow login to account only from current used Country or remove this requirement.'),
('bnetaccount lock ip', 210, 'Syntax: .bnetaccount lock ip [on|off]\nAllow login to account only from current used IP or remove this requirement.'),
('bnetaccount password', 211, 'Syntax: .bnetaccount password $old_password $new_password $new_password\nChange your account password.'),
('bnetaccount set', 212, 'Syntax: .bnetaccount set $subcommand\nType .bnetaccount set to see the list of possible subcommands or .help bnetaccount set $subcommand to see info on subcommands.'),
('bnetaccount set password', 213, 'Syntax: .bnetaccount set password $account $password $password\nSet password for account.'),
('bnetaccount link', 214, 'Syntax: .bnetaccount link $email $login\nLinks battle.net account ($email) to an existing game account ($login).'),
('bnetaccount unlink', 215, 'Syntax: .bnetaccount unlink $gameaccount $password\nRemoves battle.net account link from $gameaccount'),
('bnetaccount gameaccountcreate', 216, 'Syntax: .bnetaccount gameaccountcreate $account\nCreate additional game account for specified battle.net account.');

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1185 AND 1189;
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1036 AND 1040;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1036, 'Battle.net account %s was linked with game account %s.'),
(1037, 'Battle.net account %s or game account %s does not exist.'),
(1038, 'Game account %s is already linked with a battle.net account.'),
(1039, 'Game account %s had its battle.net account link removed.'),
(1040, 'Game account %s is not linked to any battle.net account.');
