-- Add incapacitating roar spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_incapacitating_roar';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(99, 'spell_dru_incapacitating_roar');
