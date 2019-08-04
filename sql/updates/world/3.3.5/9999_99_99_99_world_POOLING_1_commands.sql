-- 
DELETE FROM `command` WHERE `name`='debug poolstatus';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('debug poolstatus',879,'Syntax: .debug poolstatus [<poolSpawnId>]

Shows status for specified pool, or all spawn pools on the current map.');
