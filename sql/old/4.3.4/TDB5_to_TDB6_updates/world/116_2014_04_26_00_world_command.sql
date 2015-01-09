SET @id = 614;

DELETE FROM `command` WHERE `name` = 'broadcast_text';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('broadcast_text', @id, 'Syntax: .broadcast_text\r\n\r\nReload broadcast_text table.');
