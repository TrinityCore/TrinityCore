DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_svalna_caress_of_death';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_svalna_revive_champion';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_svalna_remove_spear';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(70078, 'spell_svalna_caress_of_death'),
(70053, 'spell_svalna_revive_champion'),
(71462, 'spell_svalna_remove_spear');
