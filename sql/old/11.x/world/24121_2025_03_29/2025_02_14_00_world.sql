DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_blade_of_vengeance';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_blade_of_vengeance_aoe_target_selector';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(184575, 'spell_pal_blade_of_vengeance'),
(404358, 'spell_pal_blade_of_vengeance_aoe_target_selector');
