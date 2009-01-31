ALTER TABLE db_version CHANGE COLUMN required_7207_01_mangos_creature required_7207_02_mangos_gameobject bit;

ALTER TABLE gameobject
  ADD COLUMN `phaseMask` smallint(5) unsigned NOT NULL default '1' AFTER `spawnMask`;
