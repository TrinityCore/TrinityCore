delete from creature where id in (59974, 59884, 59930, 58542, 59893);
update creature_template set ScriptName = 'boss_thalnos_the_soulrender' where entry = 59789;
update creature_template set ScriptName = 'npc_empowering_spirit' where entry = 59893;
update creature_template set unit_flags = 512, ScriptName = 'npc_fallen_crusader' where entry = 59884;
update creature_template set ScriptName = 'npc_empowered_zombie' where entry = 59930;

update creature_difficulty_stat set dmg_multiplier = 30 where entry = 59884;
update creature_difficulty_stat set dmg_multiplier = 300 where entry = 59930;

delete from areatrigger_actions where entry = 220;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `comment`) VALUES 
(220, 0, 1, 0, 2, 115291, 0, 0, 0, 0, 0, 0, 'Thalnos - Spirit Gale on enter enemy'),
(220, 1, 42, 1, 2, 115291, 0, 0, 0, 0, 0, 0, 'Thalnos - Spirit Gale exit');

delete from areatrigger_data where entry = 220;
INSERT INTO `areatrigger_data` (`entry`, `sphereScale`, `sphereScaleMax`, `isMoving`, `moveType`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `customEntry`, `hitType`, `Height`, `RadiusTarget`, `Float5`, `Float4`, `Radius`, `HeightTarget`, `MoveCurveID`, `ElapsedTime`, `comment`) VALUES 
(220, 2, 2, 0, 0, 0, 0, 0, 0, 23612, 2857, 0, 0, 0, 0, 0, 0, 0, 0, 242, 'Thalnos - Spirit Gale');

delete from spell_target_filter where spellid in (115309, 115157);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(115309, 15, 8, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 'Evicted Soul'),
(115157, 7, 0, 0, 0, 0, 0, 0, 7, 2, 1, 0, 0, -1, 'Empowering Spirit');

delete from spell_linked_spell where spell_trigger = 115304;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) VALUES 
(115304, 115305, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Evict Soul');

delete from spell_proc_event where entry = 115306;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(115306, 0, 0, 0, 0, 0, 0, 4, 0, 0, 100, 0, 7);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 115157;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 115157, 0, 0, 31, 0, 3, 59884, 0, 0, 0, '', NULL);

delete from achievement_criteria_data where criteria_id = 20063;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(20063, 11, 0, 0, 'achievement_empowered_spiritualist');

delete from creature_text where entry = 59789;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(59789, 0, 0, 'Вы разделите мое вечное страдание!', 14, 0, 100, 0, 0, 27832, 'Талнос Воздаятель Душ to Player'),
(59789, 1, 0, 'Покой? Смерть приносит лишь мучение!', 14, 0, 100, 0, 0, 27831, 'Талнос Воздаятель Душ to 0'),
(59789, 2, 0, 'Найди... и обрети... тело!', 14, 0, 100, 0, 0, 27834, 'Талнос Воздаятель Душ to Player'),
(59789, 3, 0, '|TInterface\\Icons\\spell_warlock_demonsoul.blp:20|t%s применяет |cFFFF0000|Hspell:115297|h[Изгнание души]|h|r на |cFF006EFD|3-3($n)|r!', 41, 0, 100, 0, 0, 0, 'Талнос Воздаятель Душ to Player'),
(59789, 4, 0, '|TInterface\\Icons\\ability_warlock_jinx.blp:20|t%s начинает призывать |cFFFF0000|Hspell:115147|h[Могучих духов]|h|r!', 41, 0, 100, 0, 0, 0, 'Талнос Воздаятель Душ to 0'),
(59789, 5, 0, 'Найди тело и жестоко отомсти врагам!', 14, 0, 100, 0, 0, 27835, 'Талнос Воздаятель Душ to 0'),
(59789, 6, 0, 'Неужели... это конец?..', 14, 0, 100, 0, 0, 27830, 'Талнос Воздаятель Душ to Player');