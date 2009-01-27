ALTER TABLE db_version CHANGE COLUMN required_7175_01_mangos_spell_proc_event required_7193_01_mangos_mangos_string bit;

UPDATE mangos_string SET content_default = 'Unit Flags: %u.\nDynamic Flags: %u.\nFaction Template: %u.' WHERE entry = 542;