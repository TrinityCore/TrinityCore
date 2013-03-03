/*ALTER TABLE db_version CHANGE COLUMN required_7544_01_mangos_uptime required_7558_01_mangos_mangos_string bit;*/

DELETE FROM `trinity_string` WHERE `entry` IN (1123,1124,1125,1126,1127);
INSERT INTO `trinity_string` VALUES
(1123,'Not pet found',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1124,'Wrong pet type',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1125,'Your pet learned all talents',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1126,'Your pet talents have been reset.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1127,'Talents of %s\'s pet reset.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
