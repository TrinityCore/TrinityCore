ALTER TABLE db_version CHANGE COLUMN required_6960_02_mangos_string required_6961_01_mangos_command bit;

DELETE FROM `command` WHERE name = 'reload';
