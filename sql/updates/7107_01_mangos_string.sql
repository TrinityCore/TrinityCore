ALTER TABLE db_version CHANGE COLUMN required_7097_01_mangos_spell_proc_event required_7107_01_mangos_string bit;

DELETE FROM `mangos_string` WHERE `entry` IN (521,1109,1122);
INSERT INTO `mangos_string` VALUES
(521,'%d - |cffffffff|Hskill:%d|h[%s %s]|h|r %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1109,'%d - %s %s %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1122,'(%u/%u +perm %u +temp %u)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
