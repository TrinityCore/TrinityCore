-- ALTER TABLE db_version CHANGE COLUMN required_8021_01_mangos_spell_proc_event required_8030_03_mangos_npc_trainer bit;

DELETE FROM npc_trainer WHERE spell = 64904;

