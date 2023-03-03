update creature_template set ScriptName = 'npc_tsulong_embodied_terror' where entry = 62969;
update creature_template set flags_extra = 130 where entry = 62962;
update creature_template set ScriptName = 'npc_tsulong_unstable_sha' where entry = 62919;

DELETE FROM `creature` WHERE id = 62962;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(62962, 996, 248, 1, -1018.58, -2992.519, 12.39281, 4.655136, 7200, 0, 0), 
(62962, 996, 248, 1, -1001.01, -3098.932, 12.20952, 4.655136, 7200, 0, 0), 
(62962, 996, 248, 1, -1018.58, -2992.519, 12.39281, 4.655136, 7200, 0, 0), 
(62962, 996, 248, 1, -963.3073, -3059.722, 12.20953, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -1024.486, -3101.462, 12.2165, 4.655136, 7200, 0, 0), 
(62962, 996, 248, 1, -1074.8, -3053.674, 12.20953, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -1060.609, -3012.747, 12.20952, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -969.5156, -3075.156, 12.20953, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -1047.639, -2999.571, 12.20952, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -993.757, -2999.411, 12.20953, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -961.7952, -3041.033, 12.20953, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -967.1077, -3021.302, 12.20953, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -1064.377, -3077.078, 12.20952, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -1070.936, -3030.722, 12.20952, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -980.7986, -3090.003, 12.20953, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -1047.977, -3096.87, 12.20952, 4.655136, 7200, 0, 0),
(62962, 996, 248, 1, -979.0972, -3006.896, 12.20953, 4.655136, 7200, 0, 0);

delete from spell_target_filter where spellid in (123011);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(123011, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Tsulong - Terrorize');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (123697);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 123697, 0, 0, 31, 0, 3, 62442, 0, 0, 0, '', NULL);