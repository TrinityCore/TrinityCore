DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_pulverize', 'spell_dru_pulverize_thrash', 'spell_dru_pulverize_trigger_periodic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80313, 'spell_dru_pulverize'),
(77758, 'spell_dru_pulverize_thrash'),
(158790, 'spell_dru_pulverize_trigger_periodic');
