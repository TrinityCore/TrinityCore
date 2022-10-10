delete from creature where map = 1136 and id in
(72248,72302,72561,72311,72560,73910,73909,72312,72313,72549,62822,50850,
72548,72534,72581,72579,72580,73493,73494,73495,73496,73550,62821,60484,
73551,73552,73553,73565,73628,72408,72356,72357,72947,72355,73086,72456,
72941,72942,72943,72945,72352,72353,72958,73310,73100,73094,73088);

update creature_template set speed_fly = 3, rank = 3, flags_extra = 1, ScriptName = 'boss_galakras' where entry = 72249;
delete from creature where id = 72249;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(72249, 1136, 6738, 6800, 16536, 1, 0, 0, 1409.42, -4815.51, 77.2564, 4.98926, 604800, 0, 0, 416946976, 1000, 0, 0, 0, 0, 0, 0);

update gameobject_template set flag = 48 where entry in (221916, 223044);
delete from gameobject where id in (221916, 223044);
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
(221916, 1136, 6738, 6800, 16536, 1, 1368.15, -4845.38, 32.7172, 5.4018, 0.00426456, 0.00262746, -0.426574, 0.904439, 7200, 255, 1, 0),
(223044, 1136, 6738, 6800, 16536, 1, 1459.69, -4812.72, 29.3937, 4.36332, 0, 0, -0.819152, 0.573577, 7200, 255, 1, 0);

update creature_template set flags_extra = 2 where entry = 72248;
update creature_template set minlevel = 90, maxlevel = 90, ScriptName = 'npc_demolitions' where entry in (73550,73552,73493,73495);
update creature_template set spell1 = 146488 where entry = 72408;
update creature_template set minlevel = 90, maxlevel = 90 where entry in (73493,73494,73495,73496,73550,73551,73552,73553);
update creature_template set gossip_menu_id = 15992, RegenHealth = 0, ScriptName = 'npc_jaina_or_sylvana' where entry = 72302;
update creature_template set gossip_menu_id = 15803, npcflag = 1, RegenHealth = 0, ScriptName = 'npc_varian_or_lorthemar' where entry = 72311;
update creature_template set gossip_menu_id = 72560, npcflag = 1, RegenHealth = 0, ScriptName = 'npc_varian_or_lorthemar' where entry = 72560;
update creature_template set spell1 = 147328 where entry = 73310;
update creature_template set RegenHealth = 0, ScriptName = 'npc_jaina_or_sylvana' where entry = 72561;
update creature_template set RegenHealth = 0, ScriptName = 'npc_verees_or_aethas' where entry in (73910, 73909);
update creature_template set ScriptName = 'npc_korkron_demolisher' where entry = 72947;
update creature_template set ScriptName = 'npc_high_enforcer_thranok' where entry = 72355;
update creature_template set ScriptName = 'npc_korgra_the_snake' where entry = 72456;
update creature_template set ScriptName = 'npc_dragonmaw_flagbearer' where entry = 72942;
update creature_template set ScriptName = 'npc_dragonmaw_proto_drake' where entry = 72943;
update creature_template set ScriptName = 'npc_dragonmaw_bonecrusher' where entry = 72945;
update creature_template set ScriptName = 'npc_dragonmaw_ebon_stalker' where entry = 72352;
update creature_template set ScriptName = 'npc_dragonmaw_tidal_shaman' where entry = 72958;
update creature_template set ScriptName = 'npc_korkron_elite_sniper' where entry = 72261;
update creature_template set ScriptName = 'npc_galakras_south_tower' where entry = 73565;
update creature_template set ScriptName = 'npc_galakras_north_tower' where entry = 73628;
update creature_template set ScriptName = 'npc_antiair_turret' where entry = 72408;
update creature_template set ScriptName = 'npc_master_cannoneer_dagryn' where entry = 72356;
update creature_template set ScriptName = 'npc_lieutenant_krugruk' where entry = 72357;
update creature_template set ScriptName = 'npc_dragonmaw_flameslinger' where entry = 72353;
update creature_template set ScriptName = 'npc_dragonmaw_grunt' where entry = 72941;
update creature_template set ScriptName = 'npc_korkron_cannon' where entry = 72358;
update creature_template set ScriptName = 'npc_pressure_mine' where entry = 72910;
update creature_template set speed_walk = 1.6, speed_run = 1.4, faction_a = 1771, faction_h = 1771, equipment_id = entry, ScriptName = 'npc_dragonmaw_grunt_h' where entry = 73530;

delete from vehicle_template_accessory where EntryOrAura = 72249;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(72249, 72248, 0, 1, 'Boss Galakras', 6, 30000);

delete from creature_template_addon where entry in (73094, 72942);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(73094, 0, 0, 0, 1, 0, '146754'),
(72942, 0, 0, 0, 1, 0, '145232');

delete from areatrigger_scripts where entry in (9360,9361,9357);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(9360, 'at_galakras_towers'),
(9361, 'at_galakras_towers'),
(9357, 'at_siege_of_orgrimmar_sniper_shoot_me');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (146899,148243,148041,148042,147814,145752,148506,149467,147204);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 3, 146899, 0, 0, 31, 0, 3, 72302, 0, 0, 0, '', NULL),
(13, 3, 146899, 0, 1, 31, 0, 3, 72561, 0, 0, 0, '', NULL),
(13, 3, 146899, 0, 2, 31, 0, 3, 72311, 0, 0, 0, '', NULL),
(13, 3, 146899, 0, 3, 31, 0, 3, 72560, 0, 0, 0, '', NULL),
(13, 3, 146899, 0, 4, 31, 0, 3, 73910, 0, 0, 0, '', NULL),
(13, 3, 146899, 0, 5, 31, 0, 3, 73909, 0, 0, 0, '', NULL),
(13, 1, 148243, 0, 0, 31, 0, 3, 73493, 0, 0, 0, '', NULL),
(13, 1, 148243, 0, 1, 31, 0, 3, 73495, 0, 0, 0, '', NULL),
(13, 1, 148243, 0, 2, 31, 0, 3, 73550, 0, 0, 0, '', NULL),
(13, 1, 148243, 0, 3, 31, 0, 3, 73552, 0, 0, 0, '', NULL),
(13, 1, 148041, 0, 0, 31, 0, 3, 73530, 0, 0, 0, '', NULL),
(13, 1, 148042, 0, 0, 31, 0, 3, 73530, 0, 0, 0, '', NULL),
(13, 1, 147814, 0, 0, 31, 0, 3, 72656, 0, 0, 0, '', NULL),
(13, 4, 145752, 0, 0, 31, 0, 3, 72358, 0, 0, 0, '', NULL),
(13, 16, 145752, 0, 0, 31, 0, 3, 72656, 0, 0, 0, '', NULL),
(13, 4, 148506, 0, 0, 31, 0, 3, 72910, 0, 0, 0, '', NULL),
(13, 1, 149467, 0, 0, 31, 0, 3, 72358, 0, 0, 0, '', NULL),
(13, 2, 147204, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', NULL),
(13, 1, 147204, 0, 0, 31, 0, 3, 0, 0, 0, 0, '', NULL);

delete from gossip_menu where entry in (15803,15992,72560);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(15803, 22732),
(15992, 23053),
(72560, 72560);

delete from gossip_menu_option where menu_id in (15803,15992,72560);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(15803, 0, 0, 'Мои солдаты – ваши солдаты, о мой король.', 1, 1, 0, 0, 0, 0, 'Начать бой?'),
(15992, 0, 0, 'Мы в вашем распоряжении.', 1, 1, 0, 0, 0, 0, 'Начать бой?'),
(72560, 0, 0, 'Мы в вашем распоряжении.', 1, 1, 0, 0, 0, 0, 'Начать бой?');

delete from npc_text where id in (22732,72560);
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES 
(22732, 'Итак, мы вступаем в войну. Подайте мне сигнал, когда солдаты будут готовы, и я отдам команду к наступлению.'),
(72560, 'Вот что важно, герой. Подай мне сигнал, когда будешь $gготов:готова; выступить в атаку. И постарайся удержать леди Сильвану в строю, хорошо?');

delete from npc_spellclick_spells where npc_entry in (72408,72249,72656);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(72408, 93970, 1, 0),
(72249, 46598, 1, 0),
(72656, 147814, 1, 0);

delete from spell_script_names where spell_id in(147897, 147916, 146991);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(147897, 'spell_most_complicated_bomb'),
(147916, 'spell_most_complicated_bomb'),
(146991, 'spell_galakras_flames_of_galakrond');

delete from areatrigger_data where entry in (1259,1283,1287,1340,1203,1301);
INSERT INTO `areatrigger_data` (`entry`, `radius`, `radius2`, `isMoving`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `customVisualId`, `customEntry`, `comment`) VALUES 
(1259, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OO: Flame Arrows'),
(1283, 30, 0, 0, 0, 0, 0, 0, 0, 0, 'OO War Banner'),
(1287, 12, 0, 0, 0, 0, 0, 0, 0, 0, 'OO Jaina Blizzard'),
(1340, 12, 0, 0, 0, 0, 0, 0, 0, 0, 'OO Sylvana Flamestrike'),
(1203, 1, 0, 0, 0, 0, 0, 1, 0, 0, 'OO: Spike Mine'),
(1301, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'OO: Poison Cloud');

delete from areatrigger_actions where entry in (1259,1259,1283,1283,1287,1287,1340,1340,1203,1301);
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `comment`) VALUES 
(1259, 0, 1, 0, 2, 146765, 0, 0, 0, 0, 'OO: Flame Arrows on enter cast'),
(1259, 1, 42, 1, 2, 146765, 0, 0, 0, 0, 'OO: Flame Arrows on exit remove'),
(1283, 0, 1, 0, 1, 146735, 0, 0, 0, 0, 'OO War Banner spawn cast friendly'),
(1283, 1, 40, 1, 1, 146735, 0, 0, 0, 0, 'OO War Banner despawn remove friendly'),
(1287, 0, 1, 0, 2, 147431, 0, 0, 0, 0, 'OO Jaina Blizzard on enter enemy'),
(1287, 1, 42, 1, 2, 147431, 0, 0, 0, 0, 'OO Jaina Blizzard exit enemy'),
(1340, 0, 1, 0, 2, 147431, 0, 0, 0, 0, 'OO Sylvana Flamestrike on enter enemy'),
(1340, 1, 42, 1, 2, 147431, 0, 0, 0, 0, 'OO Sylvana Flamestrike exit enemy'),
(1203, 0, 1, 0, 8, 148506, 0, 0, 0, 0, 'OO: Spike Mine Detonation on player entry'),
(1301, 0, 1, 0, 2, 147705, 0, 0, 0, 0, 0, 'OO: Poison Cloud on enter'),
(1301, 1, 42, 1, 2, 147705, 0, 0, 0, 0, 0, 'OO: Poison Cloud on exit');

delete from spell_trigger_dummy where spell_id in (144037,147438,148520,148522,146769,146775);
INSERT INTO `spell_trigger_dummy` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `check_spell_id`, `comment`) VALUES 
(144037, 0, 14, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'OO: Ping Boss'),
(147438, 0, 14, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'OO: Flame Arrows'),
(148520, 0, 14, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'OO: Tidal Wave'),
(148522, 0, 14, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'OO: Tidal Wave'),
(146769, 0, 14, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'OO: Crusher\'s Call'),
(146775, 0, 15, 0, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'OO: Crusher\'s Call');

delete from spell_target_filter where spellId = 146769;
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(146769, 15, 0, 0, 0, 0, 0, 0, 7, 0, 5, 10, 0, 0, 'OO: Crusher\'s Call');

delete from creature_equip_template where entry = 73530;
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES 
(73530, 94650, 0, 0);

update creature_template set AIName = 'SmartAI' where entry = 72656;
delete from smart_scripts where entryorguid = 72656;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(72656, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - State passive'),
(72656, 0, 1, 0, 8, 0, 100, 1, 147814, 0, 0, 0, 11, 145752, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SpellHit - Cast Spike Mine Detonation'),
(72656, 0, 2, 0, 8, 0, 100, 0, 145752, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SpellHit - Despawn');

delete from creature_text where entry in (72248,72302,72311,72356,72357,72408,72560,72561,72947,73494,73551,73565,73628,73909);
insert into `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) values
('72248','0','0','Воины Драконьей Пасти! Отбейте пристань и сбросьте врага в море! Во имя Истинной Орды!','14','0','100','25','0','38391','Полководец Зела to Галакрас'),
('72248','1','0','Драконья Пасть, вперед!','14','0','100','0','0','38394','Полководец Зела to Player'),
('72248','2','0','За Гарроша!','14','0','100','5','0','38395','Полководец Зела to Player'),
('72248','3','0','Они ворвались в башню. Разрушить ее!','14','0','100','0','0','38397','Полководец Зела to Специалист-взрывотехник'),
('72248','4','0','Следующий отряд!','14','0','100','0','0','38393','Полководец Зела to Player'),
('72248','5','0','Направьте орудия на башню! Похороните их заживо!','14','0','100','0','0','38399','Полководец Зела to Специалист-взрывотехник'),
('72248','6','0','Галакрас теряет высоту, но приходит в себя после выстрела!','41','0','100','0','0','0','Полководец Зела to Протодракон клана Драконьей Пасти'),
('72248','7','0','%s от удара вылетает из седла!','41','0','100','0','0','38154','Полководец Зела to Галакрас'),
('72248','8','0','Аргх!','14','0','100','0','0','38154','Полководец Зела to Галакрас'),
('72248','9','0','Думаете, вы победили? Мы – орки! Братья по крови, ведомые величайшим вождем! Ваша кровь наполнит залив!','14','0','100','0','0','38402','Полководец Зела to Галакрас'),
('72302','0','0','Вот и они!','14','0','100','1','0','38099','Леди Джайна Праудмур to Полководец Зела'),
('72302','1','0','Я вызвала снежную бурю, ведите их в нее!','14','0','10','0','0','38100','Леди Джайна Праудмур to 0'),
('72302','2','0','Она направляет орудия на собственные башни!','14','0','100','0','0','38085','Леди Джайна Праудмур to Полководец Зела'),
('72302','3','0','Осталась еще одна!','14','0','100','0','0','38086','Леди Джайна Праудмур to Player'),
('72302','4','0','Получилось! Протодракон сбит!','14','0','100','0','0','38087','Леди Джайна Праудмур to Галакрас'),
('72302','5','0','Это победа!','14','0','0','0','0','38088','Леди Джайна Праудмур'),
('72302','6','0','Мы будем удерживать пристань до конца высадки. Идите к воротам Оргриммара и обменяйтесь новостями с Вол\'джином и его повстанцами.','14','0','0','0','0','38089','Леди Джайна Праудмур'),
('72311','0','0','Посмотрим, удалось ли ему выполнить свою часть сделки.','14','0','100','1','0','38947','Король Вариан Ринн to Леди Джайна Праудмур'),
('72311','1','0','Обе готовы! Стреляйте!','14','0','100','22','0','38944','Король Вариан Ринн to Player'),
('72311','2','0','Ха-ха-ха! Большому кораблю...','14','0','100','153','0','38946','Король Вариан Ринн'),
('72356','0','0','Поджечь запалы! Они не уйдут живыми!','14','0','100','5','0','38740','Мастер-канонир Дагрин to 0'),
('72356','1','0','И это все?','14','0','100','153','0','38742','Мастер-канонир Дагрин to Мастер-канонир Дагрин'),
('72356','2','0','Я умираю... с честью...','14','0','100','0','0','38741','Мастер-канонир Дагрин to Player'),
('72357','0','0','Вы пришли захватить мою башню? Ха-ха-ха...','14','0','100','574','0','38737','Лейтенант Кругрук to 0'),
('72357','1','0','Я воин Драконьей Пасти, я – сила драконов, кулак Орды!','14','0','100','5','0','38739','Лейтенант Кругрук to 0'),
('72357','2','0','Вам... не выиграть... войну...','14','0','100','0','0','38738','Лейтенант Кругрук to Player'),
('72408','0','0','Игроки захватывают противовоздушную турель южной башни!','41','0','100','0','0','38153','Противовоздушная турель to Player'),
('72408','1','0','Игроки захватывают противовоздушную турель северной башни!','41','0','100','0','0','38293','Противовоздушная турель to Player'),
('72560','0','0','Отлично, первый отряд высадился.','12','0','100','1','0','38167','Лор\'темар Терон to Player'),
('72560','1','0','Тактика, Темная Госпожа. Два слова: береговая оборона.','12','0','100','1','0','38168','Лор\'темар Терон to Player'),
('72560','2','0','Герои, захватите башни и сбейте этого дракона из пушек!','12','0','100','5','0','38169','Лор\'темар Терон to Player'),
('72560','3','0','Кто-то должен удерживать зону высадки.','12','0','100','1','0','38170','Лор\'темар Терон to Player'),
('72560','4','0','Они атакуют свои же башни!','14','0','100','5','0','38152','Лор\'темар Терон to Полководец Зела'),
('72560','5','0','Полдела сделано!','14','0','100','5','0','38153','Лор\'темар Терон to Player'),
('72560','6','0','Иногда я сам себе удивляюсь. Дракон сбит!','14','0','100','6','0','38154','Лор\'темар Терон to Галакрас'),
('72560','7','0','Наконец-то! Теперь придется выбивать пыль с одежды.','14','0','100','5','0','38155','Лор\'темар Терон to Player'),
('72560','8','0','Я буду считать это комплиментом. Мы перегруппируемся и будем удерживать пристань. Вол\'джин ждет вас у ворот города.','14','0','100','1','0','38156','Лор\'темар Терон to Player'),
('72561','0','0','Сбейте ее скорее, не терпится взять ее за глотку.','14','0','100','1','0','38303','Леди Сильвана Ветрокрылая to Полководец Зела'),
('72561','1','0','Только моими стрелами это чудовище не сразить.','12','0','100','1','0','38302','Леди Сильвана Ветрокрылая to Лор\'темар Терон'),
('72561','2','0','Со вторым покончено.','14','0','100','0','0','38293','Леди Сильвана Ветрокрылая to Player'),
('72561','3','0','Надеюсь, ты понимаешь, что мы прямо под ним, правда?','14','0','100','0','0','38294','Леди Сильвана Ветрокрылая to Лор\'темар Терон'),
('72561','4','0','Я не погибну. Не сейчас!','14','0','100','0','0','38289','Леди Сильвана Ветрокрылая to 0'),
('72561','5','0','А, ты все еще тут? Я так надеялась, что тебя настигла смерть. Ты был бы очень привлекательным мертвецом.','14','0','100','0','0','38295','Леди Сильвана Ветрокрылая to Лор\'темар Терон'),
('72561','6','0','Значит, клан Драконьей Пасти заодно с Гаррошем.','12','0','100','1','0','38301','Леди Сильвана Ветрокрылая to Лор\'темар Терон'),
('72947','0','0','Полководец Зела приказывает |cFFFF0404|hКор\'кронскому разрушителю|h|r атаковать башню!','41','0','100','0','0','38397','Кор\'кронский разрушитель to Специалист-взрывотехник'),
('72947','1','0','Полководец Зела приказывает |cFFFF0404|hКор\'кронскому разрушителю|h|r атаковать башню!','41','0','100','0','0','0','Кор\'кронский разрушитель to Специалист-взрывотехник'),
('73494','0','0','Подожди!','12','0','0','4','0','0',''),
('73551','0','0','Подожди!','12','0','100','4','0','0','Помощник специалиста-взрывотехника to Помощник специалиста-взрывотехника'),
('73565','0','0','Дверь южной башни разбита!','41','0','100','0','0','0','Башня to Специалист-взрывотехник'),
('73628','0','0','Дверь северной башни разбита!','41','0','100','0','0','0','Башня to Специалист-взрывотехник'),
('73909','0','0','Я вызываю огненный столб, ведите их!','14','0','10','0','0','38152','Верховный маг Этас Похититель Солнца to 0');