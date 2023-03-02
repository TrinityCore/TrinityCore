DELETE FROM spell_script_names WHERE ScriptName = 'spell_warr_sudden_death';
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES (29725, 'spell_warr_sudden_death');
DELETE FROM spell_script_names WHERE ScriptName IN ('spell_warr_heroic_leap_damage', 'spell_warr_heroic_leap', 'spell_warr_colossus_smash', 'spell_warr_second_wind',  'spell_warr_glyph_of_hindering_strikes', 'spell_warr_charge', 'spell_warr_glyph_of_hamstring', 'spell_warr_staggering_shout', 'spell_warr_shockwave');
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES 
(52174, 'spell_warr_heroic_leap_damage'),
(6544, 'spell_warr_heroic_leap'),
(86346, 'spell_warr_colossus_smash'),
(29838, 'spell_warr_second_wind'),
(78, 'spell_warr_glyph_of_hindering_strikes'),
(845, 'spell_warr_glyph_of_hindering_strikes'),
(100, 'spell_warr_charge'),
(1715, 'spell_warr_glyph_of_hamstring'),
(107566, 'spell_warr_staggering_shout'),
(46968, 'spell_warr_shockwave');
DELETE FROM spell_script_names WHERE ScriptName = 'spell_warl_create_healthstone';