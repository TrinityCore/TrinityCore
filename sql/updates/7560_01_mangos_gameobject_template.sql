ALTER TABLE db_version CHANGE COLUMN required_7558_02_mangos_command required_7560_01_mangos_gameobject_template bit;

ALTER TABLE gameobject_template
  ADD COLUMN IconName varchar(100) NOT NULL default '' AFTER name;
