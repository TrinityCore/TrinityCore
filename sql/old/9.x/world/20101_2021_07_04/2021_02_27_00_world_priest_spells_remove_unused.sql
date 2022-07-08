-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pri_body_and_soul',
'spell_pri_circle_of_healing',
'spell_pri_dispel_magic',
'spell_pri_divine_aegis',
'spell_pri_glyph_of_prayer_of_healing',
'spell_pri_hymn_of_hope',
'spell_pri_improved_power_word_shield',
'spell_pri_lightwell_renew',
'spell_pri_mana_burn',
'spell_pri_mana_leech',
'spell_pri_pain_and_suffering_proc',
'spell_pri_phantasm',
'spell_pri_shadowform');
