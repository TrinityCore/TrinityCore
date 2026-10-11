DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_frenzied_enrage', 'spell_warr_powerful_enrage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(184362, 'spell_warr_frenzied_enrage'),
(184362, 'spell_warr_powerful_enrage');
