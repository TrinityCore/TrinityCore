ALTER TABLE db_version CHANGE COLUMN required_2008_12_22_09_mangos_spell_affect required_2008_12_22_10_mangos_string bit;

INSERT INTO `mangos_string` VALUES
(345,'Forced customize for player %s will be requested at next login.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(346,'Forced customize for player %s (GUID #%u) will be requested at next login.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
