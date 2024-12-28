DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_demon_spikes', 'spell_dh_deflecting_spikes');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(203720, 'spell_dh_demon_spikes'),
(203819, 'spell_dh_deflecting_spikes');
