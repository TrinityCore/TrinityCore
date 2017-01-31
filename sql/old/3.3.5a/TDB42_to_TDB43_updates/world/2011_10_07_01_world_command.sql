DELETE FROM `command` WHERE `name` = 'ticket reset';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('ticket reset', 3, 'Syntax: .ticket reset\nRemoves all closed tickets and resets the counter, if no pending open tickets are existing.');