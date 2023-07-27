DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_tranquility', 'spell_dru_tranquility_heal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(740, 'spell_dru_tranquility'),
(157982, 'spell_dru_tranquility_heal');
