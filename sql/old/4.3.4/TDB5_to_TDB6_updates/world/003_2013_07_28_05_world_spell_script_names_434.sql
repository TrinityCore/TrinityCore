DELETE FROM `spell_script_names` WHERE `spell_id` IN (31821,64364,63510,63514,63531);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(31821, 'spell_pal_aura_mastery'),
(64364, 'spell_pal_aura_mastery_immune'),
(63510, 'spell_pal_improved_concentraction_aura_effect'),
(63514, 'spell_pal_improved_devotion_aura_effect'),
(63531, 'spell_pal_sanctified_retribution_effect');
