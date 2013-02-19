/*ALTER TABLE db_version CHANGE COLUMN required_7376_01_mangos_spell_area required_7382_01_mangos_creature_template bit;*/

ALTER TABLE creature_template
  ADD COLUMN unk16 float NOT NULL default '1' AFTER InhabitType,
  ADD COLUMN unk17 float NOT NULL default '1' AFTER unk16;
