DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_saviana_conflagration_init';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_saviana_conflagration_throwback';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(74452, 'spell_saviana_conflagration_init'),
(74455, 'spell_saviana_conflagration_throwback');
