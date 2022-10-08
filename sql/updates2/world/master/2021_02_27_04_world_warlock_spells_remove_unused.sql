-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warl_bane_of_doom',
'spell_warl_conflagrate',
'spell_warl_demonic_empowerment',
'spell_warl_demon_soul',
'spell_warl_everlasting_affliction',
'spell_warl_fel_synergy',
'spell_warl_glyph_of_shadowflame',
'spell_warl_improved_soul_fire',
'spell_warl_nether_ward_overrride',
'spell_warl_shadow_ward',
'spell_warl_soul_leech');
