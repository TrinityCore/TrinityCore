DELETE FROM `spell_script_names` WHERE ScriptName IN (
'spell_pal_beacon_of_virtue',
'spell_pal_beacon_of_light_aura',
'spell_pri_twist_of_fate',
'spell_pri_mind_bomb',
'spell_pri_holy_word_chastise',
'spell_pri_clarity_of_will',
'spell_pri_smite',
'spell_pri_prayer_of_healing',
'spell_pri_prayer_of_mending',
'spell_pri_heal_flash_heal',
'spell_pri_binding_heal',
'spell_pri_power_word_shield',
'spell_dru_thrash',
'spell_dru_thrash_periodic_damage'
);

INSERT INTO spell_script_names(`spell_id`, `ScriptName`) VALUES
(200025, 'spell_pal_beacon_of_virtue'),
(200025, 'spell_pal_beacon_of_light_aura'),
(109142, 'spell_pri_twist_of_fate'),
(205369, 'spell_pri_mind_bomb'),
(88625, 'spell_pri_holy_word_chastise'),
(152118, 'spell_pri_clarity_of_will'),
(585, 'spell_pri_smite'),
(596, 'spell_pri_prayer_of_healing'),
(33076, 'spell_pri_prayer_of_mending'),
(32546, 'spell_pri_binding_heal'),
(2061, 'spell_pri_heal_flash_heal'),
(2060, 'spell_pri_heal_flash_heal'),
(17, 'spell_pri_power_word_shield'),
(77758, 'spell_dru_thrash'),
(192090, 'spell_dru_thrash_periodic_damage');

