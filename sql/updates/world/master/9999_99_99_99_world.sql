DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_shadow_crash', 'spell_pri_whispering_shadows_dummy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(205385, 'spell_pri_shadow_crash'),
(391286, 'spell_pri_whispering_shadows_dummy');
