DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_banish','spell_warl_create_healthstone','spell_warl_ritual_of_doom_effect');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES 
(710,'spell_warl_banish'),
(6201,'spell_warl_create_healthstone');
