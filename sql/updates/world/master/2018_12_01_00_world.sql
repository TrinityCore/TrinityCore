DELETE FROM `command` WHERE `permission` = 698;
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('reload spell_script_names', 698, 'Syntax: .reload spell_script_names\nReload spell_script_names table.');