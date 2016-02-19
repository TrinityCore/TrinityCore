--
DELETE FROM `spell_proc_event` WHERE `entry`= 56841;
INSERT INTO `spell_proc_event` VALUES (56841, 0, 9, 2048, 2048, 2048, 256, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hun_glyph_of_arcane_shot';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(56841,'spell_hun_glyph_of_arcane_shot');
