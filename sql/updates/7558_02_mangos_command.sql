ALTER TABLE db_version CHANGE COLUMN required_7558_01_mangos_mangos_string required_7558_02_mangos_command bit;

DELETE FROM `command` WHERE `name` IN ('learn all_mypettalents');

INSERT INTO `command` VALUES
('learn all_mypettalents',3,'Syntax: .learn all_mypettalents\r\n\r\nLearn all talents for your pet available for his creature type (only for hunter pets).');
