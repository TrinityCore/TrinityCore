-- --------
DELETE FROM `command` WHERE `name` = 'modify arenapoints';

DELETE FROM `command` WHERE `name` = 'modify currency';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('modify currency', 2, 'Syntax: .modify currency #id #value\nAdd $amount (without precision) of $currency to the selected player.');
