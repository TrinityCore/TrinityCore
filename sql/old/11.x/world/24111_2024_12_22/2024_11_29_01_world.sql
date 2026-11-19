DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_evo_verdant_embrace', 'spell_evo_verdant_embrace_trigger_heal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(360995, 'spell_evo_verdant_embrace'),
(396557, 'spell_evo_verdant_embrace_trigger_heal');
