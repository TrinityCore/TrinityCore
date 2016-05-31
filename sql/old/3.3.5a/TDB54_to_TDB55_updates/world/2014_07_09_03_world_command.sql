DELETE FROM `command` WHERE `name` LIKE 'reload battleground_template';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload battleground_template', 631, 'Syntax: .reload battleground_template\r\nReload Battleground Templates.');
