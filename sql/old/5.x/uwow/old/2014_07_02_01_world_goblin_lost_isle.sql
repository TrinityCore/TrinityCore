/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

UPDATE `quest_poi` SET WorldMapAreaId = 544 WHERE `questId` in (14001, 14014, 14019, 14021, 14031, 14233, 14234, 14235, 14236, 14237, 14238, 14239, 14240, 14241, 14242, 14243, 14244, 14245, 14248, 14303, 14326, 14445, 14473, 14474, 24671, 24741, 24744, 24816, 24817, 24856, 24858, 24859, 24860, 24864, 24868, 24897, 24901, 24925, 24929, 24935, 24936, 24937, 24940, 24942, 24945, 24946, 24952, 24954, 24958, 25023, 25024, 25058, 25066, 25093, 25098, 25099, 25100, 25109, 25110, 25122, 25123, 25124, 25125, 25184, 25200, 25201, 25202, 25203, 25204, 25207, 25213, 25214, 25225, 25231, 25243, 25244, 25251, 25265);
UPDATE `quest_template` SET level = -1 WHERE `ZoneOrSort` = 4720;

-- some creatures in all phases.
UPDATE `creature` SET phaseMask = phaseMask | 8 | 4 | 2 WHERE `id` in (35904, 36383);

UPDATE `creature_template_addon` SET `bytes1` = '0' WHERE `entry` = 36383;
-- --------------------------------
--          INTRO
-- --------------------------------

DELETE FROM `quest_end_scripts` WHERE id =14126;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(14126, 0, 34, 22, 0, 0, 0, 0, 0, 0),
(14126, 2, 6, 648, 0, 0, 533.77, 3274.62, 0.198194, 4.90527);

UPDATE `quest_template` SET `PrevQuestId` = '14239' WHERE `Id` = 14474;
UPDATE `quest_template` SET `NextQuestId` = '14474' WHERE `Id` = 14239;
DELETE FROM creature_involvedrelation WHERE quest = 14001;
DELETE FROM creature_questrelation WHERE quest = 14001;


-- stan at while not take first quest. intro ivent.
DELETE FROM spell_area WHERE spell = 69010 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('69010', '4720', '14126', '14239', '0', '0', '2', '1', '64', '74');

DELETE FROM `spell_target_position` WHERE id = 69018;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('69018', '648', '537.135', '3272.25', '0.18', '5.576622');

UPDATE `creature_template` SET `ScriptName` = 'npc_gizmo', `npcflag` = '2' WHERE `entry` = 36600;
UPDATE `creature_template` SET `ScriptName` = 'npc_doc_zapnnozzle', `npcflag` = '0' WHERE `entry` = 36608;
DELETE FROM `creature` WHERE `id` = 36608;

DELETE FROM `creature_text` WHERE `entry` = 36608;
INSERT INTO `creature_text` (`entry`,`id` , `groupid`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
('36608', '0', '0', 'Механил, что ты тут расселся? Разве не видишь, кто рядом с тобой лежит?!', '12', '0', '100', '396', '0', '0', ''), 
('36608', '0', '1', 'Это же $N! Только благодаря $gему:ей; мы все еще дышим, а не превратились в поджаристые шкварки уже там, на Кезане.', '12', '0', '100', '396', '0', '0', ''), 
-- 69085
('36608', '0', '2', 'Отойди, сейчас я $gего:ее; воскрешу. Надеюсь, мой дефибриллятор не испортился от воды!', '12', '0', '100', '396', '0', '0', ''), 
-- 69022 x5
('36608', '0', '3', 'Ну же! Разряд!', '12', '0', '100', '396', '0', '0', ''), 
-- 69022 x5
('36608', '0', '4', 'Я сделал все, что мог. Ты слышишь меня, $N? Очнись! Не иди к Свету!', '12', '0', '100', '396', '0', '0', '');
-- 69013

DELETE FROM `creature_text` WHERE `entry` = 36600;
INSERT INTO `creature_text` (`entry`,`id` , `groupid`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
('36600', '0', '0', 'Это $N?! Извини, док, я думал, что $gего:ее; убили!', '12', '0', '100', '0', '0', '0', ''); 

-- --------------------------------
--          PHASE 1
-- --------------------------------

-- --------
-- Q: 14474 Goblin Escape Pods
-- --------

DELETE FROM `creature` WHERE `id` = 34748;
UPDATE `gameobject` SET phaseMask = 1 WHERE `id` = 195188;

DELETE FROM spell_area WHERE spell in(68258, 68256) AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('68258', '4720', '14474', '0', '0', '0', '2', '1', '10', '0'),
('68256', '4720', '14474', '0', '0', '0', '2', '1', '10', '0');

-- 67845 summon prince

UPDATE `quest_template` SET  `CompleteScript` =  '0', StartScript = '0' WHERE  `Id` IN (14474, 14001);
DELETE FROM `quest_end_scripts` WHERE `id` = 24;
DELETE FROM `quest_start_scripts` WHERE `id` = 48;

-- simple event script on go use.
DELETE FROM `event_scripts` WHERE id = 195188;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(195188, 1, 8, 34748, 0, 0, 0, 0, 0, 0),
(195188, 1, 10, 34748, 15000, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34748;
DELETE FROM smart_scripts WHERE entryorguid = 34748;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34748, 0, 0, 0, 11, 0, 100, 0, 0, 0, 8000, 0, 1, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 'Say text at summon');

DELETE FROM `creature_text` WHERE entry = 34748;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34748, 0, 0, '$N! Прошу тебя, скажи, что это чудовище – торговый принц – не выжил!', 12, 0, 100, 5, 0, 0, 'Уцелевший гоблин'),
(34748, 0, 1, 'Это безумие! Ты что, $gхотел:хотела; меня взорвать?!', 12, 0, 100, 5, 0, 0, 'Уцелевший гоблин'),
(34748, 0, 2, '$N? А мне говорили, что ты уже... того.', 12, 0, 100, 5, 0, 0, 'Уцелевший гоблин'),
(34748, 0, 3, '$N, это ты! Спасибо, $gбрат:лапочка;!', 12, 0, 100, 5, 0, 0, 'Уцелевший гоблин');

DELETE FROM `creature_text` WHERE entry = 36600 AND groupid = 1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36600, 1, 0, 'Да, многие до сих пор заперты в спасательных капсулах, босс. Хотя, стой. Ты же, кажется, больше не босс? Ну, в любом случае, все они утонут, если ты их оттуда не вытащишь.', 12, 0, 100, 1, 0, 0, 'Зуботочер Механил');

-- toD0.
DELETE FROM `creature_text` WHERE entry = 35649;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35649, 0, 0, 'Привет, $N. Как мило, что вы меня спасли! Надеюсь, никаких обид?', 12, 0, 100, 3, 0, 19562, 'Торговый принц Галливикс');

-- --------------------------------
--          PHASE 2
-- --------------------------------

DELETE FROM spell_area WHERE spell =  67851 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('67851', '4720', '14014', '14237', '0', '0', '2', '1', '74', '74');

UPDATE `quest_template` SET `Method` = '2' WHERE `quest_template`.`Id` = 14031;

-- Торговый принц Галливикс
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36403;
DELETE FROM smart_scripts WHERE entryorguid = 36403;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36403, 0, 0, 0, 60, 0, 100, 0, 30000, 60000, 30000, 60000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Say text at summon');
DELETE FROM `creature_text` WHERE entry = 36403;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36403, 0, 1, 'Меня не покидает мысль о том, что если бы кое-кто не лез не в свое дело еще на Кезане, мы бы уже были в Азшаре.', 14, 0, 100, 5, 0, 19590, 'Торговый принц Галливикс'),
(36403, 0, 0, 'Слушайте все сюда... Если со мной кто-то не согласен, он может начинать искать новую работу!', 14, 0, 100, 15, 0, 19593, 'Торговый принц Галливикс');


-- Q: 14473
DELETE FROM `creature_text` WHERE entry = 35786;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35786, 0, 0, '$N, лучше бы тебе разобраться с этими тероящерами-детенышами, пока они не разобрались с нами!', 12, 0, 100, 25, 0, 0, 'Максс Оползень'),
(35786, 1, 0, 'Слышишь рычание матриарха на утесе? Не попадайся ей!', 12, 0, 100, 6, 0, 0, 'Максс Оползень');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=35786;
DELETE FROM smart_scripts WHERE entryorguid = 35786;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35786, 0, 0, 0, 47, 0, 100, 0, 14473, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14473'),
(35786, 0, 1, 0, 50, 0, 100, 0, 14473, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At finish q: 14473');


-- --------
-- Q: 14019 target 34699 sound 18658 spell 67919
-- --------

DELETE FROM smart_scripts WHERE entryorguid = 34699;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34699, 0, 0, 1, 8, 0, 100, 0, 67917, 0, 0, 0, 33, 35760, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'SpellHit - Kill Credit'),
(34699, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Despawn'),
(34699, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 4, 18658, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Play sound'),
(34699, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 67919, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell');

DELETE FROM `creature_text` WHERE entry = 35758;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35758, 0, 0, 'Обезьянам эти бананы понравятся!', 12, 0, 100, 11, 0, 2304, 'Бамм Взрыбомм'),
(35758, 1, 0, 'Ничего красивее я еще не видел!', 12, 0, 100, 11, 0, 0, 'Бамм Взрыбомм');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=35758;
DELETE FROM smart_scripts WHERE entryorguid = 35758;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35758, 0, 0, 0, 47, 0, 100, 0, 14019, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14019'),
(35758, 0, 1, 0, 50, 0, 100, 0, 14019, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At finish q: 14019');

-- --------
-- Q: 14014, 14248, 14234
-- --------

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=35650;
DELETE FROM smart_scripts WHERE entryorguid = 35650;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35650, 0, 0, 0, 47, 0, 100, 0, 14014, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14014'),
(35650, 0, 1, 0, 47, 0, 100, 0, 14248, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14248'),
(35650, 0, 2, 0, 47, 0, 100, 0, 14234, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14234');

DELETE FROM `creature_text` WHERE entry = 35650;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35650, 0, 0, 'Чтобы выжить на этом пустынном острове, нам понадобятся все наши инструменты и все бомбы, $N.', 12, 0, 100, 0, 0, 0, 'Хамми Кофельнагель'),
(35650, 1, 0, 'Промоках у входа в пещеру, к юго-востоку отсюда.', 12, 0, 100, 1, 0, 0, 'Хамми Кофельнагель'),
(35650, 2, 0, 'Если мы хотим пережить все это, нам нужны друзья. Будем надеяться, орки не убьют тебя в первую же минуту.', 12, 0, 100, 273, 0, 0, 'Хамми Кофельнагель');

-- --------
-- Q: 14021
-- --------

-- 261091 - 260932
UPDATE `quest_template` SET `StartScript` = '0' WHERE `quest_template`.`Id` = 14021;
DELETE FROM `quest_start_scripts` WHERE `id` = 8;

UPDATE `creature_template_addon` SET `bytes1` = '0', `bytes2` = '0', auras=NULL WHERE `entry` in (36344, 35810);
UPDATE `creature_template` SET `dynamicflags` = '0', `RegenHealth` = '0' WHERE `entry` in (36344, 35810);
DELETE FROM `creature_addon` WHERE guid in (SELECT guid FROM creature where id in (36344, 35810));
INSERT INTO `creature_addon` (`guid`, `bytes2`, auras) SELECT guid, 1, '29266' FROM creature where id in (36344, 35810);

DELETE FROM `gameobject` WHERE `id` = 195488 AND `zoneId` = 4720;
DELETE FROM `gameobject` WHERE `id` = 195622;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(195622, 648, 1, 3, 645.788, 3006.57, -13.3067, 0.558504, 0, 0, 0, 1, 120, 255, 1),
(195622, 648, 1, 3, 588.82, 2966.69, -2.35813, 2.32129, 0, 0, 0, 1, 120, 255, 1),
(195622, 648, 1, 3, 577.785, 2904.27, -6.97185, 5.41052, 0, 0, 0, 1, 120, 255, 1),
(195622, 648, 1, 3, 601.269, 2889.74, -6.27649, 3.927, 0, 0, 0, 1, 120, 255, 1),
(195622, 648, 1, 3, 607.663, 2855.47, -7.23667, 2.53072, 0, 0, 0, 1, 120, 255, 1),
(195622, 648, 1, 3, 668.467, 2949.86, -0.032897, 0.523598, 0, 0, 0, 1, 120, 255, 1);

UPDATE `quest_template` SET `PrevQuestId` = '14248' WHERE `Id` in (14031, 14021);
DELETE FROM creature_involvedrelation WHERE quest = 14031 AND id != 35769;
DELETE FROM creature_questrelation WHERE quest = 14031  AND id != 35769;

DELETE FROM `creature_text` WHERE entry = 35769;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35769, 0, 0, 'От каджа''мита эти обезьяны поумнели! Постарайся защитить этого шахтера, $N.', 12, 0, 100, 273, 0, 0, 'Штейгер Промоках'),
(35769, 1, 0, 'Я объявляю этот рудник собственностью картеля Трюмных Вод!', 12, 0, 100, 4, 0, 0, 'Штейгер Промоках');

UPDATE `creature_template` SET `ScriptName` = 'npc_foreman_dampwick', `gossip_menu_id` = '10677' WHERE `entry` = 35769;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10677;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(10677, 1, 0, 'Э-э, Промоках, мне нужен еще один шахтер...', 1, 2, 0, 0, 0, 0, ''),
(10677, 0, 0, 'Расскажи мне еще раз про каджа''мит.', 1, 2, 0, 0, 0, 0, '');

UPDATE `creature_template` SET `minlevel` = '6', `maxlevel` = '6', `faction_A` = '35', `faction_H` = '35', `unit_flags` = '33554440', `flags_extra` = '2' WHERE `entry` = 35814;
DELETE FROM `creature_template_addon` WHERE entry = 35814;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('35814', '0', '0', '0', '0', '0', '68065');

UPDATE `creature_template` SET `KillCredit1` = '35816', `minlevel` = '6', `maxlevel` = '6', `faction_A` = '2204', `faction_H` = '2204', `unit_flags` = '32776', `ScriptName` = 'npc_frightened_miner' WHERE `entry` = 35813;
DELETE FROM `creature_text` WHERE entry = 35813;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35813, 0, 0, 'Ладно, идем. Ты же прикроешь меня, да?', 12, 0, 100, 396, 0, 0, 'Испуганный шахтер'),
(35813, 1, 0, 'Эй! Что это за наскальные рисунки! Ай! Что это за звуки? Это обезьяны?', 12, 0, 100, 396, 0, 0, 'Испуганный шахтер'),
(35813, 2, 0, 'Эта жила уже выработана.', 12, 0, 100, 396, 0, 0, 'Испуганный шахтер'),
(35813, 3, 0, 'Эй! Почему работаю только я один?', 12, 0, 100, 396, 0, 0, 'Испуганный шахтер'),
(35813, 4, 0, 'Я рассказывал тебе, что на Кезане служил в компании счетоводом среднего звена? Я работал на тебя много лет, а ты хоть имя мое знаешь?', 12, 0, 100, 396, 0, 0, 'Испуганный шахтер'),
(35813, 5, 0, 'Этого достаточно. Теперь я сам выберусь на поверхность. Спасибо, $N.', 12, 0, 100, 396, 0, 0, 'Испуганный шахтер');

SET @id = 0;
DELETE FROM `script_waypoint` WHERE `entry` = 35813;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(35813, @id := @id+ 1, 492.4184, 2976.321, 8.040207, 5000, NULL),
(35813, @id := @id+ 1, 506.8004, 2976.932, 7.138058, 5000, NULL),
(35813, @id := @id+ 1, 507.1741, 2974.924, 8.405232, 0, NULL),
(35813, @id := @id+ 1, 516.9028, 2973.127, 8.410025, 0, NULL),
(35813, @id := @id+ 1, 528.6945, 2961.117, 6.836154, 0, NULL),
(35813, @id := @id+ 1, 538.8212, 2951.87, 4.82069, 0, NULL),
(35813, @id := @id+ 1, 548.1198, 2943.126, 2.182257, 0, NULL),
(35813, @id := @id+ 1, 572.2361, 2944.425, -0.4270274, 2000, NULL),
(35813, @id := @id+ 1, 584.1675, 2958.499, -1.936844, 0, NULL),
(35813, @id := @id+ 1, 588.5505, 2962.911, -3.184606, 0, NULL),
(35813, @id := @id+ 1, 592.0505, 2957.161, -4.434606, 0, NULL),
(35813, @id := @id+ 1, 589.2186, 2939.589, -7.464939, 0, NULL),
(35813, @id := @id+ 1, 583.6559, 2928.126, -7.024014, 0, NULL),
(35813, @id := @id+ 1, 577.9059, 2910.876, -7.524014, 0, NULL),
(35813, @id := @id+ 1, 574.467, 2890.151, -7.921604, 0, NULL),
(35813, @id := @id+ 1, 592.1823, 2876.141, -6.806148, 0, NULL),
(35813, @id := @id+ 1, 607.6823, 2857.406, -7.147975, 0, NULL),
(35813, @id := @id+ 1, 608.9818, 2861.15, -7.115796, 0, NULL),
(35813, @id := @id+ 1, 628.2778, 2911.825, -1.997341, 0, NULL),
(35813, @id := @id+ 1, 640.7576, 2921.84, -1.023298, 0, NULL),
(35813, @id := @id+ 1, 658.5018, 2936.432, 0.1191088, 0, NULL),
(35813, @id := @id+ 1, 666.1684, 2947.392, -0.06006161, 15000, NULL),
(35813, @id := @id+ 1, 665.3238, 2946.608, -0.346116, 0, NULL),
(35813, @id := @id+ 1, 653.9792, 2934.824, 0.3678297, 0, NULL),
(35813, @id := @id+ 1, 645.9608, 2930.977, -0.8898152, 0, NULL),
(35813, @id := @id+ 1, 632.7639, 2920.276, -0.9334426, 0, NULL);

-- ----------------------------------------
-- Q: 14031 Spell 68280 PhaseAura 70661
-- ----------------------------------------

DELETE FROM `creature_involvedrelation` WHERE quest = 14031;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('35650', '14031');

DELETE FROM spell_area WHERE spell in(70661, 70678, 70680, 70681) AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('70661', '4720', '14031', '0', '0', '0', '2', '1', '8', '0'),
('70678', '4720', '14031', '0', '0', '0', '2', '1', '8', '0'),
('70680', '4720', '14031', '0', '0', '0', '2', '1', '8', '0'),
('70681', '4720', '14031', '0', '0', '0', '2', '1', '8', '0');

UPDATE `creature_template` SET `InhabitType` = '4', `flags_extra` = '128' WHERE `entry` in (37872, 37895, 37896, 37897);

DELETE FROM `creature` WHERE `id` in (37872, 37895, 37896, 37897);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(37895, 648, 1, 2, 0, 0, 570.646, 2908.03, 4.51759, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(37872, 648, 1, 2, 0, 0, 566.854, 2947.43, 2.96716, 5.61996, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(37897, 648, 1, 2, 0, 0, 650.604, 2966.22, 3.32871, 0.558505, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(37896, 648, 1, 2, 0, 0, 616.08, 2849.9, -4.64756, 1.58825, 120, 0, 0, 1, 0, 0, 0, 0, 0);

-- Cast 68280 on specific targets
DELETE FROM `conditions` WHERE SourceEntry = 68280;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 68280, 0, 0, 31, 0, 3, 37895, 0, 0, 0, '', 'Cast - Only - 37895'),
(13, 1, 68280, 0, 1, 31, 0, 3, 37872, 0, 0, 0, '', 'Cast - Only - 37872'),
(13, 1, 68280, 0, 2, 31, 0, 3, 37897, 0, 0, 0, '', 'Cast - Only - 37897'),
(13, 1, 68280, 0, 3, 31, 0, 3, 37896, 0, 0, 0, '', 'Cast - Only - 37896');

DELETE FROM `conditions` WHERE SourceEntry = 68296;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 68296, 0, 0, 31, 0, 3, 37895, 0, 0, 0, '', 'Cast - Only - 37895'),
(13, 1, 68296, 0, 1, 31, 0, 3, 37872, 0, 0, 0, '', 'Cast - Only - 37872'),
(13, 1, 68296, 0, 2, 31, 0, 3, 37897, 0, 0, 0, '', 'Cast - Only - 37897'),
(13, 1, 68296, 0, 3, 31, 0, 3, 37896, 0, 0, 0, '', 'Cast - Only - 37896');

DELETE FROM `conditions` WHERE SourceEntry = 70641;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 70641, 0, 0, 31, 0, 3, 37895, 0, 0, 0, '', 'Cast - Only - 37895'),
(13, 1, 70641, 0, 1, 31, 0, 3, 37872, 0, 0, 0, '', 'Cast - Only - 37872'),
(13, 1, 70641, 0, 2, 31, 0, 3, 37897, 0, 0, 0, '', 'Cast - Only - 37897'),
(13, 1, 70641, 0, 3, 31, 0, 3, 37896, 0, 0, 0, '', 'Cast - Only - 37896');

DELETE FROM `conditions` WHERE SourceEntry = 68281;

-- Creature on hit 68280 cast 68279 on player
DELETE FROM `spell_scripts` WHERE id = 68280;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('68280', '0', '0', '15', '68279', '3', '0', '0', '0', '0', '0');


-- on hit 68279 add aura  70649 on player
-- and cast 70641 on creature target witch add this aura - bind sight
-- and start channel 68281 on target witch add this aura
DELETE FROM `spell_script_names` WHERE spell_id = 68279;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('68279', 'spell_photo_capturing');

-- quest credit and clean aura state.
DELETE FROM `spell_script_names` WHERE spell_id = 68296;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('68296', 'spell_ctu_snap_effect');

-- ----------------------------------------
-- Q: 14233  Orcs Can Write?
-- ----------------------------------------

UPDATE `quest_template` SET `PrevQuestId` = '0' WHERE `Id` = 14233;
DELETE FROM `creature_questrelation` WHERE `quest` = 14233 AND id != 35837;
DELETE FROM `creature` WHERE id = 35837;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES
(35837, 648, 4720, 4778, 1, 15, 0, 0, 650.264, 2975.21, 3.04716, 2.38661, 300, 0, 0, 137, 0, 0, 0, 0, 0, 0);

-- ----------------------------------------
-- Q: 14235 The Vicious Vale
-- ----------------------------------------

DELETE FROM `creature_text` WHERE entry = 35875;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35875, 0, 0, 'Килаг Жутеклык должен быть где-то на этой тропе, ведущей на запад, гоблин.', 12, 0, 100, 1, 0, 0, 'Аггра'),
(35875, 1, 0, 'Возвращайся через долину и найди Килага в Лесном наблюдательном пункте.', 12, 0, 100, 1, 0, 0, 'Аггра');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=35875;
DELETE FROM smart_scripts WHERE entryorguid = 35875;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35875, 0, 0, 0, 47, 0, 100, 0, 14235, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14235'),
(35875, 0, 1, 0, 47, 0, 100, 0, 14237, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14237');

-- ----------------------------------------
-- Q: 14236 The Vicious Vale
-- Q: 14236 Weed Whacker
-- ----------------------------------------

UPDATE `creature` set phaseMask = 10 WHERE `id` = 35894;
UPDATE creature_template SET `AIName`='SmartAI' WHERE entry in (35897, 35896, 35893);
UPDATE `creature_template` SET `ScriptName` = 'npc_strangle_vine' WHERE `entry` = 35995;
UPDATE creature_template SET `spell1` = '15620', `AIName` = '', `ScriptName` = 'npc_orc_scout' WHERE entry = 35894;

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 36042;
UPDATE `creature_model_info` SET `combat_reach` = '2.5' WHERE `modelid` in (29951, 29952);
UPDATE `creature_model_info` SET `combat_reach` = '0.5' WHERE `modelid` in (29999, 30123, 30043, 30127, 30129, 30138, 30140, 30135);

DELETE FROM smart_scripts WHERE entryorguid in (35897, 35896, 35995, 36042, 35893, 35894);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35897, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'disable move'),
(35897, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'disable auto-attack'),
(35897, 0, 2, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 11, 68209, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'cast 68209'),
(35897, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'deffensiv state'),
(35896, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'disable move'),
(35896, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'disable auto-attack'),
(35896, 0, 2, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 11, 68207, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'cast 68207'),
(35896, 0, 3, 0, 60, 0, 100, 0, 1000, 15000, 35000, 45000, 11, 68208, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'cast 68208'),
(35896, 0, 4, 0, 25, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'deffensiv state'),
(35893, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'disable move'),
(35893, 0, 1, 0, 47, 0, 100, 0, 14236, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14236'),
(35893, 0, 2, 0, 47, 0, 100, 0, 14303, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14303');

DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 35995;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES ('35995', '46598', '1', '0');

DELETE FROM `vehicle_template_accessory` WHERE EntryOrAura = 35995;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(35995, 36042, 0, 0, 'captured orc', 8, 0);

DELETE FROM `creature_text` WHERE entry = 35893;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35893, 0, 0, 'Воспользуйся газонокосилкой, чтобы скосить эти растения!', 12, 0, 100, 0, 0, 0, 'Килаг Жутеклык'),
(35893, 1, 0, 'Отправляйся обратно к Аггре и скажи ей, что мы движемся на северо-запад.', 12, 0, 100, 0, 0, 4121, 'Килаг Жутеклык');

DELETE FROM `creature_text` WHERE entry = 36042;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36042, 0, 0, 'Тром-Ка, гоблин!', 12, 0, 100, 0, 0, 0, 'Орк-разведчик to Удушающая лиана'),
(36042, 0, 1, 'Я обязан тебе жизнью.', 12, 0, 100, 0, 0, 0, 'Орк-разведчик to Удушающая лиана'),
(36042, 0, 2, 'У меня сломаны ребра.', 12, 0, 100, 0, 0, 0, 'Орк-разведчик to Удушающая лиана'),
(36042, 0, 3, "Ака'магош, Гоблин!", 12, 0, 100, 0, 0, 0, 'Орк-разведчик to Удушающая лиана');

-- spell: 68211 Weed Whacker 
UPDATE `creature_template` SET `faction_A` = '2204', `faction_H` = '2204', `unit_flags` = '33555208', `VehicleId` = '0' WHERE `entry` = 35903;
DELETE FROM `spell_script_names` WHERE `spell_id` = 68211;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('68211', 'spell_weed_whacker');

DELETE FROM spell_area WHERE spell in (68212, 68824) AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('68212', '4720', '14236', '0', '0', '0', '2', '0', '8', '0'),
('68824', '4720', '14236', '0', '0', '0', '2', '0', '8', '0');

DELETE FROM `creature` WHERE `id` = 35893;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES
(35893, 648, 4720, 4780, 1, 2, 0, 35893, 602.473, 2781.14, 88.8978, 1.19422, 300, 0, 0, 264, 0, 0, 0, 2048, 0, 0);

-- spawn flowers
DELETE FROM `creature` WHERE `id` in (35897, 35896, 35995);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `zoneId`, `dynamicflags`) VALUES
(35897, 648, 1, 2, 0, 0, 617.51, 2778.53, 89.4045, 2.72271, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 605.055, 2797.71, 88.1306, 4.46804, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 734.54, 2901.11, 89.3918, 3.94444, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 725.99, 2897.27, 88.7679, 3.94444, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 708.889, 2905.75, 88.7316, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 710.707, 2901.17, 89.9951, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 709.255, 2896.49, 89.8552, 4.64258, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 697.443, 2899.55, 90.6525, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 691.55, 2898.81, 91.0435, 4.4855, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 702.377, 2884, 86.6283, 3.94444, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 691.438, 2886.28, 86.4597, 4.39823, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 730.153, 2848.16, 86.404, 3.71755, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 697.08, 2878.25, 86.4667, 5.88176, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 721.995, 2846.16, 86.0167, 2.94961, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 704.83, 2867.79, 86.4929, 2.30383, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 676.531, 2885.18, 86.534, 5.58505, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 706.346, 2861.54, 86.5726, 2.53073, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 716.87, 2848.89, 86.0565, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 706.639, 2855.31, 86.4173, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 714.339, 2836.51, 86.2683, 2.16421, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 683.38, 2865.62, 85.0608, 4.62512, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 689.677, 2851.98, 84.8808, 1.76278, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 694.599, 2841.56, 84.9882, 2.07694, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 690.917, 2844.19, 84.4848, 3.59538, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 665.047, 2864.71, 84.7656, 1.71042, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 676.906, 2851.96, 84.6337, 3.85718, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 695.269, 2822.27, 86.7083, 6.10865, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 671.802, 2856.2, 84.5753, 0.733038, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 680.964, 2842.15, 84.4281, 4.03171, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 664.516, 2858.2, 85.2548, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 690.743, 2825.75, 86.3148, 1.51844, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 683.221, 2834.72, 85.4501, 3.28122, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 686.087, 2829.94, 86.022, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 685.802, 2823.29, 86.5251, 2.1293, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 668.45, 2845.08, 85.0578, 4.88692, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 662.392, 2847.23, 86.05, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 679.969, 2817.55, 86.5433, 6.10865, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 657.009, 2827.65, 84.7245, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 655.347, 2812.39, 85.0226, 4.41568, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 652.273, 2821.18, 85.1368, 3.9968, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 656.564, 2799.62, 87.1676, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 650.672, 2803.63, 85.9124, 2.30383, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 648.877, 2799.6, 86.6, 2.53073, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 644.401, 2780.16, 88.8423, 1.16937, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 643.592, 2799.56, 86.0348, 2.98451, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 638.25, 2799, 85.5399, 1.71042, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 632.729, 2809.16, 86.2285, 0.733038, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 637.102, 2768.71, 90.3314, 1.55334, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 593.84, 2855.28, 96.3692, 2.9147, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 629.76, 2792.09, 86.4327, 4.2586, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 627.238, 2797.27, 86.0474, 1.78024, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 615.137, 2820, 92.2465, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 626.144, 2782.32, 87.9045, 1.8326, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 621.214, 2797.27, 86.7222, 2.26893, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 621.715, 2774.06, 89.6007, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 607.658, 2813.78, 91.4896, 4.83456, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 594.873, 2823.46, 89.9607, 3.28122, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 592.141, 2798.15, 89.2812, 5.95157, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 585.066, 2794.32, 89.8524, 5.14872, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 579.396, 2815.66, 85.4957, 3.66519, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 577.148, 2808.19, 85.7133, 4.86947, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 598.637, 2866.21, 97.0507, 1.71042, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 607.365, 2881.34, 95.0249, 1.76278, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 665.446, 2871.32, 85.4722, 3.19395, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 666.045, 2883.33, 86.3924, 4.17134, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 708.491, 2921.47, 83.7974, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 650.007, 2953.95, 95.9285, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 647.205, 2957.73, 95.2142, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 699.342, 2921.82, 85.5637, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 633.856, 2954.11, 93.6596, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 637.462, 2948.33, 95.0278, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 624.599, 2941.73, 94.3348, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 639.695, 2932.15, 96.3559, 2.86234, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 628.198, 2937.42, 95.0779, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 632.267, 2923.8, 96.1541, 2.09439, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 635.333, 2930.04, 95.8273, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 656.873, 2915.94, 91.9799, 4.27606, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 612.464, 2919.67, 93.2602, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 598.42, 2897, 91.688, 2.09439, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 616.991, 2909.15, 91.2225, 1.0821, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 643.255, 2909.07, 87.2731, 2.53073, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 620.387, 2884.37, 94.5655, 2.53073, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 659.325, 2864.63, 85.4057, 2.26893, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 601.316, 2893.47, 91.3978, 0.541052, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 638.851, 2901.52, 87.3177, 0.418879, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 626.786, 2878.93, 93.3335, 0.645772, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 617.668, 2898, 90.0955, 2.86234, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 612.51, 2892.57, 91.2394, 1.8326, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 632.635, 2894.04, 88.1076, 1.71042, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 629.486, 2889.41, 88.8192, 2.05949, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 645.538, 2845.86, 87.3339, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 648.503, 2860.2, 87.1316, 2.86234, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 652.585, 2875.68, 85.7361, 4.88692, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 646.304, 2868.83, 87.1424, 4.92183, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 580.799, 2831.06, 85.5251, 3.35103, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 580.863, 2842.07, 87.3802, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 593.545, 2873.57, 92.1662, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 582.392, 2869.18, 86.2031, 2.86234, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 617.399, 2947.04, 96.6666, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 605.632, 2914.42, 92.1733, 1.39626, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 591.007, 2896.43, 91.6997, 2.86234, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 609.352, 2956.9, 99.6566, 0.0174533, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 582.811, 2895.72, 91.6247, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 573.243, 2898.71, 91.586, 2.09439, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 595.3, 2924.01, 91.6616, 2.21657, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 576.663, 2906.12, 92.808, 2.86234, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 597.649, 2935.3, 92.26, 3.31613, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 568.958, 2898.6, 91.1302, 4.34587, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 574.014, 2917.69, 92.6789, 1.0821, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 570.951, 2904.96, 92.0445, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 560.68, 2912.35, 91.8414, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 568.201, 2930.09, 91.52, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 565.01, 2919.6, 92.8201, 1.18682, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 562.358, 2937.29, 93.5375, 2.86234, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 552.898, 2936.92, 92.9609, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(35897, 648, 1, 2, 0, 0, 560.983, 2929.99, 92.7134, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(35896, 648, 1, 2, 596.589, 2796.66, 89.2672, 5.11381, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 612.089, 2791.25, 87.4725, 3.78736, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 612.479, 2771.83, 91.842, 2.30383, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 608.401, 2793.6, 87.9246, 4.20624, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 614.764, 2775.95, 90.4501, 2.49582, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 615.104, 2786.55, 87.4207, 3.14159, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 616.964, 2782.34, 88.3424, 2.98451, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 600.391, 2798.57, 89.5762, 4.81711, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 711.309, 2914.81, 82.9827, 4.29351, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 720.531, 2903.57, 90.2547, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 715.785, 2904.57, 90.1719, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 698.804, 2911.76, 87.7711, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 702.861, 2908.69, 87.8941, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 694.495, 2909.94, 89.5092, 5.67232, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 720.946, 2895.15, 88.6085, 4.29351, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 715.326, 2895.38, 89.0529, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 700.387, 2903.55, 89.6601, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 704.141, 2898.59, 90.0192, 4.34587, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 686.167, 2898.73, 92.0789, 4.76475, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 675.035, 2898.41, 92.397, 4.03171, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 697.63, 2884.99, 86.4849, 4.74729, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 682.134, 2889.14, 88.6923, 5.07891, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 726.88, 2841.81, 86.2853, 2.84489, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 674.5, 2894.33, 91.8986, 4.5204, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 686.342, 2883.04, 86.5047, 0.122173, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 684.939, 2878.6, 86.4871, 3.94444, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 696.422, 2870.04, 85.6986, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 721.024, 2839.66, 86.1897, 2.58309, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 672.549, 2881.66, 86.5, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 678.337, 2879.03, 86.452, 3.59538, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 686.573, 2872.65, 85.9519, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 715.186, 2843.78, 85.4821, 1.48353, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 689.703, 2869.42, 85.3885, 4.81711, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 710.019, 2850.54, 86.2797, 3.75246, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 698.557, 2862.17, 85.9732, 2.53073, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 701.408, 2856.57, 85.9734, 3.54302, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 710.231, 2843.81, 85.1292, 2.72271, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 703.648, 2849.77, 85.492, 2.58309, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 696.057, 2856.5, 85.5275, 3.59538, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 692.37, 2859.38, 85.3096, 2.53073, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 703.564, 2844.35, 84.7993, 2.51327, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 708.889, 2838.72, 85.6385, 2.58309, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 708.292, 2831.82, 86.2577, 3.01942, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 701.059, 2829.58, 85.9331, 1.76278, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 695.816, 2847.6, 84.6845, 6.10865, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 675.304, 2874.31, 86.2587, 4.34587, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 677.316, 2866.55, 85.2319, 4.10152, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 683.566, 2857.83, 84.5797, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 696.203, 2836.52, 85.5346, 2.58309, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 671.042, 2870.16, 85.7415, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 683.158, 2849.56, 84.3313, 2.1293, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 696.57, 2827.19, 86.1528, 4.46804, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 690.599, 2835.25, 85.6552, 4.01426, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 692.519, 2830.05, 85.9615, 2.58309, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 687.175, 2839.19, 85.1138, 3.12414, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 676.906, 2851.96, 84.6337, 3.85718, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 671.802, 2856.2, 84.5753, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 692.403, 2816.77, 88.2959, 2.18166, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 621.759, 2875.1, 95.6138, 0.0872665, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 673.708, 2845.35, 84.9063, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 666.076, 2852.12, 85.3906, 3.9968, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 626.971, 2870.85, 96.7914, 0.279253, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 659.418, 2854.36, 86.2464, 3.9968, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 675.613, 2837.57, 84.8257, 6.10865, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 679.564, 2826.75, 86.1934, 1.97222, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 685.731, 2810.97, 86.9978, 1.41372, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 674.465, 2821.88, 85.4771, 1.58825, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 668.601, 2826.93, 84.8069, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 670.807, 2819.3, 85.1195, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 670.201, 2834.13, 84.8839, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 666.215, 2813.61, 85.5861, 2.42601, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 655.865, 2840.73, 86.3755, 2.07694, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 665.677, 2839.45, 85.457, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 661.507, 2834.06, 85.3803, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 663.394, 2818.74, 84.9264, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 658.054, 2818.13, 84.9323, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 660.908, 2823.92, 85.0234, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 654.455, 2834.74, 85.7587, 4.01426, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 665.964, 2808.71, 86.4732, 2.53073, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 660.993, 2807.88, 86.3132, 1.8326, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 662.764, 2802.1, 87.2841, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 656.618, 2804.47, 86.4222, 2.53073, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 657.71, 2795.77, 87.6839, 2.23402, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 654.139, 2789.32, 88.3735, 2.1293, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 648.142, 2814.14, 84.8032, 1.20428, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 647.59, 2808.84, 84.9046, 4.83456, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 649.215, 2784.75, 88.5085, 2.49582, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 642.358, 2818.76, 86.1094, 1.46608, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 644.403, 2785.71, 88.0562, 3.47321, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 643.736, 2791.77, 87.3004, 5.84685, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 641.45, 2805.6, 85.1771, 3.78911, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 640.323, 2762.07, 92.9158, 2.00713, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 639.398, 2812.06, 85.5831, 2.26893, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 638.964, 2792.35, 86.7136, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 638.25, 2799, 85.5399, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 633.781, 2816.58, 86.9096, 4.92183, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 638.873, 2774.77, 89.541, 2.3911, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 622.321, 2825.01, 93.5349, 5.60251, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 627.773, 2815, 87.4316, 5.41052, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 634.014, 2794.53, 86.0682, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 632.104, 2801.37, 85.4965, 4.88692, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 628.063, 2805.42, 86.6892, 3.9968, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 632.99, 2777.01, 89.2145, 1.39626, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 617.13, 2826.35, 93.9497, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 625.229, 2810.44, 87.3421, 5.49779, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 629.115, 2786.35, 87.378, 3.28122, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 612.384, 2827.35, 94.0642, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 596.543, 2844.75, 95.9187, 3.78736, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 628.21, 2772.3, 89.5108, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 588.177, 2850.59, 94.0264, 3.33358, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 621.245, 2805.54, 88.4768, 4.36332, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 626.174, 2777.39, 88.8893, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 609.439, 2823.34, 92.8524, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 613.172, 2814.2, 91.617, 5.5676, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 621.507, 2786.73, 87.0606, 4.15388, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 614.93, 2801.66, 87.6721, 5.39307, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 589.408, 2839.52, 90.8243, 2.51327, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 616.786, 2793.18, 87.0972, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 603.247, 2822.83, 91.7648, 5.18363, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 590.082, 2834.06, 89.9846, 3.00197, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 600.028, 2819.03, 91.3428, 4.34587, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 610.34, 2797.64, 87.7585, 4.92183, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 604.509, 2807.72, 90.7919, 4.66003, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 593.656, 2817.98, 88.9684, 4.29351, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 595.253, 2811.25, 89.3382, 4.4855, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 596.71, 2803.59, 89.8395, 4.41568, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 589.503, 2805.33, 88.1444, 5.34071, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 587.142, 2812.65, 86.9843, 3.89208, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 578.333, 2824.36, 83.9135, 3.03687, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 584.134, 2803.88, 86.868, 5.13127, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 579.858, 2798.55, 87.8419, 5.09636, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 572.29, 2802.56, 85.7058, 2.53073, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 597.42, 2861.71, 97.467, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 592.455, 2864.5, 95.5664, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 649.943, 2829.42, 85.5444, 2.58309, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 632.464, 2822.44, 87.5341, 5.32325, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 638.276, 2825.69, 87.3495, 4.60767, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 583.564, 2833.71, 87.1221, 4.41568, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 593.828, 2891.3, 91.1983, 2.42601, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 669.604, 2877.66, 86.2918, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 644.908, 2951.74, 95.6416, 2.58309, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 640.154, 2956.3, 94.6246, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 703.745, 2922.47, 84.9236, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 645.804, 2946.09, 95.5412, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 652.078, 2945.79, 94.527, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 627.292, 2953.85, 92.7616, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 642.67, 2927.04, 98.0648, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 648.363, 2923.28, 97.5123, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 623.726, 2948.59, 93.8547, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 632.292, 2944.74, 94.7788, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 639.948, 2943.15, 95.0163, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 663.571, 2926.98, 92.805, 3.94444, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 647.108, 2932.71, 95.6771, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 647.401, 2938.91, 94.2708, 5.14872, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 625.313, 2932.43, 95.2222, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 630.061, 2931.43, 95.7174, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 657.764, 2925.44, 93.5756, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 622.368, 2928.43, 94.996, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 654.814, 2939.47, 92.5754, 0.0349066, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 634.498, 2937.11, 94.8879, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 654.896, 2931.61, 93.5057, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 624.854, 2923.24, 94.4811, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 654.061, 2919.94, 92.8438, 4.34587, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 666.029, 2889.09, 86.4813, 5.09636, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 618.93, 2916.25, 92.5811, 1.58825, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 605.497, 2906.84, 91.1242, 5.02655, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 612.071, 2912.7, 92.2274, 2.42601, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 663.712, 2877.38, 85.8351, 3.85718, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 618.231, 2878.27, 95.0185, 1.3439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 651.885, 2899.95, 86.5125, 4.18879, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 659.436, 2883.54, 85.9864, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 635.863, 2907.01, 87.6207, 4.29351, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 652.458, 2894.41, 86.4551, 5.21853, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 645.882, 2900.54, 86.807, 5.0091, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 622.875, 2906.19, 89.1615, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 613.344, 2902.73, 90.3619, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 606.547, 2898.44, 91.0752, 1.58825, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 614.507, 2883.21, 93.9927, 1.27409, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 630.729, 2904.88, 87.9826, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 657.75, 2870.82, 85.4247, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 653.352, 2886.62, 85.8121, 3.19395, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 630.865, 2899.82, 88.0139, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 640.031, 2895.97, 87.2421, 3.19395, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 646, 2891.61, 86.2742, 0.733038, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 626.49, 2896.41, 88.8663, 4.88692, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 621.826, 2892.75, 89.8468, 0.139626, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 639.979, 2889.51, 87.1493, 3.9968, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 647.611, 2882.74, 85.9028, 1.71042, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 634.818, 2885.27, 88.0387, 0.872665, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 654.759, 2848.35, 86.6545, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 651.967, 2866.07, 86.7152, 4.92183, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 654.898, 2860.53, 86.4479, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 642.523, 2862.39, 87.6362, 6.17846, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 647.83, 2839.31, 86.9996, 3.12414, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 651.547, 2854.26, 86.7648, 4.03171, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 644.958, 2853.09, 87.4658, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 639.7, 2830.39, 87.4054, 5.61996, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 639.825, 2880.97, 87.0748, 0.122173, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 643.757, 2875.86, 86.5877, 3.9968, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 641.314, 2836.22, 87.3438, 4.03171, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 575.305, 2837.6, 85.6119, 3.03687, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 576.418, 2854.79, 85.2668, 2.46091, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 574.481, 2847.05, 85.5442, 3.14159, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 577.922, 2875.09, 86.9606, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 585.017, 2888.09, 90.2622, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 578.906, 2882.43, 88.8311, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 615.167, 2933.27, 94.0617, 3.36848, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 618.967, 2956.32, 94.5669, 4.74729, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 613.255, 2954.14, 98.0663, 0.523599, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 609.708, 2927.02, 93.5758, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 606.469, 2920.67, 92.6871, 5.044, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 571.84, 2880.55, 88.9445, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 596.214, 2904.63, 91.9458, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 577.604, 2887.53, 90.2127, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 597.939, 2911.41, 91.7118, 3.10669, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 588.521, 2901.62, 92.1736, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 604.116, 2930.47, 93.2198, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 597.507, 2916.38, 92.1064, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 601.736, 2923.94, 92.0463, 5.044, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 591.075, 2908.85, 92.3549, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 575.118, 2892.71, 90.993, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 578.063, 2896.71, 91.6784, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 569.555, 2889.7, 90.3202, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 584.076, 2906.68, 92.7856, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 590.094, 2915.82, 92.953, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 591.891, 2921.72, 92.2834, 1.88496, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 596.703, 2929.9, 91.8084, 2.79253, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 581.87, 2914.31, 92.9953, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 587.608, 2921, 92.4041, 1.5708, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 581.851, 2921.02, 92.2082, 1.13446, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 571.146, 2934.09, 91.6364, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 574.177, 2911.3, 92.9892, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 576.257, 2930.71, 90.7453, 0.0349066, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 567.217, 2911.97, 92.6316, 2.09439, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 578.101, 2925.47, 91.2366, 0.645772, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 570.903, 2921.61, 92.4308, 2.86234, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 566.203, 2905.95, 91.3124, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 568.849, 2939.64, 93.3584, 4.34587, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 558.2, 2942.71, 93.4396, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 562.816, 2946.48, 94.0791, 1.0821, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 567.564, 2945.48, 94.0026, 1.18682, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 558.816, 2920.2, 92.6555, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 553.18, 2914.77, 90.8636, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35896, 648, 1, 2, 551.293, 2921.93, 91.8499, 3.52556, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 718.096, 2899.77, 89.7968, 4.57276, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 690.904, 2879.62, 86.5078, 5.13127, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 699.559, 2843.72, 84.9045, 1.20428, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 670.868, 2861.58, 84.4856, 5.96903, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 674.882, 2828.02, 85.2862, 5.96903, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 647.856, 2793.13, 87.5803, 5.96903, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 622.743, 2814.23, 87.6273, 1.74533, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 621.688, 2792, 86.5645, 1.97222, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 598.092, 2814.71, 89.7731, 4.85202, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 646.372, 2825.85, 86.0599, 0.837758, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 703.462, 2915.89, 85.7082, 4.5204, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 645.068, 2948.5, 95.6578, 5.96903, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 617.366, 2923.2, 93.9921, 4.39823, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 655.214, 2923.84, 93.6575, 1.36136, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 657.406, 2891.69, 86.2919, 1.50098, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 619.033, 2880.96, 94.6522, 5.96903, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 642.615, 2857.31, 87.7384, 5.96903, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 578.269, 2845.36, 86.7932, 4.85202, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 580.786, 2901.66, 92.4352, 6.14356, 120, 0, 1, 0, 0, 0, 0, 0),
(35995, 648, 1, 2, 559.172, 2933.75, 93.3946, 5.39307, 120, 0, 1, 0, 0, 0, 0, 0);

-- --------------------------------
--          PHASE 4
-- --------------------------------
UPDATE `creature` SET phaseMask = phaseMask | 4 WHERE `id` in (35875, 35882, 36432, 36417, 36423, 36063, 36578, 35917, 36421, 36422, 35929, 36092, 36112, 36103, 36129, 36127);
UPDATE `creature` SET phaseMask = phaseMask | 4 WHERE map = 648 AND areaId = 4781 AND `phaseMask` &8 = 0;
UPDATE `gameobject` SET phaseMask = phaseMask | 4 WHERE `id` in (196881);

UPDATE `quest_template` SET `RewardSpell` = '0' WHERE `Id` = 14303;
DELETE FROM spell_area WHERE spell = 67852 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('67852', '4720', '14237', '14326', '0', '0', '2', '1', '74', '74');

-- ----------------------------------------
-- Q: 14238 Infrared = Infradead
-- ----------------------------------------

DELETE FROM spell_area WHERE spell in (69303, 68338) AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('69303', '4720', '14238', '0', '0', '0', '2', '0', '8', '0'),
('68338', '4720', '14238', '0', '0', '0', '2', '1', '8', '0');

UPDATE `creature_template_addon` SET `auras` = '68322 68327' WHERE `entry` = 36092;
DELETE FROM `creature_template_addon` WHERE entry = 36100;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('36100', '0', '0', '0', '0', '0', '77622 68327');

-- 68344 -> 68338 -> 68336
-- 68371 - 68337
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=35917;
DELETE FROM smart_scripts WHERE entryorguid = 35917;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35917, 0, 0, 0, 47, 0, 100, 0, 14238, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14238'),
(35917, 0, 1, 0, 47, 0, 100, 0, 14240, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14240');

DELETE FROM `creature_text` WHERE entry = 35917;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35917, 0, 0, 'Наденьте инфракрасные теплодетекторы!', 42, 0, 100, 0, 0, 0, 'Килаг Жутеклык'),
(35917, 1, 0, 'Садись на Бастию! Найди Бракса!', 12, 0, 100, 25, 0, 16458, 'Килаг Жутеклык');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36100;
DELETE FROM smart_scripts WHERE entryorguid = 36100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36100, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At spawn');
DELETE FROM `creature_text` WHERE entry = 36100;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36100, 0, 0, '$N, не забудь надеть очки. Тогда они нас врасплох не застанут.', 12, 0, 100, 1, 0, 0, 'Орк-разведчик');

-- ----------------------------------------
-- Q: 14240 To the Cliffs
-- ----------------------------------------

-- spell: 68974 npc: 36585 summon spell 68973
UPDATE `quest_template` SET `StartScript` = '14240' WHERE `quest_template`.`Id` = 14240;
DELETE FROM `quest_start_scripts` WHERE id = 14240;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14240', '0', '15', '68973', '2', '0', '0', '0', '0', '0');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36585;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES ('36585', '68974', '1', '0');

UPDATE `creature_template` SET `VehicleId` = '530', `minlevel` = '8', `maxlevel` = '8', `faction_A` = '2204', `faction_H` = '2204', `unit_flags` = '33288', `unit_flags2` = '67584', `ScriptName` = 'npc_bastia' WHERE `entry` = 36585;

SET @id = 0;
SET @entry = 36585;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(@entry, @id := @id+ 1, 866.792, 2843.53, 102.838, 0, NULL),
(@entry, @id := @id+ 1, 869.602, 2865.53, 101.059, 0, NULL),
(@entry, @id := @id+ 1, 878.995, 2872.6, 100.695, 0, NULL),
(@entry, @id := @id+ 1, 903.644, 2880.71, 100.018, 0, NULL),
(@entry, @id := @id+ 1, 919.332, 2904.62, 100.903, 0, NULL),
(@entry, @id := @id+ 1, 939.792, 2919.01, 105.368, 0, NULL),
(@entry, @id := @id+ 1, 947.203, 2941.62, 109.105, 0, NULL),
(@entry, @id := @id+ 1, 978.345, 2949.76, 109.816, 0, NULL),
(@entry, @id := @id+ 1, 1033.64, 2950.85, 109.956, 0, NULL),
(@entry, @id := @id+ 1, 1048.4, 2974.9, 112.374, 0, NULL),
(@entry, @id := @id+ 1, 1069.07, 2992.79, 116.149, 0, NULL),
(@entry, @id := @id+ 1, 1074.73, 3025.15, 121.704, 0, NULL),
(@entry, @id := @id+ 1, 1091.07, 3046.52, 123.542, 0, NULL),
(@entry, @id := @id+ 1, 1069.62, 3098.21, 125.306, 0, NULL),
(@entry, @id := @id+ 1, 1031.37, 3122.97, 124.963, 0, NULL),
(@entry, @id := @id+ 1, 1023.47, 3141.83, 123.785, 0, NULL),
(@entry, @id := @id+ 1, 1031.68, 3174.65, 118.965, 0, NULL),
(@entry, @id := @id+ 1, 1056.54, 3201.88, 111.593, 0, NULL),
(@entry, @id := @id+ 1, 1061.17, 3225.76, 96.3107, 0, NULL),
(@entry, @id := @id+ 1, 1078.86, 3237.86, 82.1458, 0, NULL);

-- ----------------------------------------
-- Q: 14241 Get to the Gyrochoppa!
-- ----------------------------------------

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36112;
DELETE FROM smart_scripts WHERE entryorguid = 36112;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36112, 0, 0, 0, 47, 0, 100, 0, 14241, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14241');

DELETE FROM `creature_text` WHERE entry = 36112;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36112, 0, 0, 'Беги к гиролету! Живо!', 14, 0, 100, 5, 0, 1343, 'Разведчик Бракс');

-- --------------------------------
--          PHASE 8
-- --------------------------------

UPDATE `creature` SET phaseMask = phaseMask | 8 WHERE `id` in (36423, 36063, 36578, 35917, 36421, 36422, 35929, 36092, 36112, 36103, 36129, 36127, 38432, 36179, 36615, 36521, 36520, 36467, 38738, 36501, 33280, 36428, 36518, 36524, 36523, 36469, 36468, 36519, 36426, 36525, 36463, 36513, 36425, 36417, 36418);
UPDATE `gameobject` SET phaseMask = phaseMask | 8 WHERE `id` in (196881, 196443 );
DELETE FROM spell_area WHERE spell = 67853 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('67853', '4720', '14241', '14326', '0', '0', '2', '1', '74', '74'), -- interrupt for 11 phase.
('67853', '4720', '14243', '14245', '0', '0', '2', '1', '66', '66'); -- could be splite at finish, but we on vehicle go out from it

-- ----------------------------------------
-- Q: 14242 Precious Cargo
-- ----------------------------------------
DELETE FROM creature WHERE id = 36149 AND GUID in (263276, 263277);
DELETE FROM gameobject WHERE id = 195707;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(195707, 648, 1, 8, 993.177, 3852.28, 2.81896, 2.70526, 0, 0, 0, 1, 120, 0, 1);

UPDATE `quest_template` SET `RewardSpell` = '0', `StartScript` = '14242' WHERE `Id` = 14242;

DELETE FROM `quest_start_scripts` WHERE id = 14242;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14242', '0', '15', '68386', '2', '0', '0', '0', '0', '0');

-- music: 16422 veh. 36143 0xF1508D2F00066EF7 by spell 68386

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36143;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES ('36143', '68387', '1', '0');

UPDATE `creature_template` SET `InhabitType` = '4', `minlevel` = '10', `maxlevel` = '10', `faction_A` = '35', `faction_H` = '35', `unit_flags` = '8', `VehicleId` = '505', `ScriptName` = 'npc_gyrochoppa' WHERE `entry` = 36143;

DELETE FROM `creature_text` WHERE entry = 36143;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36143, 0, 0, 'Найди \"Драгоценный груз\"!', 42, 0, 100, 0, 0, 0, 'Гиролет');

SET @id = 0;
SET @entry = 36143;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(@entry, @id := @id+ 1, 846.743, 3335.536, 10.14332, 0, NULL),
(@entry, @id := @id+ 1, 755.8854, 3374.22, 14.39331, 0, NULL),
(@entry, @id := @id+ 1, 780.3264, 3449.157, 14.39331, 0, NULL),
(@entry, @id := @id+ 1, 1071.618, 3589.423, 26.22275, 0, NULL),
(@entry, @id := @id+ 1, 1098.778, 3729.424, 93.02834, 0, NULL),
(@entry, @id := @id+ 1, 971.5139, 3802.339, 14.36161, 0, NULL);


-- --------------------------------
--          PHASE 11
-- --------------------------------
DELETE FROM spell_area WHERE spell = 68421 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('68421', '4720', '14326', '0', '0', '0', '2', '1', '74', '0');
-- ('68421', '4720', '14326', '14243', '0', '0', '2', '1', '74', '64');

DELETE FROM `spell_script_names` WHERE spell_id = 68421;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('68421', 'spell_mmut_phase_controller');

UPDATE `creature` SET phaseMask = 1024 WHERE `id` in (36161, 36188);

-- ----------------------------------------
-- Q: 14326 Meet Me Up Top
-- ----------------------------------------

-- trall cast 68440 68441

UPDATE `quest_template` SET `StartScript` = '14326' WHERE `Id` = 14326;
DELETE FROM `quest_start_scripts` WHERE id = 14326;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14326', '0', '15', '69079', '2', '0', '0', '0', '0', '0');

-- NPC: 36177,  GO: 196828, 196818, 196819, 196827, 
-- summon 69079 summon music 20140 phaser 68421
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36622;
DELETE FROM smart_scripts WHERE entryorguid = 36622;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36622, 0, 0, 0, 11, 0, 100, 0, 0, 0, 8000, 0, 1, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 'Say text at summon');
DELETE FROM `creature_text` WHERE entry = 36622;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36622, 0, 0, 'Увидимся. Еще раз спасибо за освобождение!', 12, 0, 100, 0, 0, 20140, 'Тралл');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36161;
DELETE FROM smart_scripts WHERE entryorguid = 36161;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36161, 0, 0, 0, 60, 0, 100, 0, 5000, 5000, 30000, 30000, 11, 68440, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 68440'),
(36161, 0, 1, 0, 60, 0, 100, 0, 15000, 15000, 30000, 30000, 11, 68441, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 68441'),
(36161, 0, 2, 0, 60, 0, 100, 0, 25000, 25000, 30000, 30000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'text ');

DELETE FROM `creature_text` WHERE entry = 36161;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36161, 0, 0, 'Сила моря, внемли моему зову!', 14, 0, 100, 0, 0, 20142, 'Тралл'),
(36161, 0, 1, 'Дети шторма, спуститесь на землю и сокрушите всех, кто захочет помешать мне спасти этот мир!', 14, 0, 100, 0, 0, 20146, 'Тралл');

-- at hit 68441 add aura 42345
DELETE FROM `spell_script_names` WHERE spell_id in (68441, 68440);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('68441', 'spell_trall_chain_lightning'),
('68440', 'spell_trall_chain_lightning');

DELETE FROM `conditions` WHERE SourceEntry in (68441, 68440);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 68441, 0, 0, 31, 0, 3, 36177, 0, 0, 0, '', 'Cast - Only - 36177'),
(13, 1, 68440, 0, 0, 31, 0, 3, 36177, 0, 0, 0, '', 'Cast - Only - 36177');

UPDATE `creature_template` SET `InhabitType` = '4', `flags_extra` = '128' WHERE `entry` = 36177;

DELETE FROM creature WHERE id = 36177;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
( 36177, 648, 1, 1024, 0, 0, 982.543, 3831.68, 16.2098, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 990.361, 3827.46, 16.3493, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 969.347, 3855.34, 19.5089, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1009.86, 3826.5, 15.9927, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1014.42, 3820.85, -1.3734, 5.74213, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 957.816, 3871.21, 16.7336, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1030.05, 3825.86, 13.8738, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1031.45, 3877.45, -0.493885, 4.95674, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 966.689, 3892.89, -0.889676, 2.72271, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 949.774, 3873.99, 15.4051, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1047.04, 3840.09, 8.92073, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 944.695, 3887.41, 16.2884, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1047.46, 3823.79, 25.8481, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1057.5, 3842.38, 16.442, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1058.63, 3838.16, 24.9713, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1056.87, 3835.55, 31.469, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1047.06, 3804.63, 14.3963, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 938.128, 3894.71, 17.422, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1018.46, 3781.31, -1.52524, 0.488692, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 926.76, 3885.06, 14.959, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 938.495, 3903.62, 18.4363, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1059.24, 3820.77, 31.16, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 947.93, 3913.58, 10.992, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 912.925, 3841.58, -0.948623, 2.00713, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 937.151, 3912.57, 14.1645, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 909.398, 3862.57, 6.48174, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 921.188, 3892.87, 26.3799, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1055.92, 3793.16, 20.8459, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 944.476, 3921.79, 20.789, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 943.318, 3916.8, 33.7804, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 921.795, 3893.83, 33.7341, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1057.45, 3809.52, 48.9266, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 933.891, 3909.92, 34.8312, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1071.5, 3805.16, 2.47999, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1067.67, 3808.13, 34.5026, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1048.04, 3776.12, 5.31391, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 935.571, 3910.62, 44.0395, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 929.276, 3917.18, 11.5891, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 921.106, 3895.33, 41.4411, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 906.384, 3876.07, 26.9863, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 922.823, 3895.68, 51.4509, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 914.828, 3900.27, 31.3135, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1060.76, 3787.62, 37.8424, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 897.172, 3872.11, 18.2587, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 901.559, 3876.78, 32.1127, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1083.23, 3809.43, 11.8348, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1060.19, 3781.72, 31.8958, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1062.69, 3776.37, 18.0102, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 893.175, 3879.9, 7.05079, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 902.837, 3907, 3.43669, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1068.08, 3773.4, 14.6765, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 880.87, 3847.28, 8.17899, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 1062.91, 3750.1, 7.27157, 2.14675, 120, 0, 0, 1, 0, 0, 0, 0, 0),
( 36177, 648, 1, 1024, 0, 0, 878.984, 3800.55, -0.992045, 2.02458, 120, 0, 0, 1, 0, 0, 0, 0, 0);

DELETE FROM gameobject where id in (196828, 196827, 196819, 196818, 196824, 196822, 196397,196396  );
INSERT INTO `gameobject` ( `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
( 196828, 648, 1, 1024, 1100.05, 3834.49, -0.706536, 3.92699, 0, 0, 0, 1, 120, 255, 1),
( 196827, 648, 1, 1024, 1097.85, 3779.34, -0.701713, 2.2602, 0, 0, 0, 1, 120, 255, 1),
( 196819, 648, 1, 1024, 898.854, 3927.96, -0.508845, 5.03527, 0, 0, 0, 1, 120, 255, 1),
( 196818, 648, 1, 1024, 880.547, 3894.37, -0.705065, 0.314158, 0, 0, 0, 1, 120, 255, 1),
( 196824, 648, 1, 1024, 1025.23, 3856.29, -0.714786, 4.84329, 0, 0, 0, 1, 120, 255, 1),
( 196822, 648, 1, 1024, 978.387, 3863.73, -0.71228, 4.13643, 0, 0, 0, 1, 120, 255, 1),
( 196397, 648, 1, 1032, 989.276, 3810.35, -3.9846, 2.68781, 0, 0, 0, 1, 120, 255, 1), -- залезть на корабль. ToDo 
( 196396, 648, 1, 1032, 965.863, 3821.98, -3.89254, 5.86431, 0, 0, 0, 1, 120, 255, 1);

-- some with aura 31261

DELETE FROM creature WHERE id = 36176;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(36176, 648, 1, 1024, 0, 0, 1026.34, 3861.48, 0.657364, 1.65806, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1019.83, 3816.17, -1.48139, 1.41372, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1024.81, 3856.18, 0.555807, 4.03171, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 991.474, 3843.44, 14.0969, 3.80851, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 981.264, 3867.84, 0.663825, 0.890118, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 980.116, 3866.84, 0.129798, 2.53073, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 982.608, 3866.95, 0.660438, 0.890118, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 976.512, 3869.99, -1.38487, 5.8294, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 984.081, 3843.13, 13.3541, 3.78549, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 958.184, 3884.87, -1.71044, 0.837758, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 993.078, 3847.48, 15.4196, 3.77485, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 959.731, 3827.42, -1.46759, 3.78736, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1025.54, 3857.66, 0.108346, 4.17134, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1024.54, 3861.19, 0.657223, 1.65806, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1021.77, 3852.05, -1.42788, 1.02974, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 964.911, 3887.54, -1.77475, 1.02974, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 995.154, 3839.09, 3.31274, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 971.477, 3814.44, 3.31476, 2.82743, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 981.198, 3806.91, 3.31553, 2.11185, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 988.568, 3848.06, 14.6678, 2.54818, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 987.349, 3826.94, 9.07462, 0, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 993.908, 3848.06, 15.5031, 1.06465, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 981.359, 3834.73, 3.31351, 4.92183, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 987.46, 3821.27, 8.83262, 5.55015, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 992.26, 3841.78, 13.9183, 3.71755, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 974.471, 3825.44, 8.75554, 2.54818, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 983.153, 3828.78, 9.14276, 0.925025, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 993.087, 3848.01, 15.4196, 5.05447, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 979.974, 3862.61, 0.52264, 0.890118, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 978.311, 3863.72, 0.499834, 0.890118, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 980.161, 3864.58, 0.108192, 0.890118, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1025.44, 3862.55, 0.382346, 1.58825, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1015.36, 3824.28, -1.44302, 1.309, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1016.02, 3854.24, -1.47176, 0.418879, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 982.269, 3865.59, 0.134283, 3.47321, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1029.96, 3828.55, -1.43967, 1.71042, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 964.781, 3857.56, -1.52251, 0.471239, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 974.203, 3848.69, -1.67555, 1.20428, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 973.804, 3856.26, -1.47806, 0.907571, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 949.653, 3832.32, -1.46884, 4.13643, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 943.906, 3848.54, -1.46149, 3.05433, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1027.39, 3856.46, 0.553046, 3.92699, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 999.25, 3808.45, -1.46345, 4.76475, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 946.177, 3851.09, -1.41059, 5.8294, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1026.75, 3859.88, 0.115175, 3.49066, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1024.55, 3857.57, 0.169316, 4.17134, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 996.984, 3843.77, 14.5108, 0.977127, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1033.66, 3845.24, -1.35327, 2.19912, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1010.65, 3800.68, -1.45978, 4.11898, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 974.503, 3900.28, 0.147535, 2.58309, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 972.514, 3899.78, 0.151916, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 973.657, 3801.19, 14.4685, 1.76017, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 975.945, 3901.17, 0.674324, 0.453786, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 970.788, 3900.21, 0.425345, 3.49066, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 963.122, 3896.19, -1.67874, 0.471239, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 975.411, 3902.68, 0.674103, 0.401426, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 967.28, 3802.29, 14.9806, 5.58622, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1031.26, 3810.29, -1.41845, 1.67552, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 972.142, 3901.86, 0.148218, 5.77704, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 973.62, 3902.55, 0.147416, 4.31096, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 948.094, 3816.48, -1.41177, 3.64774, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 998.575, 3793.93, -1.50967, 4.92183, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 934.788, 3862.28, -1.48799, 3.78736, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 963.989, 3798.66, 16.101, 2.53176, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 951.422, 3894.61, -1.4246, 0.296706, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 942.05, 3884.01, -1.49597, 0.506145, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 962.805, 3904.53, -1.72971, 5.8294, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1000.66, 3788.04, 0.181447, 1.69297, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 934.727, 3824.41, -1.36201, 4.60767, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1029.17, 3797.24, -1.48875, 4.62512, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1001.71, 3786.37, 0.416058, 4.5204, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1012.76, 3788.5, -1.47509, 3.45575, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 999.208, 3785.08, 0.149317, 5.25344, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1020.32, 3790.84, -1.51504, 4.85202, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1001.78, 3783.98, 0.166423, 5.89921, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1000.92, 3782.83, 0.13303, 6.24828, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 935.378, 3814.06, -1.52355, 4.36332, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1059.13, 3839.74, 14.9458, 2.60252, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1004.32, 3783.05, -1.49836, 2.89725, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 925.717, 3837.15, -1.45939, 1.88496, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1057.48, 3830.06, 13.0164, 6.00492, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 999.003, 3781.96, 0.654622, 4.27606, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 936.016, 3810.44, 0.159305, 1.97222, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 934.915, 3810.75, 0.627296, 1.29154, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 922.698, 3853.23, 0.530745, 4.39823, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1060.3, 3830.71, 13.035, 4.61888, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 921.861, 3851.71, 0.134099, 4.2586, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 921.531, 3849.58, 0.154558, 5.0091, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 933.717, 3810.23, 0.196379, 1.06465, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 920.809, 3848.54, 0.676447, 4.36332, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 920.748, 3848.46, 0.685051, 4.17134, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1054.49, 3813.13, 8.20946, 0.108974, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 934.365, 3807.61, 0.172934, 1.97222, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 920.115, 3852.83, 0.165137, 2.82743, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 932.16, 3809.77, 0.178428, 5.09636, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 919.453, 3851.25, 0.154689, 2.18166, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 933.122, 3807.19, 0.16102, 1.8326, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 919.243, 3849.1, 0.671122, 4.45059, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1059.36, 3818.68, 8.51815, 5.2563, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 930.318, 3808.58, 0.681945, 3.45575, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1034.57, 3787.82, -1.49608, 4.45059, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 930.82, 3806.87, 0.687412, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 916.707, 3853.73, -1.47693, 6.03884, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 928.444, 3891.52, 8.74966, 3.726, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 917.335, 3878.11, 3.23082, 0.031006, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 936.332, 3906.7, 12.9155, 4.60029, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1022.47, 3774.52, -1.45838, 4.93928, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 916.302, 3819.86, -1.46342, 3.92699, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1053.08, 3792.89, 2.61849, 4.6203, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 939.101, 3917.9, 15.4181, 5.42751, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 921.82, 3900.99, 8.82214, 1.42884, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 907.652, 3871.49, 15.5732, 3.74805, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 933.873, 3915.95, 14.1058, 5.16083, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1080.49, 3827.46, -1.50238, 0.523599, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1068.13, 3796.42, 2.61916, 6.09181, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1056.71, 3783.75, 14.588, 4.66012, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 906.843, 3888.96, 3.23074, 4.55581, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 902.928, 3877.35, 15.3465, 3.59204, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1057.58, 3780.56, 15.3611, 4.46861, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1085.57, 3826.54, -1.4429, 0.506145, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1088.18, 3842.06, -1.54935, 2.09439, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1062.42, 3784.04, 14.5212, 2.1112, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1024.29, 3756.39, 0.56964, 4.90438, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1026.72, 3756.95, 0.539296, 4.93928, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1024.98, 3753.23, 0.133187, 5.44543, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1027.08, 3753.65, 0.120118, 4.5204, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1026.86, 3755.17, 0.134421, 4.79965, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1024.51, 3754.69, 0.162868, 5.44543, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1027.35, 3751.74, 0.669647, 4.88692, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1025.45, 3751.45, 0.664922, 4.99164, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1026.53, 3750.62, 0.365828, 4.92183, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1081.01, 3800.69, -1.40635, 2.23402, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 902.967, 3897.06, -1.49418, 3.24631, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1106.68, 3825.76, -1.4916, 1.93731, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1092.06, 3798.97, -1.37104, 2.05949, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1095.8, 3841.97, -1.50865, 5.77704, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1097.23, 3786.4, -1.56635, 4.92183, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1104.85, 3836.67, 0.660665, 0.890118, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1100.8, 3835.65, 0.159302, 6.0912, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1103.93, 3835.31, 0.136555, 2.18166, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1108.33, 3812.3, -1.52011, 0.453786, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1103.66, 3837.85, 0.660811, 0.418879, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1096.06, 3815.74, -1.46718, 1.64061, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1099.95, 3834.3, 0.496717, 0.820305, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1102.56, 3833.93, 0.154785, 1.50098, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1105.11, 3838.12, 0.387136, 0.890118, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1102.3, 3837.12, 0.137754, 4.92183, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1101.49, 3832.93, 0.554069, 3.89208, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1097.08, 3778.97, 0.390807, 5.32325, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1097.25, 3780.36, 0.176789, 1.6057, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1096.11, 3778.02, 0.565611, 5.46288, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1099.58, 3774.27, 0.673351, 5.44543, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1100.09, 3776.73, 0.130184, 3.87463, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1098.85, 3775.74, 0.105982, 5.41052, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1098.4, 3776.99, 0.115196, 5.51524, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 1100.89, 3775.37, 0.672749, 4.97419, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 919.465, 3920.95, -1.42762, 2.77507, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 909.611, 3926.57, -1.44253, 3.00197, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 886.554, 3909.69, -1.42267, 4.17134, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 883.54, 3923.77, -1.34777, 2.80998, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 901.339, 3917.14, -1.44173, 1.74533, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 896.943, 3909.86, -1.42084, 3.82227, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 895.884, 3907.3, -1.49227, 3.80482, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 889.892, 3897.71, -1.42912, 3.42085, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 898.7, 3927.75, 0.733848, 3.71755, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 898.224, 3929.04, 0.35613, 4.27606, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 895.304, 3925.07, -1.44326, 0.872665, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 899.365, 3926.93, 0.326354, 3.57792, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 900.172, 3929.55, 0.323534, 3.92699, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 878.278, 3895.86, 0.147676, 3.50811, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 877.193, 3894.3, 0.104106, 3.50811, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 880.045, 3896.32, 0.543775, 3.50811, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 878.925, 3893.66, 0.145932, 3.45575, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 875.13, 3894.86, 0.673376, 3.49066, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 875.708, 3893.14, 0.66598, 3.42085, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(36176, 648, 1, 1024, 0, 0, 880.531, 3894.57, 0.469096, 3.45575, 120, 0, 0, 1, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = 36176;
-- DEAD ON OUR SHIP
DELETE FROM `creature_addon` WHERE guid IN (select guid from creature WHERE id = 36176);
INSERT INTO `creature_addon` (`guid`, `bytes2`, auras) SELECT guid, 1, '31261' FROM creature where id = 36176 and position_z > 2 AND (`position_x` > 960 AND `position_x` < 997) AND (`position_y` > 3790 AND `position_y` < 3850);
-- ON WATTER
INSERT INTO `creature_addon` (`guid`, `bytes2`, auras) SELECT guid, 1, '37744' FROM creature where id = 36176 and position_z < 0.3;
-- ON BOAT
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, auras) SELECT guid, 1, 1, '' FROM creature where id = 36176 and position_z < 1 and position_z > 0.3;

-- ----------------------------------------
-- Q: 14243 Warchief's Revenge music 16424 summon 68408
-- ----------------------------------------

UPDATE `quest_template` SET `RequiredIdCount1` = '50', `StartScript` = '14243' WHERE `Id` in (7, 14243);
DELETE FROM `quest_start_scripts` WHERE id = 14243;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14243', '0', '15', '68408', '2', '0', '0', '0', '0', '0');
-- ('14243', '0', '16', '16424', '2', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `InhabitType` = '4', `ScriptName` = 'npc_cyclone_of_the_elements' WHERE `entry` = 36178;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36178;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES ('36178', '68436', '1', '0');

DELETE FROM `creature_text` WHERE entry = 36178;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36178, 0, 0, 'Направляюсь к Лесному наблюдательному пункту.', 42, 0, 100, 0, 0, 0, '');

SET @id = 0;
SET @entry = 36178;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
-- enter to the patch
(@entry, @id := @id+ 1, 984.9549, 3826.142, 10.02539, 0, NULL),
(@entry, @id := @id+ 1, 995.3038, 3830.475, 11.08103, 0, NULL),
(@entry, @id := @id+ 1, 1005.217, 3832.418, 14.52542, 0, NULL),
-- cycle
(@entry, @id := @id+ 1, 1022.352, 3831.351, 24.62974, 0, NULL),
(@entry, @id := @id+ 1, 1004.325, 3782.394, 21.71304, 0, NULL),
(@entry, @id := @id+ 1, 975.882, 3771.541, 20.71306, 0, NULL),
(@entry, @id := @id+ 1, 943.9549, 3785.924, 22.26854, 0, NULL),
(@entry, @id := @id+ 1, 936.1754, 3820.981, 21.93524, 0, NULL),
(@entry, @id := @id+ 1, 952.6996, 3861.26, 24.54637, 0, NULL),
(@entry, @id := @id+ 1, 968.7101, 3914.839, 20.3796, 0, NULL),
(@entry, @id := @id+ 1, 936.5087, 3944.062, 21.12957, 0, NULL),
(@entry, @id := @id+ 1, 893.6545, 3935.708, 20.87961, 0, NULL),
(@entry, @id := @id+ 1, 866.3246, 3895.795, 21.51845, 0, NULL),
(@entry, @id := @id+ 1, 867.1771, 3849.851, 21.32399, 0, NULL),
(@entry, @id := @id+ 1, 903.8854, 3827.217, 19.57398, 0, NULL),
(@entry, @id := @id+ 1, 937.9149, 3841.934, 19.26847, 0, NULL),
(@entry, @id := @id+ 1, 962.5104, 3859.353, 20.29623, 0, NULL),
(@entry, @id := @id+ 1, 1004.835, 3861.208, 19.96292, 0, NULL),
(@entry, @id := @id+ 1, 1021.788, 3827.314, 20.99073, 0, NULL),
(@entry, @id := @id+ 1, 1033.106, 3773.803, 23.60179, 0, NULL),
(@entry, @id := @id+ 1, 1062.802, 3755.345, 22.85184, 0, NULL),
(@entry, @id := @id+ 1, 1097.905, 3780.767, 20.29626, 0, NULL),
(@entry, @id := @id+ 1, 1097.259, 3826.478, 18.90739, 0, NULL),
(@entry, @id := @id+ 1, 1071.38, 3852.879, 21.18516, 0, NULL),
(@entry, @id := @id+ 1, 1042.181, 3857.24, 23.60183, 0, NULL),
-- go to the end point
(@entry, @id := @id+ 1, 956.4236, 3740.38, 70.96297, 0, NULL),
(@entry, @id := @id+ 1, 950.8785, 3662.27, 14.79625, 0, NULL),
(@entry, @id := @id+ 1, 915.7361, 3451.169, 2.296269, 0, NULL),
(@entry, @id := @id+ 1, 907.1424, 3327.42, 23.4872, 0, NULL),
(@entry, @id := @id+ 1, 960.3212, 3212.715, 111.3099, 0, NULL),
(@entry, @id := @id+ 1, 995.8976, 3143.984, 145.0299, 0, NULL),
(@entry, @id := @id+ 1, 1007.958, 3070.123, 147.641, 0, NULL),
(@entry, @id := @id+ 1, 901.7518, 2926.978, 147.641, 0, NULL),
(@entry, @id := @id+ 1, 872.4948, 2765.59, 119.8911, 0, NULL);

-- --------------------------------
--          PHASE 8. Continue after 11.
-- --------------------------------

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36513;
DELETE FROM smart_scripts WHERE entryorguid = 36513;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36513, 0, 0, 0, 60, 0, 100, 0, 30000, 30000, 60000, 60000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Say text at summon'),
(36513, 0, 1, 0, 60, 0, 100, 0, 40000, 40000, 60000, 60000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Say text at summon'),
(36513, 0, 2, 0, 60, 0, 100, 0, 50000, 50000, 60000, 60000, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Say text at summon');

DELETE FROM `creature_text` WHERE entry = 36513;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36513, 0, 0, 'Кого ты здесь перед нами корчишь? Думаешь, тебе ноги целовать будут за спасение и дружбу с орками?', 14, 0, 100, 25, 0, 19584, 'Торговый принц Галливикс'),
(36513, 1, 0, 'Я тебя раздавлю! Я торговый принц! Я! Я уже знаю, как выбраться с этого острова и стать королем Азшары!', 14, 0, 100, 25, 0, 19585, 'Торговый принц Галливикс'),
(36513, 2, 0, 'Попомни мои слова! Я до вас всех доберусь! До всех! С дороги!', 14, 0, 100, 15, 0, 19586, 'Торговый принц Галливикс');

-- ----------------------------------------
-- Q: 14244 Up, Up & Away!
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredIdCount1` = '1', `StartScript` = '0' WHERE `Id` = 14244;
DELETE FROM `quest_start_scripts` WHERE id = 10;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36425;
DELETE FROM smart_scripts WHERE entryorguid = 36425;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36425, 0, 0, 0, 47, 0, 100, 0, 14244, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14244');

DELETE FROM `creature_text` WHERE entry = 36425;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36425, 0, 0, 'Ну-ну, торговый принц.', 12, 0, 100, 1, 0, 0, 'Хамми Кофельнагель');

DELETE FROM `gossip_menu` WHERE `entry`=10808;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10808, 14985); -- 196439

DELETE FROM gossip_menu_option WHERE menu_id = 10808;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `box_coded`, `box_money`, `box_text`) VALUES
(10808, 0, 0, 'Вперед и вверх!', 1, 0, 0, ''); -- 196439

-- Spell ID: 68806 Summon 36505
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=196439;
DELETE FROM `smart_scripts` WHERE entryorguid = 196439;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('196439', '1', '0', '0', '62', '0', '100', '0', '10808', '0', '0', '0', '11', '68806', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', 'at gossipselect cast on plr');

UPDATE `creature_template` SET `InhabitType` = '4', `minlevel` = '10', `maxlevel` = '10', `faction_A` = '2204', `faction_H` = '2204', `unit_flags` = '776', `VehicleId` = '524', `ScriptName` = 'npc_sling_rocket' WHERE `creature_template`.`entry` = 36505;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36505;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES ('36505', '68805', '1', '0');

SET @id = 0;
SET @entry = 36505;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
-- enter to the patch
(@entry, @id := @id+ 1, 882.4566, 2726.064, 146.0856, 0, NULL),
(@entry, @id := @id+ 1, 890.9149, 2697.69, 164.5292, 0, NULL),
(@entry, @id := @id+ 1, 916.3698, 2591.611, 207.5022, 0, NULL),
(@entry, @id := @id+ 1, 928.4583, 2538.972, 196.3079, 0, NULL),
(@entry, @id := @id+ 1, 932.9393, 2506.701, 167.4186, 0, NULL),
(@entry, @id := @id+ 1, 941.3195, 2463.62, 111.2246, 0, NULL),
(@entry, @id := @id+ 1, 945.6337, 2440.615, 69.7246, 0, NULL),
(@entry, @id := @id+ 1, 945.2621, 2396.825, 4.585697, 0, NULL);

-- --------------------------------
--          PHASE 8. Continue after 11.
-- --------------------------------
UPDATE spell_area SET quest_end = 14245, quest_end_status = 66 WHERE spell = 68421 AND area = 4720; -- END 1024 phase

DELETE FROM spell_area WHERE spell = 68750 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('68750', '4720', '14245', '0', '0', '0', '2', '1', '66', '0'); -- appear on complete  14245 and continue after reward

DELETE FROM `phase_definitions` WHERE zoneId = 4720 AND phaseId = 180;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `wmAreaId`, `flags`, `comment`) VALUES 
('4720', '1', '0', '180', '661', '681', '0', 'Town-In-A-Box phase of 68750');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND SourceGroup = 4720 AND SourceEntry = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(23, 4720, 1, 0, 0, 28, 0, 14245, 0, 0, 0, 0, '', NULL), -- CONDITION_QUEST_COMPLETE 
(23, 4720, 1, 0, 1, 8, 0, 14245, 0, 0, 0, 0, '', NULL); -- CONDITION_QUESTREWARDED
-- (23, 4720, 1, 0, 2, 14, 0, 14466, 0, 0, 0, 0, '', NULL); -- CONDITION_QUEST_NONE for remove at get quest

-- ----------------------------------------
-- Q: 14245 It's a Town-In-A-Box
-- ----------------------------------------

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36470;
DELETE FROM smart_scripts WHERE entryorguid = 36470;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36470, 0, 0, 0, 47, 0, 100, 0, 14245, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 14245');
DELETE FROM `creature_text` WHERE entry = 36470;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36470, 0, 0, 'Быстрее, $N, разворачивай Городок-из-табакерки. Там заперты наши друзья, и им грозит опасность! Ой! Я чуть не забыл о твоем парашюте.', 12, 0, 100, 25, 0, 0, 'Штейгер Промоках');

DELETE FROM `creature` WHERE id = 36470;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(36470, 648, 1, 8, 943.8055, 2372.589, 5.604537, 1.500983, 120, 0, 0); -- 36470 (Area: 4816)
