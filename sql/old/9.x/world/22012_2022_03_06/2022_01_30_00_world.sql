DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_holy_shock_damage_visual';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_holy_shock_heal_visual';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(25912,'spell_pal_holy_shock_damage_visual'),
(25914,'spell_pal_holy_shock_heal_visual');
