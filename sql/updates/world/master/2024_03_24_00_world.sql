DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_whispering_shadows','spell_pri_whispering_shadows_effect');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(205385,'spell_pri_whispering_shadows'),
(391286,'spell_pri_whispering_shadows_effect');
