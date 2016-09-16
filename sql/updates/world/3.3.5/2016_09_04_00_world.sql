UPDATE `spell_proc_event` SET `SpellFamilyMask0`=0x00000004 WHERE `entry`=56800;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rog_glyph_of_backstab_triggered';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63975, 'spell_rog_glyph_of_backstab_triggered');
