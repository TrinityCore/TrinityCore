DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_deep_wounds';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-12162, 'spell_warr_deep_wounds');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=12162;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(12162, 12162, 1),
(12162, 12850, 2),
(12162, 12868, 3);
