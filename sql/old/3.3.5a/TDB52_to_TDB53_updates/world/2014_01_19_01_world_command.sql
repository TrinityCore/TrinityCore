SET @id = 777;

DELETE FROM `command` WHERE `name` = 'mailbox';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('mailbox', @id, 'Syntax: .mailbox\r\n\r\nShow your mailbox content.');
