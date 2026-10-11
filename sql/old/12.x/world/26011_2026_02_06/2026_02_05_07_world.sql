DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_atonement_effect' AND `spell_id` IN (139, 200829, 47750);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(200829, 'spell_pri_atonement_effect'),
(47750, 'spell_pri_atonement_effect');
