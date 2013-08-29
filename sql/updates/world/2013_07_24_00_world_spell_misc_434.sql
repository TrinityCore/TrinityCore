DELETE FROM `spell_script_names` WHERE `spell_id`=-14748;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-14748,'spell_pri_improved_power_word_shield');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=14748;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(14748, 14748, 1),
(14748, 14768, 2);
