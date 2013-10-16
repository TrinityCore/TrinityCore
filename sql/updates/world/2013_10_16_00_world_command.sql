DELETE FROM `command` WHERE `name` = 'debug transport';

INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('debug transport', 400, 'Syntax: .debug transport [start/stop]\r\n\r\n Allows to stop a transport at its nearest wait point and start movement of a stopped one. Not all transports can be started or stopped.'),
