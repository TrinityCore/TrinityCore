DELETE FROM `spell_script_names` WHERE `ScriptName`IN ('spell_monk_renewing_mist', 'spell_monk_renewing_mist_heal', 'spell_monk_renewing_mist_jump');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(115151, 'spell_monk_renewing_mist'),
(119611, 'spell_monk_renewing_mist_heal'),
(119607, 'spell_monk_renewing_mist_jump');
