DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_warl_fear',
'spell_warl_glyph_of_fear',
'spell_pri_psychic_scream');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(5782, 'spell_warl_fear'),
(56244, 'spell_warl_glyph_of_fear'),
(8122, 'spell_pri_psychic_scream');
