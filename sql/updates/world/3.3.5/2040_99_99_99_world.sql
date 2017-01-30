-- Phantom Mammoth 
DELETE FROM creature WHERE id=29748; -- shouldn't stand all the time
UPDATE creature_template SET `flags_extra` = `flags_extra`&0x2, `unit_flags` = `unit_flags`|0x00020000 WHERE entry=29748; -- set visible to players, npc shouldn't attack
-- Mojo Frenzy
DELETE FROM spell_script_names WHERE ScriptName = "spell_moorabi_mojo_frenzy";
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(55163, "spell_moorabi_mojo_frenzy");
