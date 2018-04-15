/*ALTER TABLE db_version CHANGE COLUMN required_7615_01_mangos_command required_7616_01_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE `entry` IN (1200,1201);
INSERT INTO `trinity_string` VALUES
(1200,'You try to view cinemitic %u but it doesn\'t exist.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1201,'You try to view movie %u but it doesn\'t exist.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
