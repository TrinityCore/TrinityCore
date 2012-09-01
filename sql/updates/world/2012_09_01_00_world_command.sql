DELETE FROM `command` WHERE `name`='cheat status';
INSERT INTO `command` (`name`, `security`, `help`) VALUES 
('cheat status', 2, 'Syntax: .cheat status\n Shows Active and Inactive cheats.');