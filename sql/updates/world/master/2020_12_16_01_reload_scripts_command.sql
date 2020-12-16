DELETE FROM `command` WHERE `name`='reload spell_script_names';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES 
('reload spell_script_names', 2009, 'Syntax: .reload spell_script_names');