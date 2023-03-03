delete from creature where id = 59198;

update creature_template set faction_a = 2579, faction_h = 2579, ScriptName = 'boss_flameweaver_koegler', mechanic_immune_mask = `mechanic_immune_mask` &~ (33554432) where entry = 59150;
update creature_template set faction_a = 2580, faction_h = 2580, inhabittype = 7, flags_extra = 130 where entry = 59209;
update creature_template set speed_fly = '1.5', inhabitType = 7, ScriptName = 'npc_dragon_breath_target', flags_extra = 130 where entry = 59198;
update creature_template set ScriptName = 'npc_book_case', flags_extra = 130 where entry = 59155;

delete from areatrigger_scripts where entry = 8317;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(8317, 'at_koegler_enter_room');

delete from conditions where SourceTypeOrReferenceId = 17 and SourceEntry = 114795;
delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (113641, 113366);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 114795, 0, 0, 31, 1, 3, 59209, 0, 0, 0, '', NULL),
(13, 3, 113641, 0, 0, 31, 0, 3, 59198, 0, 0, 0, '', NULL),
(13, 1, 113366, 0, 0, 31, 0, 3, 59155, 0, 0, 0, '', NULL);

delete from spell_target_filter where spellId in (126645,113366);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(126645, 7, 0, 0, 0, 0, 0, 0, 7, 2, 1, 0, 0, -1, 'Koegler - Cosmetic Flame'),
(113366, 7, 0, 0, 0, 0, 0, 0, 7, 2, 1, 0, 0, -1, 'Koegler - Book Burner');

delete from spell_trigger_dummy where spell_id in (113657,126642,126645,113366);
INSERT INTO `spell_trigger_dummy` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `check_spell_id`, `comment`) VALUES 
(113657, 114795, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'Koegler - Greater Dragon Breath'),
(126642, 114795, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'Koegler - Cosmetic Flame'),
(126645, 126642, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'Koegler - Cosmetic Flame'),
(113366, 113364, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'Koegler - Book Burner');

delete from spell_target_position where id = 113626;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(113626, 1001, 1298.13, 549.524, 12.7952, 3.14987);

delete from creature_text where entry in (59150,64764);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(59150, 0, 0, 'Сжечь, сжечь все... Никто не должен узнать о позоре Алого ордена!', 14, 0, 100, 0, 0, 29524, 'Ткач пламени Кеглер to Player'),
(59150, 1, 0, 'И вы тоже обратитесь в пепел!', 14, 0, 100, 0, 0, 29522, 'Ткач пламени Кеглер to Player'),
(59150, 2, 0, '|TInterface\\Icons\\ability_warlock_inferno.blp:20|t%s начинает использовать |cFFFF0000|Hspell:113364|h[Сжигатель книг]|h|r!', 41, 0, 100, 0, 0, 0,'Ткач пламени Кеглер to Книжный шкаф'),
(59150, 3, 0, '|TInterface\\Icons\\inv_misc_head_dragon_01.blp:20|t%s начинает использовать |cFFFF0000|Hspell:113653|h[Дыхание великого дракона]|h|r!', 41, 0, 100, 0, 0, 0,'Ткач пламени Кеглер to 0'),
(59150, 4, 0, 'Рукописи горят!', 14, 0, 100, 0, 0, 29528, 'Ткач пламени Кеглер to 0'),
(59150, 4, 1, 'Дыхание дракона!', 14, 0, 100, 0, 0, 29527, 'Ткач пламени Кеглер to 0'),
(59150, 5, 0, 'Мой огонь... угас...', 14, 0, 100, 0, 0, 29523, 'Ткач пламени Кеглер to Player'),
(64764, 0, 0, 'Там лежит немало тел. Отличная работа, $p.', 12, 0, 100, 21, 0, 0, 'Рыцарь в капюшоне to Player'), -- Knight
(64764, 1, 0, 'Присев на колени, рыцарь в капюшоне осматривает и обыскивает тело ткача пламени.', 16, 0, 100, 0, 0, 0, 'Рыцарь в капюшоне to Player'),
(64764, 2, 0, 'Удалось достать кодекс?', 12, 0, 100, 6, 0, 0, 'Рыцарь в капюшоне to Player');