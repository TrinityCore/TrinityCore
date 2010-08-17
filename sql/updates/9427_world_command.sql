DELETE FROM `command` WHERE `name` IN ('reload gossip_menu','reload gossip_menu_option','reload gossip_scripts');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload gossip_menu',3, 'Syntax: .reload gossip_menu\nReload gossip_menu table.'),
('reload gossip_menu_option',3, 'Syntax: .reload gossip_menu_option\nReload gossip_menu_option table.'),
('reload gossip_scripts',3, 'Syntax: .reload gossip_scripts\nReload gossip_scripts table.'),
