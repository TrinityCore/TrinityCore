DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_golden_path';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_golden_path_target_selector';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(26573, 'spell_pal_golden_path'),
(26573, 'spell_pal_golden_path_target_selector');
