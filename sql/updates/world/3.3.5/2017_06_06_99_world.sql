DELETE FROM `command` WHERE `name`='reload lfg_dungeon_template';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload lfg_dungeon_template', 856, 'Syntax: .reload lfg_dungeon_template\nReload lfg_dungeon_template table.');
