delete from creature where id in (61038,61042,61046,65736);

update creature_template set ScriptName = 'npc_sha_of_fear_terror_spawn' where entry = 61034;
update creature_template set ScriptName = 'npc_sha_of_fear_dread_spawn' where entry = 61003;
update creature_template set ScriptName = 'npc_sha_of_fear_pure_light_terrace' where entry = 60788;
update creature_template set minlevel = 93, maxlevel = 93, faction = 16, npcflag = 0, ScriptName = 'npc_sha_of_fear_platform_defenders' where entry in (61038,61042,61046);
update creature_template set mindmg = 1168, maxdmg = 1752, minrangedmg = 502, maxrangedmg = 754 where entry in (61038,61042,61046);
update creature_template set minlevel = 93, maxlevel = 93, faction = 14, unit_flags = 33587200, ScriptName = 'npc_sha_of_fear_sha_globe' where entry = 65691;
update creature_template set iconName = 'openhandglow', AIName = 'SmartAI' where entry = 65736;

delete from smart_scripts where entryorguid = 65736;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65736, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 85, 118977, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Cast Fearless');

delete from spell_target_filter where spellId in (129075,119787);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(129075, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Sha - Penetrating Bolt'),
(119787, 15, 2, -1, 90, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Sha of Fear - Teleport');

delete from spell_dummy_trigger where spell_id in (129075);
INSERT INTO `spell_dummy_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `comment`) VALUES 
(129075, 0, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Sha - Penetrating Bolt');

delete from spell_target_position where id in (119797,119841);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(119797, 996, -1018.21, -2837.03, 38.04, 1.57),
(119841, 996, -1017.6, -2736.75, 38.27, 4.69);

delete from spell_script_names where spell_id in (117866,131993,119593,119692,119693,129147);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(117866, 'spell_sha_of_fear_champion_light'),
(131993, 'spell_sha_of_fear_thrash'),
(119593, 'spell_sha_of_fear_ominous_cackle'),
(119692, 'spell_sha_of_fear_ominous_cackle'),
(119693, 'spell_sha_of_fear_ominous_cackle'),
(129147, 'spell_sha_of_fear_ominous_cackle_controll');

delete from waypoint_data where id in (6099900,6099901,6099902,6099903);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`, `wpguid`) VALUES 
(6099900, 1, -1063.39, -2792.65, 38.2549, 0, 0, 0, 0, 100, 0, 0),
(6099900, 2, -1082.84, -2796.48, 45.3328, 0, 0, 0, 0, 100, 0, 0),
(6099900, 3, -1136.48, -2794.79, 52.4764, 0, 0, 0, 0, 100, 0, 0),
(6099900, 4, -1192.48, -2785.4, 56.7883, 0, 0, 0, 0, 100, 0, 0),
(6099900, 5, -1230.98, -2787.74, 58.3761, 0, 0, 0, 0, 100, 0, 0),
(6099900, 6, -1260.4, -2818.42, 60.0621, 0, 0, 0, 0, 100, 0, 0),
(6099900, 7, -1256.6, -2839.09, 54.2997, 0, 0, 0, 0, 100, 0, 0),
(6099900, 8, -1233.74, -2832.04, 41.2708, 0, 0, 0, 0, 100, 0, 0),
(6099901, 1, -1043.74, -2729.38, 38.2551, 0, 0, 0, 0, 100, 0, 0),
(6099901, 2, -1070.61, -2675.39, 49.6753, 0, 0, 0, 0, 100, 0, 0),
(6099901, 3, -1098.05, -2631.98, 41.092, 0, 0, 0, 0, 100, 0, 0),
(6099901, 4, -1119.47, -2591.07, 42.1768, 0, 0, 0, 0, 100, 0, 0),
(6099901, 5, -1118.84, -2558.44, 39.8162, 0, 0, 0, 0, 100, 0, 0),
(6099901, 6, -1100.17, -2534.17, 35.2596, 0, 0, 0, 0, 100, 0, 0),
(6099901, 7, -1080.92, -2544.16, 28.7751, 0, 0, 0, 0, 100, 0, 0),
(6099901, 8, -1077.92, -2558.61, 15.8787, 0, 0, 0, 0, 100, 0, 0),
(6099902, 1, -997.042, -2744.55, 38.2805, 0, 0, 0, 0, 100, 0, 0),
(6099902, 2, -989.479, -2721.25, 50.6927, 0, 0, 0, 0, 100, 0, 0),
(6099902, 3, -986.857, -2676.98, 50.2519, 0, 0, 0, 0, 100, 0, 0),
(6099902, 4, -997.86, -2641.22, 48.1446, 0, 0, 0, 0, 100, 0, 0),
(6099902, 5, -1014.82, -2602.95, 44.4881, 0, 0, 0, 0, 100, 0, 0),
(6099902, 6, -1034.52, -2562.98, 41.4311, 0, 0, 0, 0, 100, 0, 0),
(6099902, 7, -1076.73, -2530.32, 34.023, 0, 0, 0, 0, 100, 0, 0),
(6099902, 8, -1079.37, -2546.66, 23.4002, 0, 0, 0, 0, 100, 0, 0),
(6099902, 9, -1078.1, -2558.72, 15.8798, 0, 0, 0, 0, 100, 0, 0),
(6099903, 1, -972.738, -2793.38, 38.2548, 0, 0, 0, 0, 100, 0, 0),
(6099903, 2, -934.033, -2796.63, 54.2311, 0, 0, 0, 0, 100, 0, 0),
(6099903, 3, -899.745, -2793.13, 55.7616, 0, 0, 0, 0, 100, 0, 0),
(6099903, 4, -883.721, -2745.35, 52.7023, 0, 0, 0, 0, 100, 0, 0),
(6099903, 5, -867.865, -2708.92, 50.7063, 0, 0, 0, 0, 100, 0, 0),
(6099903, 6, -823.435, -2696.61, 52.7561, 0, 0, 0, 0, 100, 0, 0),
(6099903, 7, -787.486, -2718.68, 52.8377, 0, 0, 0, 0, 100, 0, 0),
(6099903, 8, -800.991, -2740.42, 41.7081, 0, 0, 0, 0, 100, 0, 0),
(6099903, 9, -812.145, -2742.06, 31.7046, 0, 0, 0, 0, 100, 0, 0);
