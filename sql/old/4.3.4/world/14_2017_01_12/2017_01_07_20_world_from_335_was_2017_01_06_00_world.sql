DELETE FROM `command` WHERE `permission`=698;
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('character changeaccount', 698, 'Syntax: .character changeaccount [$player] $account\n\nTransfers ownership of named (or selected) character to another account');

UPDATE `trinity_string` SET `entry`=1999 WHERE `entry`=1184; -- 1184 was already used on 4.3.4 but no on master, on master 1999 is used but it will never be used on 3.3.5a/4.3.4 so i reuse this

DELETE FROM `trinity_string` WHERE `entry`=1184;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1184, 'Successfully transferred ownership of character %s to account %s');
