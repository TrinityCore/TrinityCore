DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_comet_storm', 'spell_mage_comet_storm_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(153595, 'spell_mage_comet_storm'),
(228601, 'spell_mage_comet_storm_damage');
