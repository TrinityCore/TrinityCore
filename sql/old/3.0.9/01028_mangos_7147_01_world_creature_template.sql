/*ALTER TABLE db_version CHANGE COLUMN required_7141_01_mangos_instance_template required_7147_01_mangos_creature_template bit;*/

UPDATE creature_template
  SET family = 0 WHERE entry = 1;
