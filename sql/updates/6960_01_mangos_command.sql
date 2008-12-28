ALTER TABLE db_version CHANGE COLUMN required_6958_01_mangos_spell_proc_event required_6960_01_mangos_command bit;

DELETE FROM `command` WHERE `name` = 'modify runicpower';
INSERT INTO `command` VALUES
('modify runicpower',1,'Syntax: .modify runicpower #newrunicpower\r\n\r\nModify the runic power of the selected player. If no player is selected, modify your runic power.');
