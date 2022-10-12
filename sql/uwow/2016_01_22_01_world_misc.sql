delete from creature where id in (63292);
update creature_template set minlevel = 93, maxlevel = 93, faction = 14, ScriptName = 'npc_tempest_slash', flags_extra = 128 where entry = 62908;
update creature_template set minlevel = 88, maxlevel = 88, faction = 16, unit_flags = 34078720, ScriptName = 'npc_tayak_storm_unleashed_plr_veh', flags_extra = 128 where entry = 63567;
update creature_template set unit_flags = 34078720, flags_extra = 128 where entry in (63207,63208,63209,63212,63213,63214,63631,63632,63423,63633,63424,63628,63629,63630,63421);
update creature_template set minlevel = 88, maxlevel = 88, speed_run = 1, speed_walk = 1, faction = 16, unit_flags = 33554432, ScriptName = 'npc_tayak_storm_unleashed_veh', flags_extra = 128 where entry in (63278,63299,63300,63301,63302,63303);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (125327,124033,123600);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 125327, 0, 0, 31, 0, 3, 62543, 0, 0, 0, '', NULL),
(13, 1, 124033, 0, 0, 31, 0, 3, 62543, 0, 0, 0, '', NULL),
(13, 1, 123600, 0, 0, 31, 0, 3, 63207, 0, 0, 0, '', NULL),
(13, 1, 123600, 0, 1, 31, 0, 3, 63208, 0, 0, 0, '', NULL),
(13, 1, 123600, 0, 2, 31, 0, 3, 63209, 0, 0, 0, '', NULL),
(13, 1, 123600, 0, 3, 31, 0, 3, 63212, 0, 0, 0, '', NULL),
(13, 1, 123600, 0, 4, 31, 0, 3, 63213, 0, 0, 0, '', NULL),
(13, 1, 123600, 0, 5, 31, 0, 3, 63214, 0, 0, 0, '', NULL);

delete from areatrigger_data where entry = 381;
INSERT INTO `areatrigger_data` (`entry`, `spellId`, `customEntry`, `customVisualId`, `Radius`, `RadiusTarget`, `Height`, `HeightTarget`, `Float4`, `Float5`, `isMoving`, `moveType`, `waitTime`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `hitType`, `MoveCurveID`, `ElapsedTime`, `MorphCurveID`, `FacingCurveID`, `ScaleCurveID`, `HasFollowsTerrain`, `HasAttached`, `HasAbsoluteOrientation`, `HasDynamicShape`, `HasFaceMovementDir`, `windX`, `windY`, `windZ`, `windSpeed`, `windType`, `polygon`, `comment`) VALUES 
(381, 125301, 3316, 10704, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1, 0, 'Lord Ta yak - Blade Tempest');

delete from spell_dummy_trigger where spell_id = 123600;
INSERT INTO `spell_dummy_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `comment`) VALUES 
(123600, 0, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Storm Unleashed');

delete from spell_target_filter where spellId = 123600;
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(123600, 7, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, -1, 'Storm Unleashed');

delete from world_visible_distance where type = 2 and id = 6297;
INSERT INTO `world_visible_distance` (`type`, `id`, `distance`, `comment`) VALUES 
(2, 6297, 200, 'Сердце Страха');