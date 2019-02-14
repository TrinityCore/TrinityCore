DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dk_unholy_command',
'spell_dk_disease',
'spell_dk_desecration');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-49588, 'spell_dk_unholy_command'),
(55078, 'spell_dk_disease'),
(55095, 'spell_dk_disease'),
(-55666, 'spell_dk_desecration');
