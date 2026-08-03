DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_eradicate','spell_dh_reap','spell_dh_cull');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1225826, 'spell_dh_eradicate'),
(1226019, 'spell_dh_reap'),
(1245453, 'spell_dh_cull');
