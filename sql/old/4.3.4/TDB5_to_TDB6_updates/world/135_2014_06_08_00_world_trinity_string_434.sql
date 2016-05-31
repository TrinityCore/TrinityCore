DELETE FROM `trinity_string` WHERE `entry`=1029;

INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1029, 'Account name must contain the @ symbol.');

DELETE FROM `command` WHERE `permission` IN (207,208,209,210,211,212,213);
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('battlenetaccount', 207, 'Syntax: .battlenetaccount $subcommand\r\nType .battlenetaccount to see the list of possible subcommands or .help account set $subcommand to see info on subcommands.'),
('battlenetaccount create', 208, 'Syntax: .battlenetaccount create $account $password\r\nCreate battle.net account and set password to it. Account must contain the @ symbol.'),
('battlenetaccount lock country', 209, 'Syntax: .battlenetaccount lock country [on|off]\r\nAllow login to account only from current used Country or remove this requirement.'),
('battlenetaccount lock ip', 210, 'Syntax: .battlenetaccount lock ip [on|off]\nAllow login to account only from current used IP or remove this requirement.'),
('battlenetaccount password', 211, 'Syntax: .battlenetaccount password $old_password $new_password $new_password\nChange your account password.'),
('battlenetaccount set', 212, 'Syntax: .battlenetaccount set $subcommand\nType .battlenetaccount set to see the list of possible subcommands or .help account set $subcommand to see info on subcommands.'),
('battlenetaccount set password', 213, 'Syntax: .battlenetaccount set password $account $password $password\nSet password for account.');
