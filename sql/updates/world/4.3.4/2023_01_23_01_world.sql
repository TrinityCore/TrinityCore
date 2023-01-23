DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_regrowth', 'spell_dru_regrowth_refresh');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(8936, 'spell_dru_regrowth'),
(93036, 'spell_dru_regrowth_refresh');
