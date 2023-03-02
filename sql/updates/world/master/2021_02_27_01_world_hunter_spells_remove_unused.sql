-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_hun_ancient_hysteria',
'spell_hun_arcane_shot',
'spell_hun_chimera_shot',
'spell_hun_cobra_shot',
'spell_hun_improved_mend_pet',
'spell_hun_readiness',
'spell_hun_ready_set_aim',
'spell_hun_sniper_training',
'spell_hun_target_only_pet_and_owner',
'spell_hun_tnt');
