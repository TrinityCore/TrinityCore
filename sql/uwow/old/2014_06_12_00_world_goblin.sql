/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- =================
-- Misc Data
-- =================

-- Fix PhaseShift poi
UPDATE `quest_poi` SET WorldMapAreaId = 605 WHERE `mapid` = 648; 

-- Mage Trainer
SELECT `guid` FROM creature where id = 34696 LIMIT 1 INTO @warlock;
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `entry` =34689;
UPDATE  `creature_equip_template` SET  `ItemEntry1` =  '11588' WHERE `entry` =34689;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34689;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34689, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 15000, 15000, 11, 69608, 0, 0, 0, 0, 0, 10, @warlock, 34696, 0, 0, 0, 0, 0, 'Cast Fireball OOC');

-- Warlock Trainer
SELECT `guid` FROM creature where id = 34689 LIMIT 1 INTO @mage;
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `entry` =34696;
UPDATE  `creature_equip_template` SET  `ItemEntry1` =  '27923' WHERE `entry` =34696;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34696;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34696, 0, 0, 0, 1, 0, 100, 0, 10000, 10000, 20000, 20000, 11, 69607, 0, 0, 0, 0, 0, 10, @mage, 34689, 0, 0, 0, 0, 0, 'Cast Shadow bolt OOC');

-- Shaman Trainer
-- 69626. 69630
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `entry` =34695;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34695;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34695, 0, 0, 0, 1, 0, 100, 0, 500, 1000, 600000, 600000, 11, 78273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cast Flametongue Weapon on Spawn'),
(34695, 0, 1, 0, 1, 0, 100, 0, 7500, 7500, 20000, 20000, 11, 69626, 0, 0, 0, 0, 0, 10, @mage, 34689, 0, 0, 0, 0, 0, 'Cast Lightning Bolt OOC');

-- Hunter Trainer
SELECT `guid` FROM creature where id = 48304 LIMIT 1 INTO @train;
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `entry` =34673;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34673;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34673, 0, 0, 0, 1, 0, 100, 0, 10000, 10000, 20000, 20000, 11, 69509, 0, 0, 0, 0, 0, 10, @train, 48304, 0, 0, 0, 0, 0, 'Cast Shoot Gun OOC');

-- Hot Rod spells
DELETE FROM `spell_script_names` WHERE spell_id in (66299, 90247);
INSERT INTO  `spell_script_names` (`spell_id` ,`ScriptName`)VALUES 
('66299',  'spell_gen_radio'),
('90247',  'spell_gen_stop_playing_current_music');

-- =================
-- Quest relation
-- =================

DELETE FROM `creature_questrelation` WHERE `quest` IN (14071,14093,14098,14115,14122,14125,14153,14204,14218,14222,24930);
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES (34874, 14071),(34850,14093),(34850,14098),(34668,14115),(34668,14122),(34668,14125),(35054,14153),(35378,14204),(35618,14218),(35566,14222),(35115,24930);
DELETE FROM `creature_involvedrelation` WHERE `quest` in (14075,14078,14091,14138);
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES (34850,14091),(34863,14078),(34872,14075),(34872,14138);
DELETE FROM  `creature_involvedrelation` WHERE `quest` =28414;
DELETE FROM `creature_questrelation` WHERE `quest` = 28414;
INSERT IGNORE INTO `creature_questrelation` (`id`, `quest`) VALUES ('37106', '24503');

-- =================
-- Quest Data
-- =================

-- q14069. Хороших работников трудно найти
UPDATE `quest_template` SET  `Method` =  '2', `CompleteScript` =  '14069' WHERE  `Id` =14069;
DELETE FROM `quest_end_scripts` WHERE `id` = 14069;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14069', '1', '0', '0', '0', '2000005505', '0', '0', '0', '0');
DELETE FROM `db_script_string` WHERE `entry` = 2000005505;
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000005505', 'Босс, передайте Хамми, что я достану для нее "Каджа-Колы", как только наладится производство.', 'Босс, передайте Хамми, что я достану для нее "Каджа-Колы", как только наладится производство.');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 34830;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('34830', '66306', '1', '0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 66306;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 34830, 66306, 9, 0, 14069, 0, 0, 'Required quest active for spellclick');

UPDATE  `creature_template` SET  `npcflag` =  '16777216', `flags_extra` = '2', `ScriptName` = 'npc_deffiant_troll' WHERE `entry` =34830;
DELETE FROM `creature_addon` WHERE `guid` in (select `guid` from `creature` where `id` = 34830);
DELETE FROM  `creature_template_addon` WHERE  `entry` =34830;
DELETE FROM `creature_text` WHERE entry = 34830;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34830, 0, 0, 'Ой! Перерыв закончился!', 12, 0, 100, 5, 0, 12007, 'Взбунтовавшийся тролль'),
(34830, 1, 0, 'Что я делаю не так? Разве мне не положен обед и два перерыва в день?', 12, 0, 100, 5, 0, 12007, 'Взбунтовавшийся тролль'),
(34830, 2, 0, 'Что я делаю не так? Разве мне не положен обед и два перерыва в день?', 12, 0, 100, 5, 0, 5038, 'Взбунтовавшийся тролль'),
(34830, 3, 0, 'Извини, чувак. Больше это не повторится.', 12, 0, 100, 5, 0, 12007, 'Взбунтовавшийся тролль'),
(34830, 4, 0, 'Ой! Больно!', 12, 0, 100, 5, 0, 12007, 'Взбунтовавшийся тролль'),
(34830, 5, 0, 'Не делай мне больно, чувак!', 12, 0, 100, 5, 0, 12007, 'Взбунтовавшийся тролль'),
(34830, 6, 0, 'Иду я, иду!', 12, 0, 100, 5, 0, 12007, 'Взбунтовавшийся тролль'),
(34830, 7, 0, 'Я доложу про тебя в отдел кадров!', 12, 0, 100, 5, 0, 12007, 'Взбунтовавшийся тролль');

-- У мобов присутсвовала стан-аура 29266, она мешала атаковать противников. Возможно аура наклазывается после смерти, или снимается с аггро.
UPDATE `creature_template_addon` SET  `auras` =  '' WHERE `entry` in(35294, 34865);


-- q14138
UPDATE  `quest_template` SET  `CompleteScript` =  '14138', `StartScript` =  '14138' WHERE  `Id` =14138;
DELETE FROM `quest_end_scripts` WHERE `id` = 14138;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14138', '0', '1', '432', '0', '0', '0', '0', '0', '0'),
('14138', '1', '0', '0', '0', '2000005501', '0', '0', '0', '0'),
('14138', '6', '15', '82025', '1', '0', '0', '0', '0', '0'),
('14138', '6', '16', '18495', '0', '0', '0', '0', '0', '0'),
('14138', '7', '0', '1', '0', '2000005502', '0', '0', '0', '0'),
('14138', '10', '1', '5', '0', '0', '0', '0', '0', '0'),
('14138', '10', '0', '0', '0', '2000005503', '0', '0', '0', '0');
DELETE FROM `quest_start_scripts` WHERE `id` = 14138;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14138', '0', '1', '1', '0', '0', '0', '0', '0', '0'),
('14138', '2', '0', '0', '0', '2000005504', '0', '0', '0', '0');
DELETE FROM `db_script_string` WHERE `entry` in(2000005501, 2000005502, 2000005503, 2000005504);
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000005501', 'Так приятно получить подарок из рук второй по важности шишки. Ну-ка, посмотрим, что там!', 'Так приятно получить подарок из рук второй по важности шишки. Ну-ка, посмотрим, что там!'),
('2000005502', 'Ай!', 'Ай!'),
('2000005503', 'Ладно, ладно! Я все понял!', 'Ладно, ладно! Я все понял!'),
('2000005504', 'Ха-ха! Вот здорово!', 'Ха-ха! Вот здорово!');

-- q25473
UPDATE  `quest_template` SET  `CompleteScript` =  '25473' WHERE  `Id` =25473;
DELETE FROM `quest_end_scripts` WHERE `id` = 25473;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('28349', '1', '1', '274', '0', '0', '0', '0', '0', '0'),
('25473', '2', '0', '0', '0', '2000005505', '0', '0', '0', '0');
DELETE FROM `db_script_string` WHERE `entry` = 2000005505;
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000005505', 'Потом он принесет еще? Как же мы сделаем тебя $gторговым принцем:торговой принцессой;, если наш главный товар не поступил в продажу?!!', 'Потом он принесет еще? Как же мы сделаем тебя $gторговым принцем:торговой принцессой;, если наш главный товар не поступил в продажу?!!');

-- q28349
UPDATE  `quest_template` SET  `CompleteScript` =  '28349' WHERE  `Id` =28349;
DELETE FROM `quest_end_scripts` WHERE `id` = 28349;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('28349', '1', '1', '273', '0', '0', '0', '0', '0', '0'),
('28349', '2', '0', '0', '0', '2000005506', '0', '0', '0', '0');
DELETE FROM `db_script_string` WHERE `entry` = 2000005506;
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000005506', 'О-о, босс, я думаю, вам это понравится!', 'О-о, босс, я думаю, вам это понравится!');

-- q14071. Ивент сообщение о том, что нужно сесть в машину. 
UPDATE  `quest_template` SET  `StartScript` =  '14071' WHERE  `Id` =14071;
DELETE FROM `db_script_string` WHERE `entry` = 2000005500;
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000005500', 'Используйте ключи к хотроду|TInterface\Icons\inv_misc_key_12.blp:32|t, чтобы сесть в автомобиль. Заедьте за своими друзьями: Иззи, Тузом и Гоббером.', 'Используйте ключи к хотроду|TInterface\\Icons\\inv_misc_key_12.blp:32|t, чтобы сесть в автомобиль. Заедьте за своими друзьями: Иззи, Тузом и Гоббером.');
DELETE FROM `quest_start_scripts` WHERE `id` = 14071;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
('14071', '5', '0', '42', '0', '2000005500', '0', '0', '0', '0');

-- Hot Rod basic script for future quest partition.
UPDATE  `creature_template` SET  `ScriptName` =  'npc_hot_rod' WHERE  `creature_template`.`entry` =34840;

UPDATE  `creature_template` SET  `unit_flags` =  '16392',`dynamicflags` =  '0',`type_flags` =  '40',`VehicleId` =  '448', `spell2` =  '0', `spell3` =  '66298',`spell4` =  '66299' WHERE  `creature_template`.`entry` =34840;
UPDATE  `creature_template` SET  `minlevel` =  '3', `maxlevel` =  '3', `faction_A` =  '2204',`faction_H` =  '2204', `npcflag` =  '1', `baseattacktime` =  '2000', `rangeattacktime` =  '2000', `unit_flags` =  '32768', `unit_flags2` =  '33556480' WHERE `entry` =34959;
UPDATE  `creature_template` SET  `minlevel` =  '3',`maxlevel` =  '3', `faction_A` =  '2204',`faction_H` =  '2204', `baseattacktime` =  '2000', `rangeattacktime` =  '2000', `unit_flags` =  '32776', `unit_flags2` =  '33556480' WHERE `entry` =34957;
UPDATE  `creature_template` SET  `minlevel` =  '3', `maxlevel` =  '3', `faction_A` =  '2204', `faction_H` =  '2204', `baseattacktime` =  '2000', `rangeattacktime` =  '2000', `unit_flags` =  '32776', `unit_flags2` =  '33556480' WHERE `entry` =34958;


-- q14071. Rolling with my Homies
DELETE FROM `creature` WHERE `id` in (34959, 34957, 34958, 34890, 34892, 34954);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(34890, 648, 1, 1, 0, 0, -8507.65, 1342.85, 101.78, 6.26573, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(34954, 648, 1, 1, 0, 0, -8179.48, 1321.38, 27.6826, 5.25344, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(34892, 648, 1, 1, 0, 0, -8068.13, 1482.03, 9.01469, 3.59538, 120, 0, 0, 1, 0, 0, 0, 0, 0);
DELETE FROM `creature_template_addon` WHERE `entry` in (34890, 34892, 34954);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(34890, 0, 0, 65537, 1, 0, '66405'),
(34892, 0, 0, 65536, 1, 0, '66403'),
(34954, 0, 0, 65536, 1, 0, '66404');

UPDATE  `creature_template` SET  `ScriptName` =  'npc_roling_friends' WHERE  `entry` in (34890, 34892, 34954);
UPDATE  `creature_template` SET  `ScriptName` =  'npc_roling_friends_guard' WHERE  `entry` in (34959, 34957, 34958);
-- group 0 = on kill, 1 = on aggro, 2 = onEvent
DELETE FROM `creature_text` WHERE `entry` in (34957, 34959);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34957, 0, 0, 'Я всегда тебя ненавидел!', 12, 0, 100, 0, 0, 0, 'Туз'),
(34957, 0, 1, 'Я весь день этого ждал!', 12, 0, 100, 0, 0, 0, 'Туз'),
(34957, 0, 2, 'Ты на меня смотришь?', 12, 0, 100, 0, 0, 0, 'Туз'),
(34957, 1, 0, 'Бей по морде! По морде!', 12, 0, 100, 0, 0, 0, 'Туз'),
(34957, 2, 0, 'Что это было, парни?', 12, 0, 100, 6, 0, 0, 'Туз'),
(34957, 0, 3, 'Не будешь связываться с нами!', 12, 0, 100, 0, 0, 0, 'Туз'),
(34959, 0, 0, 'Я весь день этого ждала!', 12, 0, 100, 0, 0, 0, 'Иззи'),
(34959, 0, 1, 'Ты на меня смотришь?', 12, 0, 100, 0, 0, 0, 'Иззи'),
(34959, 0, 2, 'Настал час расплаты!', 12, 0, 100, 0, 0, 0, 'Иззи'),
(34959, 2, 0, '$N, почему дрожит земля?!', 12, 0, 100, 5, 0, 0, 'Иззи'),
(34959, 1, 0, 'Бей их!', 12, 0, 100, 0, 0, 0, 'Иззи');
UPDATE  `quest_template` SET  `CompleteScript` =  '14071' WHERE  `Id` =14071;
DELETE FROM `quest_end_scripts` WHERE `id` = 14071;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('14071', '1', '1', '1', '0', '0', '0', '0', '0', '0'),
('14071', '2', '0', '0', '0', '2000005507', '0', '0', '0', '0');
DELETE FROM `db_script_string` WHERE `entry` = 2000005507;
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000005507', 'А вот и они! Вы втроем помогите $gему:ей; подготовить все к вечеринке. $gЕму:ей; предстоит много работы.', 'А вот и они! Вы втроем помогите $gему:ей; подготовить все к вечеринке. $gЕму:ей; предстоит много работы.');

-- q14070. Do it Yourself
DELETE FROM `quest_poi` WHERE `questId` = 14070;
INSERT INTO `quest_poi` (`questId`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(14070, 0, 0, 648, 605, 0, 1, 265427),
(14070, 1, 0, 648, 605, 0, 1, 265428),
(14070, 2, 0, 648, 605, 0, 1, 265429),
(14070, 3, 0, 648, 605, 0, 1, 265430),
(14070, 4, -1, 648, 605, 0, 7, 0);
UPDATE `quest_template` SET RequiredPOI1 = 265427, RequiredPOI2 = 265428, RequiredPOI3 = 265429, RequiredPOI4 = 265430, RequiredUnkFlag1 = 1, RequiredUnkFlag2 = 1, RequiredUnkFlag3 = 1, RequiredUnkFlag4 = 1 WHERE id = 14070;
UPDATE `creature_template` SET  type_flags=4, dynamicflags=33554432, unit_flags=32768, `faction_A` = '7', `faction_H` = '7', `IconName` = 'Attack', `rangeattacktime` =  '2000', `unit_flags2` = '33556480', `type_flags` =  '0' WHERE  `entry` =34835;
UPDATE `creature_template` SET  type_flags=4, dynamicflags=33554432, unit_flags=32768, `faction_A` = '7', `faction_H` = '7', `IconName` = 'Attack', `rangeattacktime` =  '2000',`unit_flags2` =  '33556480', `type_flags` =  '0' WHERE `entry` =34876;
UPDATE `creature_template` SET  type_flags=4, dynamicflags=33554432, unit_flags=32768, `faction_A` = '7', `faction_H` = '7', `IconName` = 'Attack', `rangeattacktime` =  '2000',`unit_flags2` =  '33556480', `type_flags` =  '0' WHERE `entry` =34877;
UPDATE `creature_template` SET  type_flags=4, dynamicflags=33554432, unit_flags=32768, `faction_A` = '7', `faction_H` = '7', `IconName` = 'Attack', `rangeattacktime` =  '2000',`unit_flags2` =  '33556480', `type_flags` =  '0' WHERE `entry` =34878;
-- Бруно Негорючий
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `entry` =34835;
DELETE FROM smart_scripts WHERE entryorguid = 34835;
INSERT INTO  `smart_scripts` (`entryorguid` ,`source_type` ,`id` ,`link` ,`event_type` ,`event_phase_mask` ,`event_chance` ,`event_flags` ,`event_param1` ,`event_param2` ,`event_param3` ,`event_param4` ,`action_type` ,`action_param1` ,`action_param2` ,`action_param3` ,`action_param4` ,`action_param5` ,`action_param6` ,`target_type` ,`target_param1` ,`target_param2` ,`target_param3` ,`target_x` ,`target_y` ,`target_z` ,`target_o` ,`comment`)VALUES 
('34835',  '0',  '0',  '0',  '4',  '0',  '100',  '0',  '0',  '0',  '0',  '0',  '1',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  'Бруно Негорючий onAggro text'), 
('34835',  '0',  '1',  '0',  '6',  '0',  '100',  '0',  '0',  '0',  '0',  '0',  '1',  '1',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  'Бруно Негорючий onDeath text');
DELETE FROM creature_text WHERE entry = 34835;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34835, 0, 0, 'Я как раз хотел повидаться с тобой. Не веришь?', 12, 0, 100, 0, 0, 0, 'Бруно Негорючий'),
(34835, 1, 0, 'Проклятье! Уловка не сработала!', 12, 0, 100, 0, 0, 0, 'Бруно Негорючий');
-- Френки Скрипетелька
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `creature_template`.`entry` =34876;
DELETE FROM creature_text WHERE entry = 34876;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34876, 0, 0, 'Что? Ладно, ладно... Я буду платить твоим громилам за защиту!', 12, 0, 100, 0, 0, 0, 'Френки Скрипетелька');
DELETE FROM smart_scripts WHERE entryorguid = 34876;
INSERT INTO `smart_scripts` (`entryorguid` ,`source_type` ,`id` ,`link` ,`event_type` ,`event_phase_mask` ,`event_chance` ,`event_flags` ,`event_param1` ,`event_param2` ,`event_param3` ,`event_param4` ,`action_type` ,`action_param1` ,`action_param2` ,`action_param3` ,`action_param4` ,`action_param5` ,`action_param6` ,`target_type` ,`target_param1` ,`target_param2` ,`target_param3` ,`target_x` ,`target_y` ,`target_z` ,`target_o` ,`comment`)VALUES 
('34876',  '0',  '0',  '0',  '6',  '0',  '100',  '0',  '0',  '0',  '0',  '0',  '1',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  'Френки Скрипетелька onDeath text');
-- Джек Молоток
DELETE FROM creature_text WHERE entry = 34877;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34877, 0, 0, '%s рычит и сдается, признав поражение.', 16, 0, 100, 0, 0, 0, 'Джек Молоток');
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `creature_template`.`entry` =34877;
DELETE FROM smart_scripts WHERE entryorguid = 34877;
INSERT INTO `smart_scripts` (`entryorguid` ,`source_type` ,`id` ,`link` ,`event_type` ,`event_phase_mask` ,`event_chance` ,`event_flags` ,`event_param1` ,`event_param2` ,`event_param3` ,`event_param4` ,`action_type` ,`action_param1` ,`action_param2` ,`action_param3` ,`action_param4` ,`action_param5` ,`action_param6` ,`target_type` ,`target_param1` ,`target_param2` ,`target_param3` ,`target_x` ,`target_y` ,`target_z` ,`target_o` ,`comment`)VALUES 
('34877',  '0',  '0',  '0',  '6',  '0',  '100',  '0',  '0',  '0',  '0',  '0',  '1',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  'Джек Молоток onDeath text');
-- Судзи Магик
DELETE FROM creature_text WHERE entry = 34878;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34878, 0, 0, 'Не по лицу, только не по лицу!', 12, 0, 100, 0, 0, 0, 'Судзи Магик');
UPDATE  `creature_template` SET  `AIName` =  'SmartAI' WHERE  `creature_template`.`entry` =34878;
DELETE FROM smart_scripts WHERE entryorguid = 34878;
INSERT INTO `smart_scripts` (`entryorguid` ,`source_type` ,`id` ,`link` ,`event_type` ,`event_phase_mask` ,`event_chance` ,`event_flags` ,`event_param1` ,`event_param2` ,`event_param3` ,`event_param4` ,`action_type` ,`action_param1` ,`action_param2` ,`action_param3` ,`action_param4` ,`action_param5` ,`action_param6` ,`target_type` ,`target_param1` ,`target_param2` ,`target_param3` ,`target_x` ,`target_y` ,`target_z` ,`target_o` ,`comment`)VALUES 
('34878',  '0',  '0',  '0',  '6',  '0',  '100',  '0',  '0',  '0',  '0',  '0',  '1',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  'Судзи Магик onDeath text');

-- q.24502 Necessary Roughness / Вынужденная неучтивость
-- UPDATE `quest_template` SET  `OfferRewardText` =  'У тебя получилось, $gмалыш:малышка;! Теперь нам осталось забить один гол, и мы – чемпионы!', `RequiredNpcOrGo1` =  '48271', `RequiredNpcOrGo2` =  '37114', `RequiredNpcOrGoCount1` =  '1', `RequiredNpcOrGoCount2` =  '8', `RewardReputationMask` =  '1' WHERE `Id` =24502;
DELETE FROM `creature` WHERE `id` in(48526, 37114);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
( 48526, 648, 1, 1, 0, 0, -8250.91, 1484.29, 41.4999, 3.12414, 120, 0, 0, 1, 0, 0, 0, 0, 0);
UPDATE `creature_template` SET  `npcflag` =  '16777216', `rangeattacktime` =  '2000', `unit_flags2` =  '34816', `dynamicflags` =  '0' WHERE `entry` =48526;
UPDATE `creature_template` SET  `minlevel` =  '5', `maxlevel` =  '5', `faction_A` =  '2204', `faction_H` =  '2204', `unit_flags` =  '8', `unit_flags2` =  '67584', `type_flags2` =  '0', `spell1` =  '69992', `VehicleId` =  '582' WHERE `entry` =37179;
DELETE FROM `creature_template_addon` WHERE `entry`= 37114;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('37114', '0', '0', '0', '1', '438', NULL);
UPDATE  `creature_template` SET  `faction_A` =  '2204', `faction_H` =  '2204', `baseattacktime` =  '2000', `rangeattacktime` =  '2000', `unit_flags` =  '32776' WHERE `entry` =37114;

UPDATE  `quest_template` SET  `StartScript` =  '24502' WHERE  `Id` =24502;
DELETE FROM `quest_start_scripts` WHERE `id` = 24502;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('24502', '2', '1', '25', '0', '0', '0', '0', '0', '0'),
('24502', '1', '0', '0', '0', '2000005508', '0', '0', '0', '0');
DELETE FROM `db_script_string` WHERE `entry` = 2000005508;
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000005508', 'Залезай в крошшер и побеждай. Картель Трюмных Вод рассчитывает на тебя!', 'Залезай в крошшер и побеждай. Картель Трюмных Вод рассчитывает на тебя!');
-- aura 90366 used for ivent it shouldn't be used on addon
UPDATE `creature_template_addon` SET  `auras` =  '' WHERE `entry` =48526;
-- condition for summon veh = 37179
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 48526 and spell_id = 70015;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('48526', '70015', '1', '0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 66306;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 48526, 70015, 9, 0, 24502, 0, 0, 'Required quest active for spellclick');
DELETE FROM `creature_text` WHERE entry = 37179;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37179, 0, 0, 'Бросай футбомбные мячи в \"Акул\"!', 42, 0, 100, 0, 0, 17466, '\"Буканьер Трюмных Вод\"');
UPDATE `creature_template` SET  `ScriptName` =  'npc_bilgewater_buccaneer' WHERE `entry` =37179;
UPDATE `creature_template` SET  `ScriptName` =  'npc_steamwheedle_shark' WHERE `entry` =37114;
-- wp for sharks
DELETE FROM `waypoint_data` WHERE `id` = 371140;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371140', '1', '-8289.612', '1479.857', '43.79533', '0'), 
('371140', '2', '-8288.619', '1479.970', '43.79533', '5000'), 
('371140', '3', '-8278.678', '1481.103', '43.17033', '5000'), 
('371140', '4', '-8268.736', '1482.235', '42.54533', '5000'), 
('371140', '5', '-8260.878', '1483.131', '42.17003', '5000');
DELETE FROM `waypoint_data` WHERE `id` = 371141;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371141', '1', '-8274.75', '1484.469', '42.92033', '0'), 
('371141', '2', '-8273.75', '1484.46', '42.92033', '5000'), 
('371141', '3', '-8264.75', '1484.381', '42.3981', '5000'), 
('371141', '4', '-8260.942', '1484.347', '42.1601', '10000');
DELETE FROM `waypoint_data` WHERE `id` = 371142;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371142', '1', '-8289.076', '1487.813', '43.92033', '0'), 
('371142', '2', '-8288.08', '1487.72', '43.92033', '5000'), 
('371142', '3', '-8281.107', '1487.07', '43.29533', '5000'), 
('371142', '4', '-8269.154', '1485.957', '42.67033', '5000'), 
('371142', '5', '-8261.186', '1485.215', '42.1481', '5000');
DELETE FROM `waypoint_data` WHERE `id` = 371143;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371143', '1', '-8282.017', '1477.271', '43.29533', '0'), 
('371143', '2', '-8281.041', '1477.49', '43.29533', '5000'), 
('371143', '3', '-8270.32', '1479.907', '42.67033', '5000'), 
('371143', '4', '-8261.549', '1481.885', '42.1481', '5000'), 
('371143', '5', '-8260.705', '1482.075', '42.1481', '5000');
DELETE FROM `waypoint_data` WHERE `id` = 371144;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371144', '1', '-8282.311', '1490.609', '43.54533', '0'), 
('371144', '2', '-8281.33', '1490.41', '43.54533', '5000'), 
('371144', '3', '-8273.486', '1488.824', '42.92033', '5000'), 
('371144', '4', '-8264.662', '1487.04', '42.3981', '5000'), 
('371144', '5', '-8260.743', '1486.248', '42.14829', '5000');
DELETE FROM `waypoint_data` WHERE `id` = 371145;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371145', '1', '-8296.1', '1484.925', '44.29533', '0'), 
('371145', '2', '-8295.1', '1484.91', '44.29533', '5000'), 
('371145', '3', '-8284.1', '1484.749', '43.54533', '5000'), 
('371145', '4', '-8274.1', '1484.603', '42.92033', '5000'), 
('371145', '5', '-8265.1', '1484.471', '42.3981', '5000'), 
('371145', '6', '-8260.942', '1484.41', '42.1481', '5000');
DELETE FROM `waypoint_data` WHERE `id` = 371146;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371146', '1', '-8295.637', '1474.465', '44.17033', '0'), 
('371146', '2', '-8294.66', '1474.68', '44.17033', '5000'), 
('371146', '3', '-8284.895', '1476.818', '43.54533', '5000'), 
('371146', '4', '-8274.152', '1479.171', '42.92033', '5000'), 
('371146', '5', '-8266.34', '1480.882', '42.3981', '5000'), 
('371146', '6', '-8260.713', '1482.114', '42.1481', '5000');
DELETE FROM `waypoint_data` WHERE `id` = 371147;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES 
('371147', '1', '-8295.589', '1493.881', '44.29533', '0'), 
('371147', '2', '-8294.611', '1493.67', '44.29533', '5000'), 
('371147', '3', '-8284.846', '1491.561', '43.67033', '5000'), 
('371147', '4', '-8275.08', '1489.451', '43.04533', '5000'), 
('371147', '5', '-8266.291', '1487.553', '42.5231', '5000'), 
('371147', '6', '-8260.721', '1486.349', '42.16659', '5000');
-- sepll coords. for hack target type.
DELETE FROM `spell_target_position` where id in (69971, 69976, 69977, 69978, 69979, 69980, 69981, 69982);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('69971', '648', '-8288.62', '1479.97', '43.8908', '0'), 
('69976', '648', '-8273.75', '1484.46', '42.9395', '0'),
('69977', '648', '-8288.08', '1487.72', '43.8463', '0'),
('69978', '648', '-8281.04', '1477.49', '43.3046', '0'),
('69979', '648', '-8281.33', '1490.41', '43.4756', '0'),
('69980', '648', '-8295.1',  '1484.91', '44.3231', '0'),
('69981', '648', '-8294.66', '1474.68', '44.2946', '0'),
('69982', '648', '-8294.61', '1493.67', '44.6239', '0');

-- q.24503 auto-accept. Or by npc = 28414. Goal.
UPDATE `quest_template` SET  `RewardReputationMask` =  '1', `QuestGiverPortrait` =  '0' WHERE `Id` =24503;
UPDATE  `quest_template` SET  `PrevQuestId` =  '24502' WHERE  `quest_template`.`Id` =24503;
UPDATE `creature_template` SET  `minlevel` =  '5', `faction_A` =  '2204', `faction_H` =  '2204', `baseattacktime` =  '2000', `rangeattacktime` =  '2000', `unit_flags` =  '8', `unit_flags2` =  '67584', `type_flags` =  '0', `spell1` =  '70051', `VehicleId` =  '582' WHERE `entry` =37213;
-- UPDATE  `creature_template` SET  `VehicleId` =  '579' WHERE  `creature_template`.`entry` =37213;
DELETE FROM `creature_template_addon` WHERE `entry` = 37213;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('37213', '0', '0', '0', '0', '0', '76651');
UPDATE  `creature_template_addon` SET  `bytes1` =  '65536' WHERE  `creature_template_addon`.`entry` =37213;
-- UPDATE  `creature_model_info` SET  `bounding_radius` =  '7.5', `combat_reach` =  '15' WHERE `modelid` =31295;
UPDATE `creature_template` SET  `InhabitType` =  '4' WHERE  `creature_template`.`entry` =37203;

DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 48526 and spell_id = 70015;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('48526', '70015', '1', '0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 70015;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 48526, 70015, 9, 0, 24503, 0, 0, 'Required quest active for spellclick');
UPDATE  `creature_template` SET  `ScriptName` =  'npc_bilgewater_buccaneer_2' WHERE `entry` =37213;
-- 37213 - real npc aura 76651 + cast 69987 
DELETE FROM `conditions` WHERE `SourceEntry` = 70065;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('13', '1', '70065', '0', '0', '31', '0', '3', '37213', '0', '0', '0', '', NULL);

-- q26712. Сначала – в банк
UPDATE  `quest_template` SET  `StartScript` =  '26712' WHERE  `Id` =26712;
DELETE FROM `db_script_string` WHERE `entry` in(2000267110, 2000267111);
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000267110', 'Вытяни из банка как можно больше бабок! Не хочу снова увидеть тебя в том отрепье, что ты обычно носишь. Это крайне важная вечеринка!', 'Вытяни из банка как можно больше бабок! Не хочу снова увидеть тебя в том отрепье, что ты обычно носишь. Это крайне важная вечеринка!'),
('2000267111', 'Эй, тихо! Не видите, здесь $gсам:сама; $N! $gОн:Она; станет $gследующим торговым принцем:следующей торговой принцессой;!', 'Эй, тихо! Не видите, здесь $gсам:сама; $N! $gОн:Она; станет $gследующим торговым принцем:следующей торговой принцессой;!');
DELETE FROM `quest_start_scripts` WHERE `id` = 26712;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
('26712', '0', '0', '0', '0', '2000267110', '0', '0', '0', '0');
UPDATE `quest_template` SET  `Method` =  '2', `CompleteScript` =  '26712' WHERE  `Id` =26712;
DELETE FROM `quest_end_scripts` WHERE `id` = 26712;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('26712', '0', '0', '0', '0', '2000267111', '0', '0', '0', '0');

-- Q14110
UPDATE `quest_template` SET `PrevQuestId` = '26712' WHERE `Id` = 14110;
UPDATE `quest_template` SET RequiredPOI1 = 264967, RequiredPOI2 = 264968, RequiredPOI3 = 264969, RequiredUnkFlag1 = 0, RequiredUnkFlag2 = 0, RequiredUnkFlag3 = 0, RequiredUnkFlag4 = 0 WHERE id = 14110;
UPDATE `creature_template` SET unit_flags=32768, `faction_A` = '2159', `faction_H` = '2159' WHERE  `entry` =35128;
UPDATE `creature_template` SET unit_flags=32768, `faction_A` = '2159', `faction_H` = '2159' WHERE  `entry` =35130;
UPDATE `creature_template` SET unit_flags=32768, `faction_A` = '2159', `faction_H` = '2159' WHERE  `entry` =35126;
