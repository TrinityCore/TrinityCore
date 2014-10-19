DELETE FROM `spell_script_names` WHERE `spell_id` IN (63310,-18094,56218,6358,-30293);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(63310,'spell_warl_glyph_of_shadowflame'),
(-18094,'spell_warl_shadow_trance_proc'),
(56218,'spell_warl_shadow_trance_proc'),
(6358,'spell_warl_seduction'),
(-30293,'spell_warl_soul_leech');

DELETE FROM `spell_ranks` WHERE `first_spell_id` IN (18094,30293);
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(18094, 18094, 1),
(18094, 18095, 2),
(30293, 30293, 1),
(30293, 30295, 2);
