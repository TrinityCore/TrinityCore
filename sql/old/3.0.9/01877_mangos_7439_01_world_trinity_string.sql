/*ALTER TABLE db_version CHANGE COLUMN required_7422_01_mangos_mangos_string required_7439_01_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE `entry` IN (175);
INSERT INTO `trinity_string` VALUES
(175,'Liquid level: %f, ground: %f, type: %d, status: %d',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
