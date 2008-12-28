ALTER TABLE db_version CHANGE COLUMN required_6960_01_mangos_command required_6960_02_mangos_string bit;

DELETE FROM `mangos_string` WHERE `entry` IN (173,174);
INSERT INTO `mangos_string` VALUES
(173,'You changed runic power of %s to %i/%i.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(174,'%s changed your runic power to %i/%i.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
