/*ALTER TABLE db_version CHANGE COLUMN required_7251_01_mangos_spell_chain required_7252_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN ('debug arena','debug bg');
INSERT INTO `command` VALUES
('debug arena',3,'Syntax: .debug arena\r\n\r\nToggle debug mode for arenas. In debug mode GM can start arena with single player.'),
('debug bg',3,'Syntax: .debug bg\r\n\r\nToggle debug mode for battlegrounds. In debug mode GM can start battleground with single player.');