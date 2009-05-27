ALTER TABLE db_version CHANGE COLUMN required_7893_01_mangos_command required_7896_01_mangos_creature_template bit;

ALTER TABLE creature_template CHANGE COLUMN class trainer_class tinyint(3) unsigned NOT NULL default '0';
ALTER TABLE creature_template CHANGE COLUMN race trainer_race tinyint(3) unsigned NOT NULL default '0';
