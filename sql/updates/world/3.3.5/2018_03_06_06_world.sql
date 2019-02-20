DELETE FROM `command` WHERE `name`='server debug';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('server debug', 872, 'Syntax: .server debug\n\nShows detailed information about server setup, useful when reporting a bug');
