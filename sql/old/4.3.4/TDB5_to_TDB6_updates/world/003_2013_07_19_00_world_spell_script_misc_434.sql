DELETE FROM `spell_script_names` WHERE `spell_id` IN (-51556,55440);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-51556,'spell_sha_ancestral_awakening'),
(55440,'spell_sha_glyph_of_healing_wave');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=51556;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(51556, 51556, 1),
(51556, 51557, 2),
(51556, 51558, 3);
