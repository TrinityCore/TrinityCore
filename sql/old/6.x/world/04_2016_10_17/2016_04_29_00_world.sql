DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rog_eviscerate','spell_rog_envenom');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(2098,'spell_rog_eviscerate'),
(32645,'spell_rog_envenom');
