DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dk_improved_blood_presence',
'spell_dk_improved_frost_presence',
'spell_dk_improved_unholy_presence',
'spell_dk_improved_presence');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-50365,'spell_dk_improved_presence'),
(-50384, 'spell_dk_improved_presence'),
(-50391, 'spell_dk_improved_presence');
