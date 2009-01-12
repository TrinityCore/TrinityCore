ALTER TABLE db_version CHANGE COLUMN required_7063_01_mangos_spell_proc_event required_7067_01_mangos_playercreateinfo_spell bit;

ALTER TABLE playercreateinfo_spell
  DROP COLUMN Active;

DELETE FROM playercreateinfo_spell WHERE Spell IN (1178,3025,5419,5420,5421,7376,7381,9635,21156,21178,24905,33948,34123,40121);
