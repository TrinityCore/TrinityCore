DELETE FROM `command` WHERE name='channel set public';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('channel set public', 3, 'Syntax: .channel set public  $channel $public\r\n\r\nChange password-changing ability for a channel. 1 for possible, 0 for GM only.');
