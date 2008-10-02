DELETE FROM `command` WHERE `name` = 'reload';
DELETE FROM `command` WHERE `name` = 'reload all';
DELETE FROM `command` WHERE `name` = 'reload all_spell';
INSERT INTO `command` VALUES('reload',3,'Syntax: .reload table_name\r\n\r\nReload table `table_name` if reload support added for this table and this table can be _safe_ reloaded.');
INSERT INTO `command` VALUES('reload all',3,'Syntax: .reload all\r\n\r\nReload all tables with reload support added and that can be _safe_ reloaded.');
INSERT INTO `command` VALUES('reload all_spell',3,'Syntax: .reload all\r\n\r\nReload all `spell_*` tables with reload support added and that can be _safe_ reloaded.');
