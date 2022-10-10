/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- --------------------------------
--          PHASE 2048
-- --------------------------------

-- prev 14245

-- ----------------------------------------
-- Q: 27139 Hobart Needs You
-- ----------------------------------------

UPDATE `quest_template` SET `PrevQuestId` = '14245', `CompleteScript` =  '0' WHERE `Id` = 27139;
DELETE FROM `quest_end_scripts` WHERE `id` = 14;
DELETE FROM `creature_questrelation` WHERE `quest` = 27139 AND id != 36471;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=36471;
DELETE FROM smart_scripts WHERE entryorguid = 36471;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(36471, 0, 0, 0, 47, 0, 100, 0, 27139, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 27139');
DELETE FROM `creature_text` WHERE entry = 36471;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36471, 0, 0, 'Хобарт рядом, $gсэр:мэм;.', 12, 0, 100, 25, 0, 0, 'Штейгер Промоках'),
(36471, 1, 0, 'Запомни, тебе нужны лидеры пигмеев: Гаал, Мальмо и Телох.', 12, 0, 100, 1, 0, 1473, 'Штейгер Промоках');

-- ----------------------------------------
-- Q: 24671 Cluster Cluck
-- ----------------------------------------
UPDATE `quest_template` SET `StartScript` = '0' WHERE `Id` = 24671;
DELETE FROM `quest_start_scripts` WHERE `id` = 15;

UPDATE `creature_template` SET `unit_flags` = '32768', `unit_flags2` = '33556480', `dynamicflags` = '0' WHERE `entry` = 38120;

UPDATE `creature_template` SET `npcflag` = '16777216', `InhabitType` = '7', `ScriptName` = 'npc_wild_clucker' WHERE `entry` = 38111;
UPDATE `creature_template_addon` SET `auras` = '66727' WHERE `entry` = 38111;

DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 38111;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES ('38111', '71170', '1', '0');

DELETE FROM `conditions` WHERE SourceGroup = 38111 AND SourceTypeOrReferenceId = 18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 38111, 71170, 0, 0, 9, 0, 24671, 0, 0, 0, 0, '', 'SpellClick - IfPlayerHasQuest');

SET @id = 0;
SET @entry = 38111;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
-- enter to the patch
(@entry, @id := @id+ 1, 917.0868, 2330.082, 25.59299, 0, NULL),
(@entry, @id := @id+ 1, 862.7847, 2365.922, 25.59299, 0, NULL),
(@entry, @id := @id+ 1, 862.6511, 2338.936, 14.56519, 0, NULL),
(@entry, @id := @id+ 1, 913.266, 2359.01, 25.593, 0, NULL),
(@entry, @id := @id+ 1, 915.8021, 2335.549, 25.59299, 0, NULL),
(@entry, @id := @id+ 1, 875.5712, 2332.576, 29.42632, 0, NULL),
(@entry, @id := @id+ 1, 898.4393, 2352.073, 25.59299, 0, NULL),
(@entry, @id := @id+ 1, 932.1893, 2327.84, 18.70409, 0, NULL),
(@entry, @id := @id+ 1, 867.0278, 2335.29, 23.31521, 0, NULL),
(@entry, @id := @id+ 1, 926.6545, 2338.385, 33.75965, 0, NULL),
(@entry, @id := @id+ 1, 950.6979, 2329.811, 44.70409, 0, NULL),
(@entry, @id := @id+ 1, 904.0521, 2334.08, 6.037439, 0, NULL);

UPDATE `creature_template` SET `ScriptName` = 'npc_hobart_grapplehammer', `AIName`='' WHERE `entry`=38120;
DELETE FROM smart_scripts WHERE entryorguid = 38120;


DELETE FROM `creature_text` WHERE entry = 38120;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38120, 0, 0, 'Это действительно довольно просто, $N. Просто прикрепи эти фейерверки к клушам, а я воспользуюсь дистанционным управлением, чтобы они залетели в клетки.', 12, 0, 100, 5, 0, 0, 'Хобарт Дрек'),
(38120, 1, 0, '$N, сюда, пожалуйста.', 12, 0, 100, 3, 0, 0, 'Хобарт Дрек'),
(38120, 2, 0, 'Не стоит недооценивать механоцыпа, $N. В конце концов, это изобретение Хобарта Дрека!', 12, 0, 100, 274, 0, 0, 'Хобарт Дрек'),
(38120, 3, 0, 'Грили, заряди птицефикатор мегаяйцом. Всем наггетсов!', 14, 0, 100, 5, 0, 0, 'Хобарт Дрек'),
(38120, 4, 0, 'Выключай, выключай! Яйца протухли!', 14, 0, 100, 0, 0, 0, 'Хобарт Дрек'),
(38120, 5, 0, 'В соответствии с маркетинговым исследованием, которое провела Мегз, наступление наг случится очень скоро!', 12, 0, 100, 5, 0, 0, 'Хобарт Дрек'),
(38120, 6, 0, 'Не торопись, $gприятель:девочка;. И во что же мне переделать этот реактивный сапог? Хм-м…', 12, 0, 100, 6, 0, 0, 'Хобарт Дрек'),
(38120, 7, 0, 'Я настроил ботзуку так, что за один выстрел она выпускает несколько ракет. Но я не полностью уверен, что как следует откалибровал систему наведения.', 12, 0, 100, 273, 0, 0, 'Хобарт Дрек');

-- ----------------------------------------
-- Q: 24741 Trading Up
-- ----------------------------------------
DELETE FROM gameobject WHERE id = 201974;
UPDATE `quest_template` SET `PrevQuestId` = '24671' WHERE `Id` = 24741;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38122;
DELETE FROM smart_scripts WHERE entryorguid = 38122;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38122, 0, 0, 0, 47, 0, 100, 0, 24741, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At start q: 24741'),
(38122, 0, 1, 0, 50, 0, 100, 0, 24741, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 9, 38120, 0, 20, 0, 0, 0, 0, 'At finish q: 24741 say npc 38120');
DELETE FROM `creature_text` WHERE entry = 38122;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38122, 0, 0, 'Эй, $N, не подойдешь сюда? У меня к тебе дело.', 12, 0, 100, 70, 0, 0, 'Бамм Взрыбомм'), -- should send after complete 24671
(38122, 1, 0, 'А теперь достань настоящих яиц.', 12, 0, 100, 273, 0, 0, 'Бамм Взрыбомм');

DELETE FROM `conditions` WHERE SourceEntry = 56576;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56576, 0, 0, 31, 0, 5, 201972, 0, 0, 0, '', 'Cast target - raptor trap');
DELETE FROM `creature_template_addon` WHERE entry = 38195;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('38195', '0', '0', '0', '1', '0', '71355');
UPDATE `creature_template` SET `minlevel` = '8', `maxlevel` = '8', `faction_A` = '2204', `faction_H` = '2204', `unit_flags` = '8', `unit_flags2` = '34816', `ScriptName` = 'npc_wild_clucker_egg' WHERE `entry` = 38195;

-- ----------------------------------------
-- Q: 24744 The Biggest Egg Ever
-- ----------------------------------------
DELETE FROM gameobject WHERE id = 201977;
UPDATE `gameobject_template` SET `flags` = '4' WHERE `entry` = 201977;
-- 38224
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=38224;
DELETE FROM `smart_scripts` WHERE entryorguid = 38224;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('38224', '0', '0', '0', '37', '0', '100', '0', '0', '0', '0', '0', '58', '1', '71657', '2000', '2000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''),
('38224', '0', '1', '0', '6', '0', '100', '0', '0', '0', '0', '0', '50', '201977', '30000', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'summon megaegg');
UPDATE `creature_template_addon` SET `auras` = '71416 95913 71423' WHERE `entry` = 38224;

UPDATE `creature_template` SET `ScriptName` = 'npc_elm_bunny' WHERE `entry` = 24021;

DELETE FROM `creature_text` WHERE entry = 38124;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38124, 0, 0, 'Отличная идея, доктор. Я не устаю восхищаться вашей гениальностью!', 14, 0, 100, 1, 0, 0, 'Ассистентка Грили'),
(38124, 1, 0, 'Какая огромная штука! Поменяй полярность птицефикатора. Придется пропихивать его через выходное отверстие.', 14, 0, 100, 5, 0, 0, 'Ассистентка Грили'),
(38124, 2, 0, 'Вот так. Сейчас все начнется...', 14, 0, 100, 1, 0, 0, 'Ассистентка Грили'),
(38124, 3, 0, '$N, двигайся к устройству управления паровой мехакулой XD. Избавь нас от Молота!', 12, 0, 100, 1, 0, 0, 'Ассистентка Грили'),
(38124, 4, 0, 'Ищи сияющее вещество на земле.', 12, 0, 100, 1, 0, 0, 'Ассистентка Грили'),
(38124, 5, 0, 'Грили продолжает свою бессмысленную работу, пуская слюни от напряжения.', 16, 0, 100, 0, 0, 0, 'Ассистентка Грили'),
(38124, 6, 0, 'Разберись с этими Акулами Хитрой Шестеренки, пока они нас не разгромили!', 12, 0, 100, 1, 0, 0, 'Ассистентка Грили'),
(38124, 7, 0, 'Пора устроить небольшой саботаж!', 12, 0, 100, 11, 0, 0, 'Ассистентка Грили');

