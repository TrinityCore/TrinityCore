DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_four_horsemen_consumption',
'spell_rajaxx_thundercrash',
'spell_gen_arcane_charge');

INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(28865, 'spell_four_horsemen_consumption'),
(25599, 'spell_rajaxx_thundercrash'),
(45072, 'spell_gen_arcane_charge');
