-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_aura_mastery',
'spell_pal_aura_mastery_immune',
'spell_pal_avenging_wrath',
'spell_pal_exorcism_and_holy_wrath_damage',
'spell_pal_eye_for_an_eye',
'spell_pal_righteous_defense',
'spell_pal_sacred_shield',
'spell_pal_shield_of_the_righteous',
'spell_pal_seal_of_righteousness');
