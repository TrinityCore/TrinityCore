DELETE FROM `command` WHERE `permission`=698;
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('character changeaccount', 698, 'Syntax: .character changeaccount [$player] $account\n\nTransfers ownership of named (or selected) character to another account');

DELETE FROM `Kitron_string` WHERE `entry`=1184;
INSERT INTO `Kitron_string` (`entry`, `content_default`) VALUES
(1184, 'Successfully transferred ownership of character %s to account %s');
