ALTER TABLE db_version CHANGE COLUMN required_7879_01_mangos_spell_proc_event required_7884_01_mangos_playercreateinfo_spell bit;

DELETE FROM playercreateinfo_spell WHERE Spell = '28734';