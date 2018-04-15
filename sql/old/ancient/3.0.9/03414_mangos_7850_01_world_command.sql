/*ALTER TABLE db_version CHANGE COLUMN required_7839_02_mangos_command required_7850_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN ('character reputation','pinfo');
INSERT INTO `command` VALUES
('pinfo',2,'Syntax: .pinfo [$player_name]\r\n\r\nOutput account information for selected player or player find by $player_name.'),
('character reputation',2,'Syntax: .character reputation [$player_name]\r\n\r\nShow reputation information for selected player or player find by $player_name.');
