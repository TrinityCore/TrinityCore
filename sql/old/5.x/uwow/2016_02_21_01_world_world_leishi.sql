update creature_template set minlevel = 93, maxlevel = 93, faction = 16, unit_flags2 = 69208064, ScriptName = 'npc_lei_shi_clone' where entry = 63099;

delete from areatrigger_data where entry in (408,409);
INSERT INTO `areatrigger_data` (`entry`, `spellId`, `customEntry`, `customVisualId`, `Radius`, `RadiusTarget`, `Height`, `HeightTarget`, `Float4`, `Float5`, `isMoving`, `moveType`, `waitTime`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `hitType`, `MoveCurveID`, `ElapsedTime`, `MorphCurveID`, `FacingCurveID`, `ScaleCurveID`, `HasFollowsTerrain`, `HasAttached`, `HasAbsoluteOrientation`, `HasDynamicShape`, `HasFaceMovementDir`, `windX`, `windY`, `windZ`, `windSpeed`, `windType`, `polygon`, `comment`) VALUES 
(408, 123461, 3385, 25420, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1017.96, -2911.15, 19.8185, -5, 1, 0, 'LeiShi - GetAway'),
(409, 123461, 3386, 25420, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1017.96, -2911.15, 19.8185, -5, 1, 0, 'LeiShi - GetAway');

delete from spell_script_names where spell_id in (123181,123233,123461,123705);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(123181, 'spell_leishi_afraid'),
(123233, 'spell_leishi_hide_proc'),
(123461, 'spell_leishi_get_away'),
(123705, 'spell_leishi_scary_fog');

delete from spell_proc_event where entry = 123233;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(123233, 0, 0, 0, 0, 0, 0, 139808, 0, 0, 100, 1, 1);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (132363);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 132363, 0, 0, 31, 0, 3, 63099, 0, 0, 0, '', NULL);

delete from spell_target_position where id = 123441;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(123441, 996, -1017.96, -2911.15, 19.8185, 4.71);

delete from spell_target_filter where spellid in (123705);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(123705, 15, 2, -1, 15, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'LeiShi - Scary Fog');