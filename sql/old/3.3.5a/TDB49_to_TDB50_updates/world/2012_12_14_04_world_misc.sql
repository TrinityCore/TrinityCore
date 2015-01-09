DELETE FROM `spell_script_names` WHERE `spell_id`=44436;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(44436, 'spell_tricky_treat');

DELETE FROM `waypoint_data` WHERE `id`=883750 AND `point`=3;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
(883750, 3, -8538.3, 1149.52, 19.0522, 0, 15000, 0, 1029, 100, 0);
