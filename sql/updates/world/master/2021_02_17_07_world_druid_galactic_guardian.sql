-- Add galactic guardian spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_galactic_guardian';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(203964, 'spell_dru_galactic_guardian');
