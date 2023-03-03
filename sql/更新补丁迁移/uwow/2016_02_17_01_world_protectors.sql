update creature_template set mechanic_immune_mask = mechanic_immune_mask &~ 33554432 where entry = 60586;
update creature_template set minlevel = 93, maxlevel = 93, faction = 16, unit_flags = 33554432, unit_flags2 = 2099200, inhabitType = 7, ScriptName = 'npc_asani_cleansing_waters', flags_extra = 128 where entry = 60646;
update creature_template set ScriptName = 'npc_asani_corrupted_waters' where entry = 60621;
update creature_template set minlevel = 93, maxlevel = 93, faction = 16, unit_flags = 33554432, unit_flags2 = 2099200, flags_extra = 128 where entry = 60906;

delete from spell_target_filter where spellId in (111850,118004,118005,118007,118008);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(111850, 15, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 0, 0, 'Elder Regail - Lightning Prison'),
(118004, 15, 2, -1, 10, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Regail - Lightning Storm 10m'),
(118005, 15, 2, -1, 30, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Regail - Lightning Storm 30m'),
(118007, 15, 2, -1, 50, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Regail - Lightning Storm 50m'),
(118008, 15, 2, -1, 70, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Regail - Lightning Storm 70m');

delete from spell_script_names where spell_id in (118077,117955);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(118077, 'spell_regail_lightning_storm'),
(117955, 'spell_kaolan_expelled_corruption');

delete from spell_target_position where id = 117227;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(117227, 996, -1018.17, -3049.18, 12.82, 0);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (117230);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 117230, 0, 0, 31, 0, 3, 60583, 0, 0, 0, '', NULL),
(13, 1, 117230, 0, 1, 31, 0, 3, 60585, 0, 0, 0, '', NULL),
(13, 1, 117230, 0, 2, 31, 0, 3, 60586, 0, 0, 0, '', NULL);