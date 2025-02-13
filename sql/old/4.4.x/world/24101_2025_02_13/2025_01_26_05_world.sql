DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pal_seal_of_insight', 'spell_pal_seal_of_insight_triggered');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(20165, 'spell_pal_seal_of_insight'),
(20167, 'spell_pal_seal_of_insight_triggered');
