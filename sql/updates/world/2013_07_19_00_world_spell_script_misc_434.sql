DELETE FROM `spell_script_names` WHERE `spell_id` IN (-52752,55440);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-52752,'spell_sha_ancestral_awakening'),
(55440,'spell_sha_glyph_of_healing_wave');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=52752;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(52752, 52752, 1),
(52752, 51557, 2),
(52752, 51558, 3);
