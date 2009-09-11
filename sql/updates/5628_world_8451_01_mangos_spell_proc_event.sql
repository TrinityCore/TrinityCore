
-- ALTER TABLE db_version CHANGE COLUMN required_8451_01_mangos_spell_proc_event required_8462_01_mangos_creature_ai_texts bit;

ALTER TABLE creature_ai_texts CHANGE emote emote smallint(5) unsigned NOT NULL default '0';
