DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_dh_blade_dance',
'spell_dh_blade_dance_damage',
'spell_dh_first_blood'
);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(188499, 'spell_dh_blade_dance'),
(210152, 'spell_dh_blade_dance'),
(199552, 'spell_dh_blade_dance_damage'),
(200685, 'spell_dh_blade_dance_damage'),
(210153, 'spell_dh_blade_dance_damage'),
(210155, 'spell_dh_blade_dance_damage'),
(206416, 'spell_dh_first_blood');
