-- 
DELETE FROM `command` WHERE `name`='debug warden force';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug warden force', 300, 'Syntax: .debug warden force id1 [id2 [id3 [...]]]

Queues the specified Warden checks for your client. They will be sent according to your Warden settings.');
