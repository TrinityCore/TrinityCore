DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_demonic_havoc','spell_dh_demonic_vengeance');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(198013, 'spell_dh_demonic_havoc'),
(212084, 'spell_dh_demonic_vengeance');
