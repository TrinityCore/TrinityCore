DELETE FROM spell_script_names WHERE ScriptName='spell_warl_demonic_circle_summon';
INSERT INTO spell_script_names VALUES (48018, 'spell_warl_demonic_circle_summon');

DELETE FROM disables WHERE sourceType=3 AND entry IN (10,11);