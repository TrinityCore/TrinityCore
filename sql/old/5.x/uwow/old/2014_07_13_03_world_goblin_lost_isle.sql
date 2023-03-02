/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- cosmetic zone
-- spell 74076 by 43359
-- spell 74070 by 43359 
-- spell 74072 by 43359
-- spell 74085 by 43359
UPDATE spell_area SET quest_end = 14245, quest_end_status = 66 WHERE spell = 68421 AND area = 4720; -- END 1024 phase

DELETE FROM `gossip_menu_option` WHERE `option_text` LIKE 'Gonflés à bloc !';
-- ----------------------------------------
-- Q: 24817 A Goblin in Shark's Clothing
-- ----------------------------------------

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38124;
DELETE FROM smart_scripts WHERE entryorguid = 38124;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38124, 0, 0, 0, 47, 0, 100, 0, 24817, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24817'),
(38124, 0, 1, 0, 47, 0, 100, 0, 24946, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24946'),
(38124, 0, 2, 0, 47, 0, 100, 0, 25110, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25110'),
(38124, 0, 3, 0, 47, 0, 100, 0, 25200, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25200'),
(38124, 0, 4, 0, 47, 0, 100, 0, 25204, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25204'),
(38124, 0, 5, 0, 47, 0, 100, 0, 25213, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25213');

UPDATE `quest_template` SET RequiredPOI2 = 0, RequiredUnkFlag2 = 1 WHERE id = 24817;

DELETE FROM `conditions` WHERE SourceEntry = 71648;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 71648, 0, 0, 31, 0, 3, 23837, 0, 0, 0, '', 'Cast - Only - 23837'); -- summon in ocean

DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 38318 and spell_id = 71661;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('38318', '71661', '1', '0');

UPDATE `creature_template` SET `minlevel` = '7', `maxlevel` = '7', `faction_A` = '2204', `faction_H` = '2204', `unit_flags` = '33032', `unit_flags2` = '65536', `spell1` = '71659', `spell2` = '71658', `spell3` = '71660', `VehicleId` = '628', `InhabitType` = '2' WHERE `entry` = 38318;

DELETE FROM `creature_template_addon` WHERE `entry` = 38318;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('38318', '0', '0', '0', '1', '0', '71663');

-- ----------------------------------------
-- Q: 24856 Invasion Imminent!
-- ----------------------------------------

-- ----------------------------------------
-- Q: 24858 Bilgewater Cartel Represent
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredIdCount1` = '10' WHERE `Id` = 24858;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38432;
DELETE FROM smart_scripts WHERE entryorguid = 38432;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38432, 0, 0, 0, 47, 0, 100, 0, 24858, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24858'),
(38432, 0, 1, 0, 47, 0, 100, 0, 24864, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24864'),
(38432, 0, 2, 0, 47, 0, 100, 0, 24897, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24897');

DELETE FROM `creature_text` WHERE entry = 38432;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38432, 0, 0, 'Слышали, наги? У |3-1($N) свои способы вести \"переговоры\"!', 14, 0, 100, 15, 0, 0, 'Мегз Жестекрошшер'),
(38432, 1, 0, 'Надувной пони нравится всем. Это наш лидер продаж после детских разрывных бомб.', 12, 0, 100, 1, 0, 0, 'Мегз Жестекрошшер'),
(38432, 2, 0, 'Этот шлем пигмея введет их в заблуждение – по крайней мере, на какое-то время. Возвращайся в город!', 12, 0, 100, 25, 0, 0, 'Мегз Жестекрошшер');

DELETE FROM `conditions` WHERE SourceEntry = 71857;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 71857, 0, 0, 31, 0, 3, 23837, 0, 0, 0, '', 'Cast - Only - 23837');

-- ----------------------------------------
-- Q: 24859 Naga Hide
-- ----------------------------------------

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38381;
DELETE FROM smart_scripts WHERE entryorguid = 38381;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38381, 0, 0, 0, 47, 0, 100, 0, 24859, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24859');

DELETE FROM `creature_text` WHERE entry = 38381;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38381, 0, 0, 'О твоей доле мы поговорим позже, когда ты вернешься со шкурами. Я думаю, 90 процентов мне и 10 – тебе.', 12, 0, 100, 6, 0, 0, 'Бретт \"Сдачи нет\" Маквид');

-- ----------------------------------------
-- Q: 24864 Irresistible Pool Pony
-- ----------------------------------------

UPDATE `quest_template` SET `Method` = '2' WHERE `Id` = 24864;
UPDATE `creature_template` SET `dynamicflags` = '0', `ScriptName` = 'npc_vashjelan_siren' WHERE `entry` = 38360;
-- 11831 ura 9672

DELETE FROM `npc_spellclick_spells` WHERE npc_entry in (44579, 38412, 44580, 44578) and spell_id = 71917;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('44578', '71917', '2', '0'),
('44579', '71917', '2', '0'),
('38412', '71917', '2', '0'),
('44580', '71917', '2', '0');

UPDATE `creature_template` SET `ScriptName` = 'npc_naga_hatchling' WHERE `entry` in (44579, 38412, 44580, 44578);

-- ----------------------------------------
-- Q: 24868 ISurrender or Else!
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredUnkFlag1` = '1' WHERE `quest_template`.`Id` = 24868;

UPDATE `quest_template` SET `StartScript` = '24868' WHERE `Id` = 24868;
-- [72001]72085->72086->72058 
DELETE FROM `quest_start_scripts` WHERE id = 24868;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('24868', '0', '15', '72001', '1', '0', '0', '0', '0', '0');

DELETE FROM `spell_scripts` WHERE id = 72085;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('72085', '0', '0', '18', '0', '0', '0', '0', '0', '0', '0');
DELETE FROM `conditions` WHERE SourceEntry = 72085;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 72085, 0, 0, 31, 0, 3, 44588, 0, 0, 0, '', 'Cast - Only - 44588'),
(13, 1, 72085, 0, 1, 31, 0, 3, 44589, 0, 0, 0, '', 'Cast - Only - 44589'),
(13, 1, 72085, 0, 2, 31, 0, 3, 44590, 0, 0, 0, '', 'Cast - Only - 44590'),
(13, 1, 72085, 0, 3, 31, 0, 3, 44591, 0, 0, 0, '', 'Cast - Only - 44591');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38455;
DELETE FROM smart_scripts WHERE entryorguid = 38455;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38455, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 18, 20, 0, 0, 0, 0, 0, 0, 'at summon'),
(38455, 0, 1, 0, 60, 0, 100, 1, 10000, 10000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 18, 20, 0, 0, 0, 0, 0, 0, 'at summon');

DELETE FROM `creature_text` WHERE entry = 38455;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38455, 0, 0, '$N, эти проказники у меня на крючке. Наги не нападут, пока у нас их потомство.', 12, 0, 100, 1, 0, 0, 'Туз'),
(38455, 1, 0, 'Ты $gготов:готова; принудить к сдаче их вожака? Ну, тогда пошли.', 12, 0, 100, 1, 0, 0, 'Туз'),
(38455, 2, 0, 'Когда разберемся с вашей капитуляцией, устроим особую распродажу – только для наг. На большинство товаров – скидка в тридцать процентов. Калдорайские артефакты по особой цене! Предложение действует только сегодня!', 14, 0, 100, 5, 0, 0, 'Туз'),
(38455, 3, 0, 'Мы знаем, что вы собирались на нас напасть. Так что сами во всем виноваты.', 14, 0, 100, 5, 0, 0, 'Туз'),
(38455, 4, 0, 'Ну, предводитель наг, выходи! $N и картель Трюмных Вод приказывают тебе сдаться!', 14, 0, 100, 5, 0, 0, 'Туз'),
(38455, 5, 0, 'Э-э, чувак, что-то мне это не нравится. Я сваливаю!', 12, 0, 100, 5, 0, 0, 'Туз to Безликий из глубин');

UPDATE `creature_template` SET `unit_flags` = '33024', `InhabitType` = '7', `ScriptName` = 'npc_faceless_of_the_deep' WHERE `entry` = 38448;
UPDATE `creature` SET `MovementType` = '0' WHERE `id` = 38448;
UPDATE `creature_template_addon` SET `auras` = '72126 71910' WHERE `entry` = 38448;

UPDATE `creature_template` SET `flags_extra` = '0' WHERE `entry` = 38450;
UPDATE `creature_template` SET `flags_extra` = '128' WHERE `entry` = 24288;

DELETE FROM `creature_text` WHERE entry =38448;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38448, 0, 0, 'Кто осмеливается?!', 14, 0, 100, 15, 0, 15136, 'Безликий из глубин'),
(38448, 1, 0, 'Малыши-гоблины? Я помню те дни, когда вашей расы еще не существовало!', 14, 0, 100, 1, 0, 15139, 'Безликий из глубин'),
(38448, 2, 0, 'Меня не страшат ни твои угрозы, ни эти наги. Приготовься навсегда покинуть этот мир.', 14, 0, 100, 25, 0, 15140, 'Безликий из глубин'),
(38448, 3, 0, 'А теперь, $N, ты умрешь!', 14, 0, 100, 0, 0, 15140, 'Безликий из глубин');

-- --------------------------------
--          PHASE 4096
-- --------------------------------

UPDATE spell_area SET quest_end = 24868, quest_end_status = 64 WHERE spell = 68750 AND area = 4720; -- END 2048 phase
DELETE FROM spell_area WHERE spell = 72157 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('72157', '4720', '24868', '24929', '0', '0', '2', '1', '64', '64');

-- ----------------------------------------
-- Q: 24897 Get Back to Town
-- ----------------------------------------

DELETE FROM spell_area WHERE spell = 66987 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('66987', '4720', '24897', '24925', '0', '0', '2', '1', '74', '74');

UPDATE `creature_template` SET `flags_extra` = '128' WHERE `entry` = 24110;
UPDATE `creature` SET `MovementType` = '0' WHERE `id` = 38526;

-- ----------------------------------------
-- Q: 24901 Town-In-A-Box: Under Attack
-- ----------------------------------------

UPDATE `creature_template` SET `npcflag` = '16777216', `unit_flags2` = '67584', `dynamicflags` = '0', `spell1` = '72206', `VehicleId` = '640', `faction_A` = '35', `faction_H` = '35' WHERE `entry` = 38526; -- faction old 2159

DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 38526;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('38526', '72240', '1', '0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 72240;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 38526, 72240, 9, 0, 24901, 0, 0, 'Required quest active for spellclick');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38387;
DELETE FROM smart_scripts WHERE entryorguid = 38387;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38387, 0, 0, 0, 47, 0, 100, 0, 24901, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24901'),
(38387, 0, 1, 0, 47, 0, 100, 0, 24924, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24924'),
(38387, 0, 2, 0, 47, 0, 100, 0, 24940, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24940'),
(38387, 0, 3, 0, 47, 0, 100, 0, 25058, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25058'),
(38387, 0, 4, 0, 47, 0, 100, 0, 25066, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25066'),
(38387, 0, 5, 0, 62, 0, 100, 0, 11146, 0, 0, 0, 11, 73431, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At gossip select'),
(38387, 0, 6, 0, 47, 0, 100, 0, 25098, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25098'),
(38387, 0, 7, 0, 47, 0, 100, 0, 25244, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25244'),
(38387, 0, 8, 0, 47, 0, 100, 0, 25251, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25251'),
(38387, 0, 9, 0, 62, 0, 100, 0, 11146, 1, 0, 0, 11, 74924, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At gossip select.EXIT.');

DELETE FROM `creature_text` WHERE entry =38387;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38387, 0, 0, '$N, становись за один из наших баллистических уничтожителей и бей пигмеев!', 14, 0, 100, 25, 0, 18259, 'Хамми Кофельнагель'),
(38387, 1, 0, 'Тебе придется сразиться с ними, $N. Иззи можно найти сразу за деревней.', 12, 0, 100, 273, 0, 0, 'Хамми Кофельнагель'),
(38387, 2, 0, 'Эти зомби не отличаются быстротой. Бежать необязательно. Смотри, чтобы они не съели твои мозги, $N!', 12, 0, 100, 1, 0, 0, 'Хамми Кофельнагель'),
(38387, 3, 0, 'Гоблинские гранаты против гномьих наземных мин. Покажи им, кто тут самый главный, $N!', 12, 0, 100, 1, 0, 0, 'Хамми Кофельнагель'),
(38387, 4, 0, 'Я забыла... Тебя учили летать на Кезане?', 12, 0, 100, 6, 0, 0, 'Хамми Кофельнагель'),
(38387, 5, 0, 'Не медли, $N. Кажется, Тралл уже знает, где находятся наши.', 12, 0, 100, 273, 0, 0, 'Хамми Кофельнагель'),
(38387, 6, 0, 'Девочка, она увела твоего милого! Ты знаешь, что нужно делать в таких случаях!', 12, 0, 100, 273, 0, 0, 'Хамми Кофельнагель'),
(38387, 7, 0, '$N, бери свою идеальную футбомбную униформу и мчи к причалу. Помоги Траллу справиться с торговым принцем!', 12, 0, 100, 0, 0, 0, 'Хамми Кофельнагель');

UPDATE `creature_template` SET  `unit_flags` = `unit_flags` | 0x4 WHERE `entry` in (38513, 38515, 38514, 38516, 38738, 38517, 38518, 38120, 36600, 38124, 38516, 36471, 44473, 42473, 38387, 38511);
UPDATE `creature_template` SET  `unit_flags` = `unit_flags` & ~0x300 WHERE `entry` in (38513, 38515, 38514, 38516, 38738, 38517, 38518, 38120, 36600, 38124, 38516, 36471, 44473, 42473, 38387, 38511);


UPDATE `creature_template` SET `flags_extra` = '66', `ScriptName` = 'npc_omlot_warrior' WHERE `entry` = 38531;
SET @id = 0;
SET @entry = 38531;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, '780.3081', '1948.384', '102.4497', NULL), 
(@entry, @id := @id+ 1, '780.6337', '1949.33', '102.4497', NULL),
(@entry, @id := @id+ 1, 790.5313, 1992.896, 98.23127, NULL),
(@entry, @id := @id+ 1, 802.7813, 2014.576, 97.60346, NULL),
(@entry, @id := @id+ 1, 822.5989, 2045.604, 96.09377, NULL),
(@entry, @id := @id+ 1, 844.243, 2068.012, 93.42007, NULL),
(@entry, @id := @id+ 1, 851.533, 2095.686, 88.25676, NULL),
(@entry, @id := @id+ 1, 866.2795, 2121.394, 80.82765, NULL),
(@entry, @id := @id+ 1, 868.9774, 2137.936, 75.4072, NULL),
(@entry, @id := @id+ 1, 884.8559, 2147.109, 71.69846, NULL),
(@entry, @id := @id+ 1, 901.3958, 2162.396, 65.74876, NULL),
(@entry, @id := @id+ 1, 908.0938, 2180.066, 57.25764, NULL),
(@entry, @id := @id+ 1, 907.2864, 2202.446, 43.59169, NULL),
(@entry, @id := @id+ 1, 916.2778, 2227.62, 27.9863, NULL),
(@entry, @id := @id+ 1, 911.3195, 2247.063, 20.18579, NULL),
(@entry, @id := @id+ 1, 918.8386, 2272.995, 14.70055, NULL),
(@entry, @id := @id+ 1, 912.7743, 2285.163, 12.82682, NULL),
(@entry, @id := @id+ 1, 920.1094, 2298.903, 10.39059, NULL),
(@entry, @id := @id+ 1, 905.1389, 2310.08, 8.279609, NULL),
(@entry, @id := @id+ 1, 893.9063, 2315.606, 7.613342, NULL),
(@entry, @id := @id+ 1, 888.7136, 2325.795, 7.254128, NULL),
(@entry, @id := @id+ 1, 896.5521, 2333.224, 5.74977, NULL),
(@entry, @id := @id+ 1, 905.0018, 2332.984, 5.042526, NULL),
(@entry, @id := @id+ 1, 906.7379, 2330.615, 5.055651, NULL),
(@entry, @id := @id+ 1, 906.7379, 2330.615, 5.055651, NULL),
-- part 2
(@entry, @id := @id+ 1, 788.2809, 1974.198, 100.5009, NULL),
(@entry, @id := @id+ 1, 788.4028, 1975.191, 100.5009, NULL),
(@entry, @id := @id+ 1, 789.7327, 1990.035, 98.49607, NULL),
(@entry, @id := @id+ 1, 795.1441, 2006.615, 97.68016, NULL),
(@entry, @id := @id+ 1, 806.0643, 2018.854, 97.70579, NULL),
(@entry, @id := @id+ 1, 817.4375, 2035.398, 97.08675, NULL),
(@entry, @id := @id+ 1, 825.1337, 2049.995, 96.02341, NULL),
(@entry, @id := @id+ 1, 844.3108, 2068.193, 93.39364, NULL),
(@entry, @id := @id+ 1, 847.868, 2090.849, 89.60906, NULL),
(@entry, @id := @id+ 1, 857.7708, 2106.714, 85.29278, NULL),
(@entry, @id := @id+ 1, 868.2656, 2124.417, 79.89479, NULL),
(@entry, @id := @id+ 1, 885.0608, 2144.028, 72.32169, NULL),
(@entry, @id := @id+ 1, 899.632, 2158.163, 67.04545, NULL),
(@entry, @id := @id+ 1, 907.4896, 2171.793, 61.32259, NULL),
(@entry, @id := @id+ 1, 911.257, 2200.137, 44.66008, NULL),
(@entry, @id := @id+ 1, 913.9236, 2233.153, 25.48765, NULL),
(@entry, @id := @id+ 1, 916.9479, 2251.894, 18.91982, NULL),
(@entry, @id := @id+ 1, 913.8472, 2270.724, 14.85658, NULL),
(@entry, @id := @id+ 1, 916.2604, 2290.413, 11.81221, NULL),
(@entry, @id := @id+ 1, 911.7587, 2297.226, 10.99505, NULL),
(@entry, @id := @id+ 1, 916.6354, 2307.939, 8.899861, NULL),
(@entry, @id := @id+ 1, 922.7691, 2319.675, 6.677383, NULL),
(@entry, @id := @id+ 1, 929.0573, 2328.198, 5.057785, NULL),
(@entry, @id := @id+ 1, 916.6545, 2346.238, 5.074251, NULL),
(@entry, @id := @id+ 1, 916.6545, 2346.238, 5.074251, NULL),
-- part 3
(@entry, @id := @id+ 1, 787.7698, 1966.073, 100.9721, NULL),
(@entry, @id := @id+ 1, 787.9948, 1967.047, 100.9721, NULL),
(@entry, @id := @id+ 1, 791.7518, 1981.601, 99.50809, NULL),
(@entry, @id := @id+ 1, 790.243, 1997.535, 98.0176, NULL),
(@entry, @id := @id+ 1, 800.9445, 2012.75, 97.43696, NULL),
(@entry, @id := @id+ 1, 813.5018, 2029.455, 97.38898, NULL),
(@entry, @id := @id+ 1, 824.4114, 2048.495, 96.03947, NULL),
(@entry, @id := @id+ 1, 842.3073, 2065.019, 93.84312, NULL),
(@entry, @id := @id+ 1, 846.6389, 2086.153, 90.62801, NULL),
(@entry, @id := @id+ 1, 855.1458, 2109.255, 85.27999, NULL),
(@entry, @id := @id+ 1, 867.3802, 2125.566, 79.65959, NULL),
(@entry, @id := @id+ 1, 890.2726, 2150.884, 69.9869, NULL),
(@entry, @id := @id+ 1, 905.868, 2172.104, 61.20406, NULL),
(@entry, @id := @id+ 1, 910.3281, 2196.372, 47.09286, NULL),
(@entry, @id := @id+ 1, 909.7396, 2219.04, 33.42166, NULL),
(@entry, @id := @id+ 1, 915.9358, 2228.467, 27.6009, NULL),
(@entry, @id := @id+ 1, 912.2483, 2246.139, 20.4588, NULL),
(@entry, @id := @id+ 1, 917.2031, 2254.613, 18.27465, NULL),
(@entry, @id := @id+ 1, 915.0729, 2266.892, 15.85093, NULL),
(@entry, @id := @id+ 1, 922.6441, 2276.743, 14.08816, NULL),
(@entry, @id := @id+ 1, 911.8698, 2284.948, 12.81333, NULL),
(@entry, @id := @id+ 1, 917.9358, 2298.538, 10.45248, NULL),
(@entry, @id := @id+ 1, 917.2413, 2306.946, 9.069425, NULL),
(@entry, @id := @id+ 1, 927.8906, 2320.806, 6.370274, NULL),
(@entry, @id := @id+ 1, 930.092, 2330.524, 5.022035, NULL),
(@entry, @id := @id+ 1, 926.342, 2337.524, 5.022688, NULL),
(@entry, @id := @id+ 1, 926.8055, 2343.195, 5.518414, NULL),
(@entry, @id := @id+ 1, 926.8055, 2343.195, 5.518414, NULL);


-- ----------------------------------------
-- Q: 24925 Free the Captives
-- ----------------------------------------
UPDATE `creature` SET `phaseMask` = `phaseMask` | 8192  WHERE `id` = 38647 AND phaseMask = 4096;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38647;
DELETE FROM smart_scripts WHERE entryorguid = 38647;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38647, 0, 0, 0, 47, 0, 100, 0, 24925, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24925'),
(38647, 0, 1, 0, 47, 0, 100, 0, 24937, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24937');

DELETE FROM `creature_text` WHERE entry =38647;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38647, 0, 0, '$N, давай внутрь и спасай всех!', 12, 0, 100, 5, 0, 0, 'Иззи'),
(38647, 1, 0, 'Гоблины-зомби? Надо предупредить жителей Городка-из-табакерки!', 12, 0, 100, 6, 0, 0, 'Иззи'),
(38647, 2, 0, 'Док! Помоги мне!', 14, 0, 100, 0, 0, 0, 'Иззи'),
(38647, 3, 0, 'Ай!', 14, 0, 100, 0, 0, 0, 'Иззи'),
(38647, 4, 0, 'Не позволяй ему так с собой обращаться! Вырви его сердце, девочка!', 12, 0, 100, 274, 0, 0, 'Иззи');

UPDATE `creature_template_addon` SET `mount` = '1244' WHERE `creature_template_addon`.`entry` = 38574;
DELETE FROM `creature` WHERE `id` = 38644;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38644;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38644;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('38644', '0', '0', '0', '60', '0', '100', '0', '1000', '1000', '600000', '600000', '11', '12550', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Lightning Shield on self every 10 min'), 
('38644', '1', '0', '0', '60', '0', '100', '0', '1000', '1000', '8000', '8000', '11', '13281', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', 'Earth Shock');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 38643;
UPDATE `creature_template` SET `dynamicflags` = '0', `AIName` = '', `ScriptName` = 'npc_goblin_captive' WHERE `entry` = 38643;
UPDATE `creature` SET `MovementType` = '0' WHERE id  = 38643;

UPDATE `creature_template_addon` SET `auras` = '72522' WHERE `entry` = 38643;

DELETE FROM `creature_text` WHERE entry =38643;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38643, 0, 0, 'Остальных они отвели в жерло вулкана. Одних собираются превратить в зомби, других – принести в жертву их черепашьему богу Вулканоту!', 12, 0, 100, 5, 0, 0, 'Пленный гоблин to Шаман Умлота'),
(38643, 0, 1, 'Я свободен! Я обязан тебе жизнью!', 12, 0, 100, 4, 0, 0, 'Пленный гоблин to Шаман Умлота'),
(38643, 0, 2, 'А я-то думал, что мне крышка!', 12, 0, 100, 1, 0, 0, 'Пленный гоблин to Шаман Умлота'),
(38643, 0, 3, 'Я даже не знаю, как тебя отблагодарить!', 12, 0, 100, 18, 0, 0, 'Пленный гоблин to Шаман Умлота'),
(38643, 0, 4, 'Я чувствовал, как жизнь уходит от меня.', 12, 0, 100, 1, 0, 0, 'Пленный гоблин to Шаман Умлота'),
(38643, 0, 5, 'Нужно убираться отсюда, пока меня снова не поймали!', 12, 0, 100, 5, 0, 0, 'Пленный гоблин to Шаман Умлота'),
(38643, 0, 6, 'Они пытались превратить меня в зомби!', 12, 0, 100, 5, 0, 0, 'Пленный гоблин to Шаман Умлота');

SET @id = 0;
SET @entry = 38643;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 741.2416, 1755.978, 114.5907, NULL),
(@entry, @id := @id+ 1, 737.2416, 1758.978, 113.8407, NULL),
(@entry, @id := @id+ 1, 734.7416, 1760.728, 113.3407, NULL),
(@entry, @id := @id+ 1, 732.4916, 1762.478, 112.5907, NULL),
(@entry, @id := @id+ 1, 729.9916, 1764.228, 111.8407, NULL),
(@entry, @id := @id+ 1, 726.9916, 1766.478, 110.8407, NULL),
(@entry, @id := @id+ 1, 724.4916, 1768.228, 110.0907, NULL),
(@entry, @id := @id+ 1, 722.9916, 1768.228, 109.8407, NULL),
(@entry, @id := @id+ 1, 721.9916, 1769.728, 108.5907, NULL),
(@entry, @id := @id+ 1, 720.9916, 1771.728, 109.3407, NULL),
(@entry, @id := @id+ 1, 717.2416, 1775.978, 109.0907, NULL);

-- ----------------------------------------
-- Q: 24929 Send a Message
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredUnkFlag1` = '1' WHERE `Id` = 24929;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38696;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38696;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('38696', '0', '0', '0', '0', '0', '100', '0', '1000', '1000', '30000', '30000', '11', '75942', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Voodoo Illusion');

-- --------------------------------
--          PHASE 8192
-- --------------------------------

DELETE FROM spell_area WHERE spell = 72676 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('72676', '4720', '24929', '24958', '0', '0', '2', '1', '64', '66');


-- ----------------------------------------
-- Q: 24942 Zombies vs. Super Booster Rocket Boots
-- ----------------------------------------
UPDATE `quest_template` SET `Method` = '2' WHERE `Id` = 24942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38738;
DELETE FROM smart_scripts WHERE entryorguid = 38738;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38738, 0, 0, 0, 47, 0, 100, 0, 24942, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24942'),
(38738, 0, 1, 0, 47, 0, 100, 0, 24952, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24952'),
(38738, 0, 2, 0, 47, 0, 100, 0, 25201, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25201');

DELETE FROM `creature_text` WHERE entry =38738;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38738, 0, 0, 'Иди и покажи этим зомби, из какого теста сделаны \"Буканьеры Трюмных Вод!\"', 12, 0, 100, 25, 0, 0, 'Тренер Проверяк'),
(38738, 1, 0, 'Тебе понравится!', 12, 0, 100, 273, 0, 0, 'Тренер Проверяк'),
(38738, 2, 0, 'Мы сделаем тебе лучшую футбомбную униформу, $gсынок:дочка;. Но для начала нам нужны запчасти. Много запчастей.', 12, 0, 100, 25, 0, 0, 'Тренер Проверяк');

-- spell: 72891 -> 72889 summon 38802
DELETE FROM `spell_scripts` WHERE id = 72891;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) 
VALUES ('72891', '0', '0', '15', '72889', '1', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `unit_flags` = '520', `unit_flags2` = '67584', `VehicleId` = '653', `ScriptName` = 'npc_super_booster_rocket_boots' WHERE `entry` = 38802;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 38802;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES ('38802', '72887', '1', '0');
-- 72886
DELETE FROM `conditions` WHERE SourceEntry = 72886;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 72886, 0, 0, 31, 0, 3, 38753, 0, 0, 0, '', 'Cast target - Zombies');
UPDATE `creature_template` SET `KillCredit1` = '38807' WHERE `entry` = 38753;

DELETE FROM `spell_area` WHERE `spell` = 72885;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('72885', '4720', '24942', '0', '0', '0', '2', '0', '10', '0');
-- ----------------------------------------
-- Q: 24945 Three Little Pygmies
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredUnkFlag1` = '1', `RequiredUnkFlag2` = '1', `RequiredUnkFlag3` = '1' WHERE `Id` = 24945;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36471;
DELETE FROM smart_scripts WHERE entryorguid = 36471;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36471, 0, 0, 0, 47, 0, 100, 0, 24945, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24945');

DELETE FROM `creature_text` WHERE entry =36471;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36471, 0, 0, 'Хобарт рядом, $gсэр:мэм;.', 12, 0, 100, 25, 0, 0, 'Штейгер Промоках'),
(36471, 1, 0, 'Запомни, тебе нужны лидеры пигмеев: Гаал, Мальмо и Телох.', 12, 0, 100, 1, 0, 1473, 'Штейгер Промоках');

-- ----------------------------------------
-- Q: 24952 Rocket Boot Boost
-- ----------------------------------------

UPDATE `quest_template` SET `StartScript` = '0' WHERE `Id` = 24952;
DELETE FROM `quest_start_scripts` WHERE `id` = 58;

DELETE FROM `spell_target_position` WHERE id = 72971;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('72971', '648', '1481.15', '1269.77', '106.779', '0');

-- Hack. Focus Spell.
UPDATE `gameobject_template` SET `type` = '8', `data0` = '1648', `data1` = '100', `data3` = '0' WHERE `entry` = 202330;

-- ----------------------------------------
-- Q: 24954 Children of a Turtle God
-- ----------------------------------------

-- ----------------------------------------
-- Q: 24958 Volcanoth!
-- ----------------------------------------

UPDATE `quest_template` SET `StartScript` = '0' WHERE `Id` = 24958;
DELETE FROM `quest_start_scripts` WHERE `id` = 59;

DELETE FROM `creature_template_addon` WHERE `entry` = 38855;
DELETE FROM `creature_addon` WHERE guid in (select guid from creature WHERE id = 38855);
INSERT INTO `creature_addon` (`guid`, `bytes2`, auras) SELECT guid, 1, '29266 65734' FROM creature where id = 38855 AND phaseMask = 16384;
UPDATE `creature` SET `MovementType` = '0' WHERE `id` = 38855;
UPDATE `creature_template` SET `unit_flags` = '32772', `dynamicflags` = '0', `AIName`='SmartAI' WHERE `entry` = 38855;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38855;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('38855', '0', '0', '0', '0', '0', '100', '0', '1000', '1000', '10000', '10000', '11', '73097', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', 'Volcanic Breath');

-- --------------------------------
--          PHASE 16384
-- --------------------------------

DELETE FROM spell_area WHERE spell = 73065 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('73065', '4720', '24958', '25184', '0', '0', '2', '1', '66', '66');
DELETE FROM `phase_definitions` WHERE zoneId = 4720 AND entry = 2;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `wmAreaId`, `flags`, `comment`) VALUES 
('4720', '2', '0', '183', '659', '682', '0', 'phase 16xx spell 73065');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND SourceGroup = 4720 AND SourceEntry = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(23, 4720, 2, 0, 0, 28, 0, 24958, 0, 0, 0, 0, '', NULL), -- CONDITION_QUEST_COMPLETE 
(23, 4720, 2, 0, 1, 8, 0, 24958, 0, 0, 0, 0, '', NULL); -- CONDITION_QUESTREWARDED
-- (23, 4720, 1, 0, 2, 14, 0, 14466, 0, 0, 0, 0, '', NULL); -- CONDITION_QUEST_NONE for remove at get quest

-- Correction for first terrain.
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND SourceGroup = 4720 AND SourceEntry = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(23, 4720, 1, 0, 0, 28, 0, 14245, 0, 0, 0, 0, '', NULL), -- CONDITION_QUEST_COMPLETE 
(23, 4720, 1, 0, 1, 8, 0, 14245, 0, 0, 0, 0, '', NULL), -- CONDITION_QUESTREWARDED
(23, 4720, 1, 0, 0, 28, 0, 24958, 0, 0, 1, 0, '', NULL); -- CONDITION_QUEST_COMPLETE 

DELETE FROM `vehicle_template_accessory` WHERE EntryOrAura = 38929;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('38929', '38928', '0', '0', '', '8', '0');
UPDATE `creature_template` SET `VehicleId` = '658' WHERE `entry` = 38929;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 38929;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('38929', '46598', '1', '0');
UPDATE `creature_template_addon` SET `auras` = '73116' WHERE `creature_template_addon`.`entry` = 38929;

UPDATE`creature_template` SET `ScriptName` = 'npc_sassy_hardwrench' WHERE `entry` = 38928;

DELETE FROM `creature_text` WHERE entry =38928;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38928, 0, 0, '$N, давай! Иди сюда!', 14, 0, 100, 0, 0, 0, 'Хамми Кофельнагель');

DELETE FROM `spell_target_position` WHERE id = 73135;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('73135', '648', '1580.93', '2720.48', '83.2326', '0');

-- 73137
UPDATE `creature_template` SET `minlevel` = '10', `maxlevel` = '10', `faction_A` = '2204', `faction_H` = '2204', `unit_flags` = '8', `unit_flags2` = '67584', `VehicleId` = '657', `InhabitType` = '4', `ScriptName` = 'npc_flying_bomber' WHERE `entry` = 38918;
DELETE FROM `creature_template_addon` WHERE entry = 38918;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('38918', '0', '0', '0', '0', '0', '73149');
DELETE FROM `vehicle_template_accessory` WHERE EntryOrAura = 38918;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('38918', '38869', '0', '1', '', '8', '0');
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 38918;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('38918', '73137', '1', '0'); -- 73137

UPDATE `creature_template` SET `minlevel` = '10', `maxlevel` = '10', `faction_A` = '2204', `faction_H` = '2204' WHERE `entry` = 38869;
DELETE FROM `creature_text` WHERE entry =38869;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38869, 0, 0, 'Держись, $N! Мы должны выбраться отсюда! НЕМЕДЛЕННО!', 14, 0, 100, 0, 0, 0, 'Хамми Кофельнагель'),
(38869, 1, 0, 'ОСТОРОЖНО! СЗАДИ!!!', 14, 0, 100, 0, 0, 0, 'Хамми Кофельнагель'),
(38869, 2, 0, 'МЫ ГОРИМ!', 14, 0, 100, 0, 0, 23723, 'Хамми Кофельнагель'),
(38869, 3, 0, 'ЙО-ХОООООООО!!!', 14, 0, 100, 0, 0, 23723, 'Хамми Кофельнагель'),
(38869, 4, 0, 'Сейчас мы подходим к Городку-из-табакерки...', 14, 0, 100, 0, 0, 23723, 'Хамми Кофельнагель'),
(38869, 5, 0, 'О нет! Где все? Я же высадила их здесь!', 14, 0, 100, 0, 0, 23723, 'Хамми Кофельнагель'),
(38869, 6, 0, 'Залезай на заднее сиденье. Уходим отсюда. Я знаю, где сейчас твои дружки-орки!', 14, 0, 100, 0, 0, 23725, 'Хамми Кофельнагель');

SET @id = 0;
SET @entry = 38918;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 1151.068, 1115.432, 129.643, NULL),
(@entry, @id := @id+ 1, 1135.733, 1140.052, 142.9035, NULL),
(@entry, @id := @id+ 1, 1099.583, 1166.042, 160.9143, NULL),
(@entry, @id := @id+ 1, 1035.833, 1199.629, 140.9983, NULL),
(@entry, @id := @id+ 1, 985.6024, 1262.278, 123.749, NULL),
(@entry, @id := @id+ 1, 993.0347, 1328.351, 114.8601, NULL),
(@entry, @id := @id+ 1, 1028.523, 1418.127, 106.6932, NULL),
(@entry, @id := @id+ 1, 1012.313, 1533.017, 129.8396, NULL),
(@entry, @id := @id+ 1, 922.4358, 1584.993, 168.4136, NULL),
(@entry, @id := @id+ 1, 798.5573, 1588.155, 174.2195, NULL),
(@entry, @id := @id+ 1, 737.9097, 1636.477, 142.386, NULL),
(@entry, @id := @id+ 1, 721.8958, 1756.576, 120.6636, NULL),
(@entry, @id := @id+ 1, 763.0087, 1888.224, 119.608, NULL),
(@entry, @id := @id+ 1, 808.3715, 2035.257, 112.9135, NULL),
(@entry, @id := @id+ 1, 894.9583, 2161.132, 93.30235, NULL),
(@entry, @id := @id+ 1, 940.9375, 2306.293, 39.80235, NULL),
(@entry, @id := @id+ 1, 938.3368, 2458.16, 23.83012, NULL),
(@entry, @id := @id+ 1, 868.5504, 2537.892, 11.08012, NULL),
(@entry, @id := @id+ 1, 771.257, 2526.758, 11.08012, NULL),
(@entry, @id := @id+ 1, 746.3073, 2438.623, 11.08012, NULL),
(@entry, @id := @id+ 1, 807.4288, 2367.575, 30.66352, NULL),
(@entry, @id := @id+ 1, 930.7847, 2316.547, 45.20028, NULL),
(@entry, @id := @id+ 1, 1235.776, 2192.42, 93.26237, NULL),
(@entry, @id := @id+ 1, 1534.63, 2529.204, 125.1861, NULL),
(@entry, @id := @id+ 1, 1584.891, 2684.934, 95.60267, NULL);

-- ----------------------------------------
-- Q: 25024 Repel the Paratroopers
-- ----------------------------------------

UPDATE `creature_template` SET `InhabitType` = `InhabitType` | 4 WHERE `entry` in (39039, 36719);
UPDATE `creature_template_addon` SET `auras` = '' WHERE `creature_template_addon`.`entry` = 39044;

-- ----------------------------------------
-- Q: 25093 The Heads of the SI:7
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredUnkFlag1` = '1', `RequiredUnkFlag2` = '1', `RequiredUnkFlag3` = '1' WHERE `Id` = 25093;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39065;
DELETE FROM smart_scripts WHERE entryorguid = 39065;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39065, 0, 0, 0, 47, 0, 100, 0, 25093, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25093'),
(39065, 0, 1, 0, 50, 0, 100, 0, 25093, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At finish q: 25093');

DELETE FROM `creature_text` WHERE entry =39065;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39065, 0, 0, 'Отомсти за наших, $N.', 12, 0, 100, 5, 0, 0, 'Аггра'),
(39065, 1, 0, 'Ты оказываешь нам большую услугу. Благодарю тебя, $N.', 12, 0, 100, 1, 0, 0, 'Аггра');

-- ----------------------------------------
-- Q: 25058 Mine Disposal, the Goblin Way
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredIdCount1` = '10' WHERE `Id` = 25058;

-- ----------------------------------------
-- Q: 25066 The Pride of Kezan
-- ----------------------------------------
UPDATE `creature_template` SET `gossip_menu_id` = '11146' WHERE `entry` = 38387;

DELETE FROM `gossip_menu` WHERE entry = 11146;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(11146, 15516); -- 38387

DELETE FROM `gossip_menu_option` WHERE `menu_id`=11146;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(11146, 0, 0, 'Подними меня в небо, Хамми!', 1, 2, 0, 0, 0, 0, '');
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 15 AND SourceGroup = 11146;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('15', '11146', '0', '0', '0', '9', '0', '25066', '0', '0', '0', '0', '', NULL);

-- 39074
UPDATE `creature_template` SET `minlevel` = '10', `maxlevel` = '10', `faction_A` = '2204', `faction_H` = '2204', `VehicleId` = '669', `spell1` = '73456', `spell2` = '73477', `InhabitType` = '7', `speed_walk` = '15', `speed_run` = '15', `speed_fly` = '4.5' WHERE `entry` = 39074;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 39074;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('39074', '73427', '1', '0'); -- 73427

DELETE FROM `conditions` WHERE SourceEntry = 73477;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 73477, 0, 0, 31, 0, 3, 39039, 0, 0, 0, '', 'Cast target - Gnomeregan Stealth Fighter');

-- ----------------------------------------
-- Q: 25100 Let's Ride
-- ----------------------------------------

DELETE FROM `quest_start_scripts` WHERE `id` = 61;
UPDATE `quest_template` SET `StartScript` = '25100' WHERE `Id` = 25100;
DELETE FROM `quest_start_scripts` WHERE id = 25100;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('25100', '0', '15', '73532', '2', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39066;
DELETE FROM smart_scripts WHERE entryorguid = 39066;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39066, 0, 0, 0, 47, 0, 100, 0, 25100, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25100');

DELETE FROM `creature_text` WHERE entry =39066;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39066, 0, 0, 'С нами наш маленький друг. Мне жаль дворфов – ведь у гоблина есть его газонокосилка!', 14, 1, 100, 11, 0, 0, 'Килаг Жутеклык'),
(39066, 1, 0, 'Держите строй!', 14, 1, 100, 5, 0, 0, 'Килаг Жутеклык'),
(39066, 2, 0, 'Тралл Холл!', 14, 1, 100, 15, 0, 0, 'Килаг Жутеклык'),
(39066, 3, 0, 'Вперед, Бастия! Отнеси |3-3($N) к Небесному водопаду и исправительной шахте.', 12, 0, 100, 1, 0, 0, 'Килаг Жутеклык');

-- vehicle 73532 npc = 39152 0xF15098F000068C73 by 73531 
UPDATE `creature_template` SET `minlevel` = '13', `maxlevel` = '13', `faction_A` = '2204', `faction_H` = '2204', `VehicleId` = '530', `ScriptName` = 'npc_bastia' WHERE `entry` = 39152;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 39074;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('39152', '73531', '1', '0'); -- 73427

SET @id = 0;
SET @entry = 39152;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 1714.887, 2841.918, 17.80678, NULL),
(@entry, @id := @id+ 1, 1715.491, 2825.375, 27.50569, NULL),
(@entry, @id := @id+ 1, 1713.401, 2812.724, 33.05553, NULL),
(@entry, @id := @id+ 1, 1707.38, 2790.811, 38.42721, NULL),
(@entry, @id := @id+ 1, 1691.804, 2775.447, 47.07444, NULL),
(@entry, @id := @id+ 1, 1677.771, 2763.518, 58.11836, NULL),
(@entry, @id := @id+ 1, 1662.953, 2751.408, 67.96738, NULL),
(@entry, @id := @id+ 1, 1650.644, 2743.627, 73.39718, NULL),
(@entry, @id := @id+ 1, 1634.74, 2733.807, 78.37968, NULL),
(@entry, @id := @id+ 1, 1618.495, 2724.411, 81.52821, NULL),
(@entry, @id := @id+ 1, 1599.793, 2717.84, 82.99432, NULL),
(@entry, @id := @id+ 1, 1572.321, 2711.193, 84.76134, NULL),
(@entry, @id := @id+ 1, 1565.411, 2700.459, 87.49076, NULL),
(@entry, @id := @id+ 1, 1564.866, 2683.269, 91.48758, NULL),
(@entry, @id := @id+ 1, 1566.085, 2668.811, 93.96507, NULL),
(@entry, @id := @id+ 1, 1575.575, 2659.29, 96.09312, NULL),
(@entry, @id := @id+ 1, 1592.505, 2652.558, 96.36104, NULL),
(@entry, @id := @id+ 1, 1618.379, 2641.814, 97.60857, NULL),
(@entry, @id := @id+ 1, 1662.866, 2620.088, 96.43405, NULL),
(@entry, @id := @id+ 1, 1698.408, 2599.822, 96.41636, NULL),
(@entry, @id := @id+ 1, 1725.689, 2574.59, 100.8454, NULL),
(@entry, @id := @id+ 1, 1738.896, 2550.74, 104.2022, NULL),
(@entry, @id := @id+ 1, 1746.675, 2526.562, 110.6833, NULL),
(@entry, @id := @id+ 1, 1748.517, 2516.984, 115.5963, NULL),
(@entry, @id := @id+ 1, 1755.415, 2507.885, 121.5244, NULL),
(@entry, @id := @id+ 1, 1774.222, 2503.575, 130.3001, NULL),
(@entry, @id := @id+ 1, 1781.03, 2492.333, 138.3618, NULL),
(@entry, @id := @id+ 1, 1784.519, 2474.472, 145.5816, NULL),
(@entry, @id := @id+ 1, 1779.42, 2445.134, 150.6537, NULL),
(@entry, @id := @id+ 1, 1775.873, 2437.181, 152.0934, NULL),
(@entry, @id := @id+ 1, 1773.88, 2433.24, 152.5676, NULL),
(@entry, @id := @id+ 1, 1768.443, 2423.182, 147.0627, NULL),
(@entry, @id := @id+ 1, 1762.04, 2411.097, 144.8849, NULL),
(@entry, @id := @id+ 1, 1756.076, 2399.76, 145.5517, NULL),
(@entry, @id := @id+ 1, 1749.457, 2387.339, 150.2805, NULL),
(@entry, @id := @id+ 1, 1744.099, 2376.351, 159.5151, NULL),
(@entry, @id := @id+ 1, 1741.538, 2371.378, 160.2534, NULL),
(@entry, @id := @id+ 1, 1736.741, 2360.335, 166.1565, NULL),
(@entry, @id := @id+ 1, 1741.28, 2340.196, 175.3122, NULL),
(@entry, @id := @id+ 1, 1744.193, 2336.554, 179.2318, NULL),
(@entry, @id := @id+ 1, 1746.325, 2324.137, 186.6794, NULL),
(@entry, @id := @id+ 1, 1750.389, 2314.833, 186.9828, NULL),
(@entry, @id := @id+ 1, 1773.734, 2289.837, 188.1935, NULL),
-- mine
(@entry, @id := @id+ 1, 1788, 2263, 192, NULL),
(@entry, @id := @id+ 1, 1817, 2235, 182, NULL),
(@entry, @id := @id+ 1, 1901, 2086, 186, NULL),
(@entry, @id := @id+ 1, 1903, 2030, 190, NULL),
(@entry, @id := @id+ 1, 1861, 1978, 221, NULL);
/*
(@entry, @id := @id+ 1, 1756.417, 2279.172, 187.133, NULL),
(@entry, @id := @id+ 1, 1744.917, 2270.422, 188.383, NULL),
(@entry, @id := @id+ 1, 1732.667, 2252.172, 197.383, NULL),
(@entry, @id := @id+ 1, 1724.167, 2227.422, 205.883, NULL),
(@entry, @id := @id+ 1, 1717.667, 2206.672, 213.633, NULL),
(@entry, @id := @id+ 1, 1710.917, 2187.172, 221.383, NULL),
(@entry, @id := @id+ 1, 1706.917, 2165.922, 222.133, NULL),
(@entry, @id := @id+ 1, 1715.167, 2139.922, 222.633, NULL),
(@entry, @id := @id+ 1, 1724.667, 2122.672, 223.133, NULL),
(@entry, @id := @id+ 1, 1733.417, 2108.672, 224.133, NULL),
(@entry, @id := @id+ 1, 1756.917, 2073.422, 226.133, NULL),
(@entry, @id := @id+ 1, 1766.167, 2054.922, 227.133, NULL),
(@entry, @id := @id+ 1, 1778.167, 2028.922, 224.633, NULL),
(@entry, @id := @id+ 1, 1784.917, 2006.422, 227.883, NULL),
(@entry, @id := @id+ 1, 1787.167, 1994.922, 226.883, NULL),
(@entry, @id := @id+ 1, 1796.917, 1984.172, 227.633, NULL),
(@entry, @id := @id+ 1, 1801.417, 1980.422, 229.383, NULL),
(@entry, @id := @id+ 1, 1806.917, 1978.922, 221.883, NULL);*/


-- ----------------------------------------
-- Q: 25109 The Gallywix Labor Mine
-- ----------------------------------------

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38517;
DELETE FROM smart_scripts WHERE entryorguid = 38517;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38517, 0, 0, 0, 47, 0, 100, 0, 25109, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25109');

DELETE FROM `creature_text` WHERE entry =38517;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38517, 0, 0, 'Так. Мы двинемся прочь от вулкана и попытаемся объединиться с орками, чтобы в последний раз напасть на торгового принца. Увидимся на той стороне... надеюсь.', 12, 0, 100, 1, 0, 0, 'Крадли Дротик');

-- cosmetic for mine zone
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38745;
DELETE FROM `creature_addon` WHERE guid IN (select guid from creature WHERE id in (38745, 38409, 38124));
INSERT INTO `creature_addon` (`guid`, `bytes2`, emote, auras) SELECT guid, 1, 233, '73617' FROM creature where id in (38745, 38409, 38124) and phaseMask = 16384;
UPDATE creature SET equipment_id = 11100 WHERE id in (38745, 38409, 38124) and phaseMask = 16384; -- item 1910
UPDATE `creature_template` SET `npcflag` = '0' WHERE `entry` in (38745, 38409); 

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39193;
DELETE FROM smart_scripts WHERE entryorguid = 39193;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39193, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'on aggro say');

DELETE FROM `creature_text` WHERE entry =38517;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39193, 0, 0, 'Моя надзиратель, твоя раб!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель'),
(39193, 0, 1, 'Моя получать большой бонус за поймать тебя!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель'),
(39193, 0, 2, 'За работу!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель'),
(39193, 0, 3, 'Моя любит избивать тебя!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель'),
(39193, 0, 4, 'Ты не раб! Работай или умри!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель'),
(39193, 0, 5, 'Ты не копать руду, ты получать взбучку!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель'),
(39193, 0, 6, 'Торговый принц говорить бить тебя!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель'),
(39193, 0, 7, 'Перерыв окончен!', 12, 0, 100, 0, 0, 0, 'Громила-надзиратель');

-- ----------------------------------------
-- Q: 25110 Kaja'Cola Gives You IDEAS! (TM)
-- ----------------------------------------

UPDATE `gameobject_loot_template` SET ChanceOrQuestChance = -100 WHERE `item` = 52483;

-- SUMMON FRIENDS CONDITION!!!!
DELETE FROM spell_area WHERE spell in (73607, 73568) AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('73607', '4720', '25110', '25184', '0', '0', '2', '1', '64', '66'),
('73568', '4720', '25110', '25184', '0', '0', '2', '1', '64', '66'); -- invisibility should be done by custom by script

DELETE FROM `spell_script_names` WHERE spell_id = 73631;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('73631', 'spell_kcgyi_assistant_greely');

UPDATE `creature_template` SET `minlevel` = '10', `maxlevel` = '10', `faction_A` = '2204', `faction_H` = '2204', `npcflag` = '3', `unit_flags` = '33288', `unit_flags2` = '33556480' WHERE `entry` = 39199;
DELETE FROM `creature_template_addon` WHERE `entry` = 39199;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('39199', '0', '0', '0', '0', '0', '73744');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39199;
DELETE FROM smart_scripts WHERE entryorguid = 39199;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39199, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Say text at resp'),
(39199, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 73605, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'drink'),
(39199, 0, 2, 0, 47, 0, 100, 0, 25122, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25122'),
(39199, 0, 3, 0, 50, 0, 100, 0, 25123, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At complete q: 25123'),
(39199, 0, 4, 0, 47, 0, 100, 0, 25125, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 25125');

-- ----------------------------------------
-- Q: 25122 Morale Boost
-- ----------------------------------------
DELETE FROM `gameobject_loot_template` WHERE item = 52484;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(202552, 52484, -100, 1, 0, 1, 1),
(202553, 52484, -100, 1, 0, 1, 1),
(202554, 52484, -100, 1, 0, 1, 1);

UPDATE `quest_template` SET `RequiredIdCount3` = '1', `RequiredSourceItemId1` = '52484', `RequiredSourceItemCount1` = '20' WHERE `Id` = 25122;

DELETE FROM `spell_script_names` WHERE spell_id = 73583;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('73583', 'spell_cola_zero_one');

DELETE FROM `creature_text` WHERE entry =39199;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39199, 0, 0, 'У МЕНЯ ЕСТЬ ПЛАН!', 14, 0, 100, 0, 0, 0, 'Ассистентка Грили'),
(39199, 1, 0, '$N, мы должны вытащить отсюда всех наших! Самое главное – заставить их выпить побольше \"Каджа-Колы Полулайт\"!', 12, 0, 100, 5, 0, 0, 'Ассистентка Грили'),
(39199, 2, 0, 'Мы – не часть твоей системы!', 14, 0, 100, 15, 0, 0, 'Ассистентка Грили'),
(39199, 3, 0, '$N, надо бежать через северный туннель!', 12, 0, 100, 1, 0, 0, 'Ассистентка Грили');

DELETE FROM `creature_text` WHERE entry =38745;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38745, 0, 0, 'Док! Помоги мне!', 14, 0, 100, 0, 0, 0, 'Кезанский горожанин'),
(38745, 0, 1, 'Скорее доктора!', 14, 0, 100, 0, 0, 0, 'Кезанский горожанин'),
(38745, 0, 2, 'Ботинки с колесиками. И перчатки с колесиками – на тот случай, если ты упал.', 14, 0, 100, 0, 0, 0, 'Кезанский горожанин'),
(38745, 0, 3, 'Лицензии на убийство!', 14, 0, 100, 0, 0, 0, 'Кезанский горожанин'),
(38745, 0, 4, 'Детекторы мам.', 14, 0, 100, 0, 0, 0, 'Кезанский горожанин'),
(38745, 0, 5, 'Бесплатное здравоохранение!', 14, 0, 100, 0, 0, 0, 'Кезанский горожанин');

DELETE FROM `creature_text` WHERE entry =38409;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38409, 0, 0, 'Что скажешь? Лучшее убийство зомби на этой неделе?', 14, 0, 100, 94, 0, 1473, 'Уцелевший гоблин to Баллистический уничтожитель'),
(38409, 0, 1, 'Как больно!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 2, 'Док! Помоги мне!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 3, 'Я истекаю кровью!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 4, 'Глобус, который показывает внутренности планеты... на ее поверхности. Чтобы знать, где копать!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 5, 'Точилки для ложек!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 6, 'Водостойкое мыло! Для использования под водой!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 7, 'Дома из грязи! Когда ты проводишь в них уборку... ОНИ ИСЧЕЗАЮТ.', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 8, 'Мы поместим целый город... в крошечную табакерку!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 9, 'Прикрепить два транспортных средства к большому транспорту и заставить пассажиров прыгать с одного транспорта на другой!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 10, 'Лицензии на убийство!', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин'),
(38409, 0, 11, 'Ботинки с колесиками. И перчатки с колесиками – на тот случай, если ты упал.', 14, 0, 100, 0, 0, 0, 'Уцелевший гоблин');

-- --------------------------------
--          PHASE 32768
-- --------------------------------

DELETE FROM spell_area WHERE spell = 73756 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('73756', '4720', '25184', '25251', '0', '0', '2', '1', '66', '64');

-- ----------------------------------------
-- Q: 25203 What Kind of Name is Chip, Anyway?
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredUnkFlag1` = '1' WHERE `Id` = 25203;

-- ----------------------------------------
-- Q: 25213 The Slave Pits
-- ----------------------------------------

UPDATE `quest_template` SET `StartScript` = '25213' WHERE `Id` = 25213;
DELETE FROM `quest_start_scripts` WHERE id = 25213;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('25213', '0', '15', '89164', '2', '0', '0', '0', '0', '0');

DELETE FROM `creature_text` WHERE entry =38124 AND groupid = 8;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38124, 8, 0, 'Доставь футбомбную униформу в Ямы рабов. Торопись, $N!', 12, 0, 100, 25, 0, 0, 'Ассистентка Грили');

-- [1] GUID: Full: 0xF150BB5400069540 Type: Vehicle Entry: 47956 Low: 431424 spell 89164 summon
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 47956;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('47956', '89174', '1', '0'); -- 73427

UPDATE `creature_template` SET `VehicleId` = '1293', `ScriptName` = 'npc_footbomb_uniform' WHERE `entry` = 47956;

SET @id = 0;
SET @entry = 47956;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 2343.13, 1941.69, 23.6614, NULL),
(@entry, @id := @id+ 1, 2315.24, 1956.47, 23.48, NULL),
(@entry, @id := @id+ 1, 2290.31, 1975.39, 24.7615, NULL),
(@entry, @id := @id+ 1, 2238.5, 2049.91, 29.505, NULL),
(@entry, @id := @id+ 1, 2188.17, 2046.97, 40.0295, NULL),
(@entry, @id := @id+ 1, 2154.7, 2062.08, 45.1491, NULL),
(@entry, @id := @id+ 1, 2139.28, 2109.62, 55.2909, NULL),
(@entry, @id := @id+ 1, 2122.39, 2128.13, 62.0448, NULL),
(@entry, @id := @id+ 1, 2121.06, 2175.94, 63.1841, NULL),
(@entry, @id := @id+ 1, 2139.98, 2234.07, 59.6212, NULL),
(@entry, @id := @id+ 1, 2099.64, 2327.82, 56.9755, NULL),
(@entry, @id := @id+ 1, 2115.86, 2396.34, 46.2249, NULL);


-- ----------------------------------------
-- Q: 25243 She Loves Me, She Loves Me NOT!
-- Q: 25244 What Kind of Name is Candy, Anyway?
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredUnkFlag1` = '1' WHERE `Id` = 25244;

-- ----------------------------------------
-- Q: 25214 Escape Velocity item 52575 goblin 39456 0xF1309A2000066380 click 73947 -> 73948
-- ----------------------------------------

UPDATE `quest_template` SET `Method` = '2' WHERE `Id` = 25214;
UPDATE `creature` SET `MovementType` = '0' WHERE `id` = 39456;
UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 39449;
UPDATE `creature_template` SET `unit_flags` = '32768', `unit_flags2` = '2048', `dynamicflags` = '0' WHERE `entry` = 39449;

DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 39456;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('39456', '73947', '1', '0'); -- 73427
UPDATE `creature_template` SET `npcflag` = '16777216', `InhabitType` = '4', `ScriptName` = 'npc_captured_goblin' WHERE `entry` = 39456;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND SourceGroup = 39456;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('18', '39456', '73947', '0', '0', '2', '1', '52575', '0', '0', '0', '0', '', 'req. item 52575');

DELETE FROM `creature_text` WHERE entry =39456;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39456, 0, 0, 'У пиратов есть ключи!', 12, 0, 100, 0, 0, 0, 'Пойманный гоблин'),
(39456, 0, 1, 'Мама!', 12, 0, 100, 0, 0, 0, 'Пойманный гоблин'),
(39456, 0, 2, 'Просто открой дверь... о нет!..', 12, 0, 100, 0, 0, 0, 'Пойманный гоблин'),
(39456, 0, 3, 'Зачем нужны эти ракеты?!', 12, 0, 100, 0, 0, 0, 'Пойманный гоблин'),
(39456, 0, 4, 'Мм-м... Ты же понимаешь, что у этой клетки есть дно, да?', 12, 0, 100, 0, 0, 0, 'Пойманный гоблин'),
(39456, 0, 5, '3... 2... 1...', 12, 0, 100, 0, 0, 0, 'Пойманный гоблин');

-- ----------------------------------------
-- Q: 25251 Final Confrontation
-- ----------------------------------------

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 39592; -- 82022 82023
UPDATE `creature_template` SET `npcflag` = '16777216' WHERE `entry` = 39592;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 39592;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('39592', '73991', '1', '0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND SourceGroup = 39592;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('18', '39592', '73991', '0', '0', '2', '9', '25251', '0', '0', '0', '0', '', 'req. quest 25251');

--
UPDATE `creature_template` SET `minlevel` = '85', `maxlevel` = '85', `faction_A` = '2204', `faction_H` = '2204', `VehicleId` = '696', `spell1` = '73998', `spell2` = '73994', `spell3` = '73997' WHERE `entry` = 39598;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 39598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('39598', '73989', '1', '0'); 

-- 39582 toDo
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39582;
DELETE FROM smart_scripts WHERE entryorguid = 39582;
UPDATE `creature_template` SET `faction_A` = '14', `faction_H` = '14', `minlevel` = '85', `maxlevel` = '85', `unit_flags` = '559104', `AIName` = '', `ScriptName` = 'npc_trade_prince_gallywix_final' WHERE `entry` = 39582;

DELETE FROM `creature_text` WHERE entry =39582;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39582, 0, 0, 'Заросли мы жирком! Компании необходима чистка!', 14, 0, 100, 0, 0, 19573, 'Торговый принц Галливикс to Тралл'),
(39582, 1, 0, 'Вот деньжата, которые я у тебя одалживал.', 14, 0, 100, 0, 0, 19577, 'Торговый принц Галливикс to Тралл'),
(39582, 2, 0, 'ВИЖУ, ПРЕДАТЕЛЬ ПОДОСПЕЛ, ЧТОБЫ СПАСТИ ТЕБЯ, ВОЖДЬ. КАК ЛОВКО! ВЫ ОБА СКЛОНИТЕСЬ ПЕРЕДО МНОЙ ИЛИ УМРЕТЕ ВМЕСТЕ.', 14, 0, 100, 0, 0, 19567, 'Торговый принц Галливикс'),
(39582, 3, 0, 'В картеле пройдет чистка рядов, и начну я с тебя!', 14, 0, 100, 0, 0, 19571, 'Торговый принц Галливикс to Лучшая футбомбная униформа'),
(39582, 3, 1, 'Горю нетерпением избавиться от тебя!', 14, 0, 100, 0, 0, 19575, 'Торговый принц Галливикс'),
(39582, 3, 2, 'Ты мне нравишься. Повышаю!', 14, 0, 100, 0, 0, 19578, 'Торговый принц Галливикс to Лучшая футбомбная униформа'),
(39582, 4, 0, 'Дядя, дядя! Я сдаюсь! Ребята, мне с вами не справиться!', 14, 0, 100, 20, 0, 19580, 'Торговый принц Галливикс'),
(39582, 5, 0, 'Я побежден. Вы мне указали на мои ошибки! С этого дня я обещаю совершенно иначе вести дела картеля!', 14, 0, 100, 274, 0, 19581, 'Торговый принц Галливикс'),
(39582, 6, 0, 'Как я могу служить тебе, Тралл?', 14, 0, 100, 6, 0, 19582, 'Торговый принц Галливикс');

-- 39594 trall toDO
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39594;
DELETE FROM smart_scripts WHERE entryorguid = 39594;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39594, 0, 0, 0, 60, 0, 100, 0, 5000, 5000, 20000, 20000, 11, 74019, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 74019'),
(39594, 0, 1, 0, 60, 0, 100, 0, 10000, 10000, 20000, 20000, 11, 74023, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 74023'),
(39594, 0, 2, 0, 60, 0, 100, 0, 15000, 15000, 20000, 20000, 11, 74020, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 74020'),
(39594, 0, 3, 0, 60, 0, 100, 0, 17000, 17000, 20000, 20000, 11, 74021, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 74021');

-- --------------------------------
--          PHASE 65536
-- --------------------------------

DELETE FROM spell_area WHERE spell = 74025 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('74025', '4720', '25251', '0', '0', '0', '2', '1', '64', '0');

-- ----------------------------------------
-- Q: 25265 Victory!
-- ----------------------------------------

DELETE FROM `spell_target_position` WHERE id = 74028;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('74028', '648', '2355.3', '2483.69', '11.1715', '0');

UPDATE `quest_template` SET `StartScript` = '25265' WHERE `Id` = 25265;
DELETE FROM `quest_start_scripts` WHERE id = 25265;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('25265', '0', '15', '74028', '2', '0', '0', '0', '0', '0');

-- ----------------------------------------
-- FINAL. EXIT
-- ----------------------------------------
DELETE FROM `quest_start_scripts` WHERE id in (24868, 62);
UPDATE `quest_template` SET `StartScript` = '0' WHERE `Id` = 25266;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=11146 AND id = 1;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `box_coded`, `box_money`, `box_text`, npc_option_npcflag) VALUES
(11146, 1, 0, 'Хамми, отправляемся в Оргриммар, пока этот остров окончательно не взорвался!', 1, 0, 0, '', 2);

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 15 AND SourceGroup = 11146 AND SourceEntry = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('15', '11146', '1', '0', '0', '8', '0', '25265', '0', '0', '0', '0', '', NULL);

DELETE FROM `spell_target_position` WHERE id = 74029;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('74029', '1', '1468.8', '-5012.29', '11.7693', '0');


-- update version for cache update proper.
UPDATE `version` SET  `cache_id` = `cache_id` + 1;
