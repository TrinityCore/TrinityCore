/*ALTER TABLE db_version CHANGE COLUMN required_7331_01_mangos_command required_7332_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` = 'distance';
INSERT INTO `command` VALUES
('distance',3,'Syntax: .distance [$name/$link]\r\n\r\nDisplay the distance from your character to the selected creature/player, or player with name $name, or player/creature/gameobject pointed to shift-link with guid.');
