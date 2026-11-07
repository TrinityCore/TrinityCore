--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
    'spell_gen_slow_roasted_turkey',
    'spell_gen_cranberry_chutney',
    'spell_gen_spice_bread_stuffing',
    'spell_gen_pumpkin_pie',
    'spell_gen_candied_sweet_potato'
);

DELETE FROM `spell_linked_spell` WHERE `spell_effect` = 24870;
