/*ALTER TABLE db_version CHANGE COLUMN required_7205_01_mangos_spell_chain required_7207_01_mangos_creature bit;*/

ALTER TABLE creature
  ADD COLUMN `phaseMask` smallint(5) unsigned NOT NULL default '1' AFTER `spawnMask`;