DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (15651, 15652, 15653, 15654);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES
(15651, 11, 'achievement_achieve_a_tron_static_shock'),
(15652, 11, 'achievement_achieve_a_tron_poison_bomb'),
(15653, 11, 'achievement_achieve_a_tron_arcane_annihilator'),
(15654, 11, 'achievement_achieve_a_tron_flamethrower');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_omnotron_flamethrower';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79504, 'spell_omnotron_flamethrower'),
(91535, 'spell_omnotron_flamethrower'),
(91536, 'spell_omnotron_flamethrower'),
(91537, 'spell_omnotron_flamethrower');
