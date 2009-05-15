/*ALTER TABLE db_version CHANGE COLUMN required_7782_01_mangos_spell_proc_event required_7796_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN ('go taxinode','lookup taxinode');
INSERT INTO `command` VALUES
('go taxinode',1,'Syntax: .go taxinode #taxinode\r\n\r\nTeleport player to taxinode coordinates. You can look up zone using .lookup taxinode $namepart'),
('lookup taxinode',3,'Syntax: .lookup taxinode $substring\r\n\r\nSearch and output all taxinodes with provide $substring in name.');