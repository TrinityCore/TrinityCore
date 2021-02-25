-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dk_death_pact',
'spell_dk_festering_strike',
'spell_dk_ghoul_explode',
'spell_dk_necrosis',
'spell_dk_unholy_blight');
