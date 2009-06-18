/*ALTER TABLE db_version CHANGE COLUMN required_7252_02_mangos_mangos_string required_7290_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` = 'npc setdeathstate';
INSERT INTO `command` VALUES
('npc setdeathstate',2,'Syntax: .npc setdeathstate on/off\r\n\r\nSet default death state (dead/alive) for npc at spawn.');
