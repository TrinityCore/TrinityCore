-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_rog_cheat_death',
'spell_rog_crippling_poison',
'spell_rog_master_of_subtlety',
'spell_rog_preparation',
'spell_rog_shiv',
'spell_rog_serrated_blades');
