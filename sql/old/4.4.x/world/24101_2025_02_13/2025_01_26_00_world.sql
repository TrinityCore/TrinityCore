DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pal_judgement', 'spell_pal_judgement_of_righteousness');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(20271, 'spell_pal_judgement'),
(20187, 'spell_pal_judgement_of_righteousness');
