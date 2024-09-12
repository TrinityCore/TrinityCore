DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_new_moon', 'spell_dru_half_moon', 'spell_dru_full_moon');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(274281, 'spell_dru_new_moon'),
(274282, 'spell_dru_half_moon'),
(274283, 'spell_dru_full_moon');
