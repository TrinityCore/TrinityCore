DELETE FROM `command` WHERE `name` LIKE 'channel set public';
DELETE FROM `command` WHERE `name` LIKE 'channel set ownership';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('channel set ownership', 3, 'Syntax: .channel set ownership $channel [on/off]\n\n\Grant ownership to the first person that joins the channel.');

