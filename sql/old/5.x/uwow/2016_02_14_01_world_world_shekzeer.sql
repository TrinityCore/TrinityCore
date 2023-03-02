update creature_template set mechanic_immune_mask = 650854399, ScriptName = 'npc_generic_royal_sentinel' where entry = 63589;
update creature_template set ScriptName = '' where entry = 64453;
update creature set id = 64453 where id = 63589;

delete from spell_target_filter where spellId in (123735,129149,125390,129154);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(123735, 15, 0, 0, 0, 0, 0, 0, 3, 1, 2, 5, 0, 0, 'Dread Screech'),
(129149, 7, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Shekzeer - Fixate'),
(125390, 15, 0, 0, 0, 0, 0, 0, 3, 2, 1, 0, 0, 0, 'Shekzeer - Fixate'),
(129154, 7, 0, 0, 0, 0, 0, 0, 3, 2, 1, 0, 0, 0, 'Shekzeer - Dispatch');

delete from spell_script_names where spell_id in (124843);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(124843, 'spell_shekzeer_amassing_darkness');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (129149,129154);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 129149, 0, 0, 31, 0, 3, 63589, 0, 0, 0, '', NULL),
(13, 1, 129154, 0, 0, 31, 0, 3, 63589, 0, 0, 0, '', NULL);
