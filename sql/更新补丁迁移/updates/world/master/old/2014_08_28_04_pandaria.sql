/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` in (53565, 65469, 57748, 61411, 65471, 54587);
DELETE FROM smart_scripts WHERE entryorguid in (53565, 65469, 57748, 61411, 65471, 54587);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(53565, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'cung-fu panda'),
(65469, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'cung-fu panda'),
(57748, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 5000, 5000, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'master cung-fu panda'),
(61411, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 5000, 5000, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'master cung-fu panda');

--
DELETE FROM spell_area WHERE spell in (128700, 120749, 118036,
107027, 107032, 100709, 102403, 107028, 100711, 102194, 107033, 102429, 102393, 102395, 114735, 102396, 102397, 
102399, 102400, 102868, 102521, 108150, 108879, 102873, 102869, 103051, 108834, 102872, 102874, 102870, 102875, 116571, 102871, 128574, 103538,
102398, 114455, 109303, 108835, 108823, 108822, 104018, 118028, 104017, 108844, 108842, 105308, 105307, 105005, 105306, 104567, 104334, 104566,
126059, 105333, 106623, 105001, 105002, 105095, 115426, 115435, 115446, 106494, 106622, 115448, 115447, 115449, 117973, 105525, 117501, 117783, 108931,
105096, 108914, 104028) AND  
area in(5834, 5843, 5825, 5835, 5736, 5846, 5849, 5862, 5827, 5881, 5826, 5860, 5830, 5946, 5831, 5886, 5832, 5829, 5820, 5828, 5944, 5833, 5356);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
-- unk. custom
('128700', '5736', '0', '0', '0', '0', '2', '0', '0', '0'),
('120749', '5356', '0', '0', '0', '0', '2', '0', '0', '0'),
('118036', '5736', '0', '0', '0', '0', '2', '0', '0', '0'),
--
('100709', '5736', '0', '29524', '0', '0', '2', '1', '0', '66'),
--
('102403', '5834', '29524', '29524', '0', '0', '2', '1', '8', '66'),
--
('107028', '5834', '29406', '29409', '0', '0', '2', '1', '74', '66'),
('107027', '5834', '29406', '29409', '0', '0', '2', '1', '74', '66'),
--
('100711', '5834', '29406', '29409', '0', '0', '2', '1', '66', '66'),
('107032', '5834', '29406', '29409', '0', '0', '2', '1', '66', '66'),
--
('107033', '5834', '29409', '29419', '0', '0', '2', '1', '8', '66'),
('102429', '5843', '29409', '29419', '0', '0', '2', '1', '8', '66'),
('102429', '5825', '29409', '29419', '0', '0', '2', '1', '8', '66'),
--
('102194', '5825', '29409', '29419', '0', '0', '2', '1', '66', '66'),
('102194', '5834', '29409', '29419', '0', '0', '2', '1', '66', '66'),
('102194', '5843', '29409', '29419', '0', '0', '2', '1', '66', '66'),
--
('102393', '5825', '29410', '29419', '0', '0', '2', '1', '66', '66'), -- Aysa of the Tushui
('102393', '5846', '29410', '29419', '0', '0', '2', '1', '66', '66'), -- Aysa of the Tushui
--
('102395', '5736', '29419', '29523', '0', '0', '2', '1', '66', '66'),
('114735', '5736', '29419', '29414', '0', '0', '2', '1', '66', '74'),
--
('102396', '5736', '29414', '29523', '0', '0', '2', '1', '66', '66'),
--
('102397', '5736', '29523', '29521', '0', '0', '2', '1', '66', '74'),
('102398', '5835', '29523', '29521', '0', '0', '2', '1', '66', '74'), -- master appear after complete
-- 102399
('102399', '5849', '29420', '29521', '0', '0', '2', '1', '74', '74'),
('102400', '5849', '29420', '29521', '0', '0', '2', '1', '74', '74'),
('102521', '5849', '29420', '29521', '0', '0', '2', '1', '74', '74'),
--
-- ('108150', '5736', '29421', '0', '0', '0', '2', '1', '8', '0'),
--
('102868', '5820', '29423', '29774', '0', '0', '2', '1', '74', '74'),    -- 1-й мастер в храме
--
('102872', '5826', '29521', '29662', '0', '0', '2', '1', '74', '64'),
('102872', '5860', '29521', '29662', '0', '0', '2', '1', '74', '64'),
('102872', '5862', '29521', '29662', '0', '0', '2', '1', '74', '64'),
('108834', '5860', '29521', '0', '0', '0', '2', '1', '74', '0'),
('108834', '5826', '29521', '0', '0', '0', '2', '1', '74', '0'),
('102869', '5860', '29521', '0', '0', '0', '2', '1', '74', '0'),
('102869', '5826', '29521', '0', '0', '0', '2', '1', '74', '0'),
('102869', '5862', '29521', '0', '0', '0', '2', '1', '74', '0'),
('108879', '5860', '29521', '0', '0', '0', '2', '1', '74', '0'), --
('108879', '5826', '29521', '0', '0', '0', '2', '1', '74', '0'), --
('102873', '5860', '29521', '0', '0', '0', '2', '1', '74', '0'),
('102873', '5826', '29521', '0', '0', '0', '2', '1', '74', '0'),
('103051', '5826', '29521', '0', '0', '0', '2', '1', '74', '0'),
('103051', '5860', '29521', '0', '0', '0', '2', '1', '74', '0'),
--
('102874', '5736', '29666', '29678', '0', '0', '2', '1', '66', '66'), -- qgiver1
('102870', '5736', '29666', '29678', '0', '0', '2', '1', '66', '66'), -- qgiver2
--
('102875', '5826', '29678', '0', '0', '0', '2', '1', '66', '0'), -- qgiver1
('102875', '5860', '29678', '0', '0', '0', '2', '1', '66', '0'), -- qgiver1
('102875', '5862', '29678', '0', '0', '0', '2', '1', '66', '0'), -- qgiver1
('102871', '5826', '29678', '0', '0', '0', '2', '1', '66', '0'), -- qgiver2
('102871', '5860', '29678', '0', '0', '0', '2', '1', '66', '0'), -- qgiver2
('102871', '5862', '29678', '0', '0', '0', '2', '1', '66', '0'), -- qgiver2
('128574', '5736', '29678', '29679', '0', '0', '2', '1', '66', '66'), -- watter spitit
('116571', '5862', '29678', '0', '0', '0', '2', '1', '74', '0'), -- not remove
--
('103538', '5736', '29679', '29680', '0', '0', '2', '1', '66', '66'), -- Summon Spirit of Water
--
('114455', '5881', '29680', '0', '0', '0', '2', '1', '74', '0'),
('109303', '5881', '29680', '29774', '0', '0', '2', '1', '74', '66'), -- slipping spirit of earth
('108835', '5881', '29680', '0', '0', '0', '2', '1', '74', '0'),
('108823', '5881', '29680', '29771', '0', '0', '2', '1', '74', '64'), -- YoYo
('108822', '5881', '29680', '29768', '0', '0', '2', '1', '74', '66'), -- quest giver
--
('104018', '5881', '29768', '29774', '0', '0', '2', '1', '66', '66'), -- quest giver
('118028', '5881', '29768', '0', '0', '0', '2', '1', '66', '0'), -- quest giver
--
('104017', '5736', '29774', '29775', '0', '0', '2', '1', '66', '66'), -- Summon Spirit of Water and Earth
--
('104028', '5820', '29774', '0', '0', '0', '2', '1', '66', '0'), -- 2-й мастер в храме
--
('108844', '5830', '29776', '0', '0', '0', '2', '1', '74', '0'),
('108842', '5830', '29776', '29782', '0', '0', '2', '1', '74', '64'),
('105308', '5830', '29776', '0', '0', '0', '2', '1', '74', '0'), -- aisa
('105308', '5946', '29776', '0', '0', '0', '2', '1', '74', '0'), -- aisa
('105307', '5830', '29776', '0', '0', '0', '2', '1', '74', '0'),
('105005', '5830', '29776', '0', '0', '0', '2', '1', '74', '0'),
--
('105306', '5831', '29780', '29784', '0', '0', '2', '1', '74', '74'),
--
('104567', '5886', '29785', '29786', '0', '0', '2', '1', '74', '74'),
('104334', '5886', '29785', '29786', '0', '0', '2', '1', '74', '74'),
('104566', '5886', '29785', '29786', '0', '0', '2', '1', '74', '74'),    -- aisa come to wind spirit
--
('126059', '5886', '29786', '29787', '0', '0', '2', '1', '74', '74'),    -- summon aisa & defang for battle
-- 104762 phase spell, but already done by terrain phasing
('105333', '5829', '29787', '29787', '0', '0', '2', '1', '8', '64'),
-- 105001
('106623', '5832', '29790', '29790', '0', '0', '2', '1', '8', '64'),
--
('105001', '5832', '29790', '0', '0', '0', '2', '1', '66', '0'),
--
('105002', '5832', '29791', '0', '0', '0', '2', '0', '74', '0'),    -- no autocast
-- 105095
('105095', '5820', '29791', '0', '0', '0', '2', '1', '74', '0'),    -- мастер в храме
('106494', '5820', '29792', '0', '0', '0', '2', '1', '74', '0'),
--
('106622', '5832', '29787', '29790', '0', '0', '2', '1', '66', '74'),
--
('115426', '5736', '29792', '29792', '0', '0', '2', '0', '8', '66'),    -- no autocast
('115435', '5736', '29792', '29792', '0', '0', '2', '0', '8', '66'),    -- no autocast
-- 115446
('115446', '5828', '29792', '29792', '0', '0', '2', '1', '8', '66'), -- mandori pre-event
('115448', '5828', '29792', '29792', '0', '0', '2', '1', '8', '66'), -- mandori pre-event
('115447', '5828', '29792', '29792', '0', '0', '2', '1', '8', '66'), -- mandori pre-event
('115449', '5828', '29792', '29792', '0', '0', '2', '1', '8', '66'), -- mandori pre-event hack
--
('117973', '5944', '30589', '30589', '0', '0', '2', '1', '10', '64'),
--
('105525', '5833', '29794', '29794', '0', '0', '2', '1', '8', '66'),
--
('117501', '5736', '29796', '30767', '0', '0', '2', '1', '74', '74'),
-- 117501
('117783', '5736', '29799', '29799', '0', '0', '2', '0', '8', '66'),    -- no autocast
--
('108931', '5736', '29800', '0', '0', '0', '2', '1', '74', '0'),
--
('105096', '5820', '29800', '0', '0', '0', '2', '1', '74', '0'),
('108914', '5820', '29800', '0', '0', '0', '2', '1', '74', '0');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND SourceGroup = 5736;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `Comment`, `ScriptName`) VALUES
(23, 5736, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Pandaren Start loc: world area', ''),
(23, 5736, 3, 0, 1, 8, 0, 29799, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 976', ''),
(23, 5736, 2, 0, 0, 8, 0, 29799, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 and not rewarded 29799', ''),
(23, 5736, 2, 0, 0, 28, 0, 30767, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975', ''),
(23, 5736, 2, 0, 1, 8, 0, 29799, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 and not rewarded 29799', ''),
(23, 5736, 2, 0, 1, 8, 0, 30767, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975', ''),
(23, 5736, 4, 0, 0, 8, 0, 29785, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 while not reward 29785', ''),
(23, 5736, 5, 0, 0, 9, 0, 29786, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975 while taken 29786', ''),
(23, 5736, 6, 0, 0, 8, 0, 29665, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 while not rewarded 29665', ''),
(23, 5736, 6, 0, 0, 8, 0, 29786, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975 while rewarded 29786', ''),
(23, 5736, 6, 0, 1, 28, 0, 29786, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975 while rewarded 29786', ''),
(23, 5736, 7, 0, 0, 8, 0, 29793, 0, 0, 0, 0, 'Pandaren Start loc: phase 3 while rewarded 29793', ''),
(23, 5736, 7, 0, 0, 8, 0, 29665, 0, 0, 1, 0, 'Pandaren Start loc: phase 3 while not rewarded 29665', '');

DELETE FROM phase_definitions WHERE `zoneId` = 5736;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `wmAreaId`, `comment`) VALUES
(5736, 1, 0, 0, 0, 683, 'Pandaren Start loc: world area'),
(5736, 2, 0x40, 0, 975, 0, 'Pandaren Start loc: tarrain 975'),
(5736, 3, 0x20, 0, 976, 0, 'Pandaren Start loc: tarrain976'),
(5736, 4, 3, 34604, 0, 0, 'Pandaren Start loc: 3part. Wind cavern'), -- phase
(5736, 5, 5, 34094, 0, 0, 'Pandaren Start loc: 3part. Battle for the Skies'), -- phase
(5736, 6, 9, 524, 0, 0, 'Pandaren Start loc: 3part. Wind cavern. Finish'), -- phase
(5736, 7, 3, 34095, 0, 0, 'Pandaren Start loc: 3part end');

UPDATE `gameobject` SET id = 210005 WHERE id = 210019;

-- ----------------------------------------
-- Q: 29524 The Lesson of Stifled Pride
-- ----------------------------------------
UPDATE  `creature_template` SET  `AIName`='', `ScriptName` =  'mob_tushui_trainee' WHERE  `entry`  in (54587, 65471);
DELETE FROM `creature_text` WHERE entry =65471;
DELETE FROM `locales_creature_text` WHERE `entry` = 65471;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(65471, 0, 0, 'Моему искусству не сравниться с твоим. Я признаю поражение.', 12, 0, 100, 1, 0, 33646, 'Ученик Тушуй'),
(65471, 0, 1, 'Прекрасный бой. Мне можно будет многому у тебя научиться.', 12, 0, 100, 1, 0, 33645, 'Ученик Тушуй'),
(65471, 0, 2, 'Мне никогда не приходилось видеть таких способных новичков. Я должна рассказать остальным.', 12, 0, 100, 1, 0, 33643, 'Ученик Тушуй'),
(65471, 0, 3, 'Достойный поединок, друг.', 12, 0, 100, 1, 0, 33646, 'Ученик Тушуй'),
(65471, 0, 4, 'Моему искусству не сравниться с твоим. Я признаю поражение.', 12, 0, 100, 1, 0, 33646, 'Ученик Тушуй');

DELETE FROM `creature_text` WHERE entry =54587;
DELETE FROM `locales_creature_text` WHERE `entry` = 54587;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54587, 0, 0, 'Это был хороший бой. Благодарю тебя.', 12, 0, 100, 1, 0, 33643, 'Ученик Тушуй'),
(54587, 0, 1, 'Твое мастерство не вызывает сомнений. Я сдаюсь.', 12, 0, 100, 1, 0, 33646, 'Ученик Тушуй'),
(54587, 0, 2, 'Достойный поединок, друг.', 12, 0, 100, 1, 0, 33643, 'Ученик Тушуй'),
(54587, 0, 3, 'Прекрасный бой. Мне можно будет многому у тебя научиться.', 12, 0, 100, 1, 0, 33645, 'Ученик Тушуй'),
(54587, 0, 4, 'Спасибо за напоминание о том, что нужно тренироваться усерднее.', 12, 0, 100, 1, 0, 33643, 'Ученик Тушуй');

-- ----------------------------------------
-- Q: 29408 The Lesson of the Burning Scroll
-- ----------------------------------------

-- Hack. На самом деле 59591 этот NPC все должен делать
UPDATE `quest_template` SET `SourceItemId` = '0', `RequiredSourceItemId1` = '80212', `RequiredSourceItemId4` = '0' WHERE `Id` = 29408;
UPDATE `creature_template` SET `IconName` = 'openhand', `npcflag` =  npcflag | 16777216, `unit_flags` = '295680' WHERE `entry` = 53566;
UPDATE  `creature_template` SET  `ScriptName` =  'mob_master_shang_xi' WHERE  `entry` =53566;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 53566;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(53566, 114746, 1, 1);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 114746;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 53566, 114746, 9, 0, 29408, 0, 0, 'Required quest active for spellclick');

DELETE FROM `creature_text` WHERE entry =53566;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(53566, 0, 0, 'С первой попытки! Теперь отнеси пламя на самый верх храма и сожги свиток, который ты найдешь там.', 12, 0, 100, 1, 0, 33645, 'Мастер Шан Си');

-- ----------------------------------------
-- Q: 29409 The Disciple's Challenge
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredPOI1` = '252375', `RequiredUnkFlag1` = '1' WHERE `Id` = 29409;
DELETE FROM smart_scripts WHERE entryorguid = 54611;
UPDATE `creature_template` SET `Health_mod` = '2', `AIName` = '', `ScriptName` = 'boss_jaomin_ro' WHERE  `entry` = 54611;

DELETE FROM `locales_creature_text` WHERE `entry` = 54611;
DELETE FROM `creature_text` WHERE entry =54611;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54611, 0, 0, 'А вот и мой соперник.', 12, 0, 100, 113, 0, 0, 'Цзяоминь Жо'),
(54611, 1, 0, 'Поразительно! Ты куда сильнее, чем кажешься.', 12, 0, 100, 2, 0, 0, 'Цзяоминь Жо'),
(54611, 1, 1, 'Тебя хорошо обучили.', 12, 0, 100, 2, 0, 0, 'Цзяоминь Жо'),
(54611, 1, 2, 'Я преклоняюсь перед твоим мастерством. Я уступил в честном бою.', 12, 0, 100, 2, 0, 0, 'Цзяоминь Жо'),
(54611, 1, 3, 'Похоже, мне придется еще как следует потренироваться. Благодарю за урок.', 12, 0, 100, 2, 0, 0, 'Цзяоминь Жо'),
(54611, 1, 4, 'Быть побежденным тобой – большая честь.', 12, 0, 100, 2, 0, 0, 'Цзяоминь Жо'),
(54611, 1, 5, 'Прекрасный бой. Мастер Шан будет доволен.', 12, 0, 100, 2, 0, 0, 'Цзяоминь Жо');

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_panda_announcer' WHERE `entry` = 60183;
DELETE FROM `creature_text` WHERE entry =60183;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60183, 0, 0, 'Надеюсь, ты уже $gготов:готова; к испытанию, $p. Цзяоминь Жо ожидает тебя по ту сторону моста.', 12, 0, 100, 113, 0, 33643, 'Ученик Ним');

-- ----------------------------------------
-- Q: 29409 The Disciple's Challenge
-- ----------------------------------------
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_panda_announcer' WHERE `entry` = 60244;
DELETE FROM `creature_text` WHERE entry =60244;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60244, 0, 0, 'Уже покидаешь нас? Завидую твоей доблести. Счастливого пути, |3-6($c).', 12, 0, 100, 2, 0, 33643, 'Ученик Гуан');

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_panda_announcer' WHERE `entry` = 54943;
DELETE FROM `creature_text` WHERE entry =54943;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54943, 0, 0, 'Тс-с-с! Тихо. Она тренируется.', 12, 0, 100, 396, 0, 0, 'Торговец Лорво');


-- ----------------------------------------
-- Q: 29419 The Missing Driver
-- ----------------------------------------
DELETE FROM smart_scripts WHERE entryorguid = 54855;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'mob_min_dimwind' WHERE `entry` = 54855;
UPDATE `creature_template` SET `ScriptName` = 'mob_attacker_dimwind' WHERE `creature_template`.`entry` = 54130;
UPDATE `creature_template` SET `unit_flags` = '33544', `unit_flags2` = '2048', `ScriptName` = 'npc_min_dimwind_outro' WHERE `entry` = 56503;

DELETE FROM `creature_text` WHERE entry =56503;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56503, 0, 0, 'Мастер Шан может гордиться $gтаким учеником:такой ученицей;. Спасибо, друг!', 12, 0, 100, 2, 0, 0, 'Минь Попутный Ветер'),
(56503, 1, 0, 'Я не смог бы в одиночку справиться с ними. А теперь, если ты не против, я пойду искать свою телегу.', 12, 0, 100, 1, 0, 0, 'Минь Попутный Ветер'),
(56503, 2, 0, 'Телега!', 14, 0, 100, 22, 0, 0, 'Минь Попутный Ветер'),
(56503, 3, 0, 'Здравствуй, тележка. Так и лежишь перевернутая?..', 12, 0, 100, 1, 0, 0, 'Минь Попутный Ветер');

SET @id = 0;
SET @entry = 56503;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 1409.319, 3536.138, 86.87651, NULL), 
(@entry, @id := @id+ 1, 1411.819, 3534.638, 86.12651, NULL), 
(@entry, @id := @id+ 1, 1333.938, 3564.673, 93.37936, NULL), 
(@entry, @id := @id+ 1, 1335.188, 3568.423, 92.87936, NULL),
(@entry, @id := @id+ 1, 1325.719, 3552.776, 96.56885, NULL),
(@entry, @id := @id+ 1, 1286, 3522, 98, NULL);

DELETE FROM `creature_text` WHERE entry =54130;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54130, 0, 0, 'Берегись! Кажется, прибежали его дружки!', 14, 0, 100, 2, 0, 0, 'Проказник из Янтарного Листа');

-- ----------------------------------------
-- Q: 29414  The Way of the Tushui
-- ----------------------------------------

DELETE FROM `creature_involvedrelation` WHERE `quest` = 29414 AND id = 54567;

UPDATE `quest_template` SET `Flags` = '1048576', `Method` = '2', `StartScript` = '29414' WHERE `Id` = 29414;
DELETE FROM `quest_start_scripts` WHERE id = 29414;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29414', '0', '15', '114728', '2', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `ScriptName` = 'mob_aysa_lake_escort' WHERE `creature_template`.`entry` = 59652;
DELETE FROM `script_waypoint` WHERE `entry` = 59652;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(59652, 1, 1225.24, 3449.83, 102.426, 0, ''),
(59652, 2, 1204.46, 3444.84, 102.409, 0, ''),
(59652, 3, 1177.37, 3444.32, 103.093, 0, ''),
(59652, 4, 1165.1, 3441.25, 104.974, 0, '');

DELETE FROM `creature_text` WHERE entry =59652;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(59652, 0, 0, 'Встретимся в пещере наверху.', 12, 0, 100, 396, 0, 27397, 'Аиса Воспевающая Облака');

UPDATE `creature_template` SET `ScriptName` = 'mob_aysa' WHERE `entry` = 59642;
DELETE FROM `creature_text` WHERE entry =59642;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(59642, 0, 0, 'Не дайте этим созданиям прервать мою медитацию. Скоро мы получим ответы на все наши вопросы.', 12, 0, 100, 0, 0, 27398, 'Аиса Воспевающая Облака'),
(59642, 1, 0, 'Итак, мы теперь знаем, что нам предстоит. Обратитесь к мастеру Шан Си. Он раскажет тебе, что делать дальше.', 12, 0, 100, 0, 0, 0, 'Аиса Воспевающая Облака');

DELETE FROM `creature_text` WHERE entry =54856;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54856, 0, 0, 'Мастер Ли Фэй говорит: \"Хо, дух огня, известен своим чувством голода. Он нуждается в древесине – его пище. Он нуждается в ласке ветра, что пробуждает его\".', 16, 0, 100, 0, 0, 0, 'Мастер Ли Фэй'),
(54856, 1, 0, 'Мастер Ли Фэй говорит: \"Если ты найдешь все это и принесешь к его пещере в дальнем конце деревни У-Сун, там тебя будет ждать испытание\".', 16, 0, 100, 0, 0, 0, 'Мастер Ли Фэй'),
(54856, 2, 0, 'Мастер Ли Фэй говорит: \"Путь Тушуй... это просветление через терпение и медитацию... жизнь, основанная на твердых принципах\".', 16, 0, 100, 6, 0, 0, 'Мастер Ли Фэй'),
(54856, 3, 0, 'Мастер Ли Фэй говорит: \"Пройди это испытание, и тебе явится Хо. Разожги его пламя, и если дух твой чист, Хо последует за тобой\".', 16, 0, 100, 0, 0, 0, 'Мастер Ли Фэй'),
(54856, 4, 0, 'Мастер Ли Фэй говорит: \"Приятно видеть тебя снова, Аиса. Ты отдала дань уважения, и посему я дарую тебе ответы, которые ты ищешь\".', 16, 0, 100, 1, 0, 0, 'Мастер Ли Фэй'),
(54856, 5, 0, 'Мастер Ли Фэй говорит: \"Ступайте же, дети мои. Мы встретимся вновь и очень скоро\".', 16, 0, 100, 0, 0, 0, 'Мастер Ли Фэй'),
(54856, 6, 0, 'Мастер Ли Фэй растворяется в воздухе.', 16, 0, 100, 0, 0, 0, 'Мастер Ли Фэй');

-- ----------------------------------------
-- Q: 29417  The Way of the Huojin
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'npc_panda_announcer' WHERE `creature_template`.`entry` = 54568;
DELETE FROM `creature_text` WHERE entry =54568;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54568, 0, 0, 'Получи, обезьянья морда!', 12, 0, 100, 5, 0, 27344, 'Цзи Огненная Лапа');

-- ----------------------------------------
-- Q: 29523  Fanning the Flames
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'boss_living_air' WHERE `entry` = 54631;

-- ----------------------------------------
-- Q: 29421 Only the Worthy Shall Pass
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'boss_li_fei' WHERE  `entry` = 54135;
UPDATE `creature_template` SET `ScriptName` = 'boss_li_fei_fight' WHERE `entry` = 54734;

DELETE FROM `creature_text` WHERE entry =54135;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54135, 0, 0, 'Ты $gзаслужил:заслужила; право пройти. Хо ждет тебя.', 12, 0, 100, 0, 0, 0, 'Мастер Ли Фэй');

-- ----------------------------------------
-- Q: 29423 The Passion of Shen-zin Su
-- ----------------------------------------


-- ----------------------------------------
-- Q: 29521 The Singing Pools
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'npc_childrens_going_to_east' WHERE  `entry` in (60250, 60249);

DELETE FROM `creature_text` WHERE entry =60250;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60250, 0, 0, 'Эй! Это благодаря тебе дух огня снова у нас?', 12, 0, 100, 3, 0, 0, 'Цай'),
(60250, 1, 0, 'Конечно же он был горячим. Не будь дураком, Дэн.', 12, 0, 100, 5, 0, 0, 'Цай'),
(60250, 2, 0, 'Ну-у, Дэн. Готов поспорить, тебя запросто можно запустить пинком во-он за тот холм! Ха!', 12, 0, 100, 274, 0, 0, 'Цай'),
(60250, 3, 0, 'Пока.', 12, 0, 100, 3, 0, 0, 'Цай');

DELETE FROM `creature_text` WHERE entry =60249;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60249, 0, 0, 'А он был горячий? Готов поспорить, что да!', 12, 0, 100, 6, 0, 0, 'Дэн'),
(60249, 1, 0, 'Готов поспорить, силищи тебе не занимать, а? Ты, наверно, можешь одним ударом разломить пополам вон тот мост!', 12, 0, 100, 6, 0, 0, 'Дэн'),
(60249, 2, 0, 'Прощай!', 12, 0, 100, 3, 0, 0, 'Дэн');

DELETE FROM `areatrigger_scripts`  WHERE `ScriptName` LIKE 'at_going_to_east';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES ('7858', 'at_going_to_east');

-- ----------------------------------------
-- Q: 29521 The Singing Pools
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'vehicle_balance_pole' WHERE  `entry` in (54993, 55083, 57431);
UPDATE `creature_template` SET `ScriptName` = 'mob_tushui_monk' WHERE  `entry` in (55019, 65468);
UPDATE `creature_template` SET `IconName` = 'vehichleCursor' WHERE `entry` = 57626;
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 57626;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(57626, 46598, 1, 0);
UPDATE `creature_template` SET `AIName` = 'AggressorAI' WHERE `creature_template`.`entry` = 55015;

-- ----------------------------------------
-- Q: 29662 Stronger Than Reeds
-- ----------------------------------------
UPDATE `quest_template` SET `CompleteScript` = '29662' WHERE `Id` = 29662;
DELETE FROM `quest_end_scripts` WHERE id = 29662;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29662', '0', '15', '108786', '2', '0', '0', '0', '0', '0');

-- cast 129272 Jojo Ironbrow
UPDATE `creature_template` SET `ScriptName` = 'mob_jojo_ironbrow_1' WHERE `creature_template`.`entry` = 57638;

DELETE FROM `creature_text` WHERE entry =57638;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(57638, 0, 0, 'Тростник Поющих прудов – прочнейший в этих краях, но для моего лба даже он – не прочнее воздуха.', 12, 0, 100, 1, 0, 0, 'Йо-Йо Железная Бровь'),
(57638, 1, 0, 'Многие пытались испытать меня, но я несокрушим.', 12, 0, 100, 1, 0, 0, 'Йо-Йо Железная Бровь');

DELETE FROM `conditions` WHERE SourceEntry = 108798;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 108798, 0, 0, 31, 0, 3, 57636, 0, 0, 0, '', 'Cast - Only - 57636');

DELETE FROM `spell_target_position` WHERE id in (108786, 108808);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('108786', '860', '01038.554', '3286.385', '129.1765', '1.815142'),
('108808', '860', '1039.491', '3283.111', '129.5231', '1.815142');

-- ----------------------------------------
-- Q: 29678 Shu, the Spirit of Water
-- ----------------------------------------
UPDATE `quest_template` SET `Flags` = '327688', `RequiredIdCount1` = '1', `RequiredIdCount2` = '1', `RequiredPOI1` = '251733', `RequiredPOI2` = '251734' WHERE `Id` = 29678;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 65493;
DELETE FROM smart_scripts WHERE entryorguid = 65493;

DELETE FROM `creature_involvedrelation` WHERE `quest` = 29678; -- autosubmit

-- ----------------------------------------
-- Q: 29679 A New Friend
-- ----------------------------------------
DELETE FROM `creature_questrelation` WHERE `quest` = 29679;
DELETE FROM `area_queststart` WHERE id = 5862;
INSERT INTO `area_queststart` (`id`, `quest`) VALUES ('5862', '29679');

DELETE FROM `creature_text` WHERE entry = 54975;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(54975, 0, 0, 'Должна признать, за вами было интересно наблюдать!', 12, 0, 100, 0, 0, 27394, 'Аиса Воспевающая Облака'),
(54975, 1, 0, 'И мне кажется, у тебя появился новый друг.', 12, 0, 100, 0, 0, 27395, 'Аиса Воспевающая Облака');

DELETE FROM `spell_script_names` WHERE `spell_id` = 103538;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('103538', 'spell_summon_spirit_of_watter');

UPDATE `creature_template` SET `ScriptName` = 'mob_aysa_cloudsinger_watter_outro' WHERE `entry` = 54975;

-- ----------------------------------------
-- Q: 29680 The Source of Our Livelihood
-- ----------------------------------------
UPDATE `creature_template` SET `IconName` = 'vehichleCursor' WHERE `entry` in (57710, 57741, 59497);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` in (57710, 57741, 59497);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(57710, 115904, 1, 0),
(57741, 115904, 1, 0),
(59497, 115904, 1, 0);

UPDATE `creature_template` SET `VehicleId` = '1944', `ScriptName` = 'vehicle_carriage' WHERE `entry` = 57208;
DELETE FROM `spell_script_names`  WHERE `spell_id` = 115904;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('115904', 'spell_grab_carriage');

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 59499;
UPDATE `creature_template` SET `ScriptName` = 'npc_nourished_yak' WHERE `entry` in (57207, 59499, 57742);

SET @id = 0;
SET @entry = 57207;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 979.338, 2852.28, 87.276, NULL), 
(@entry, @id := @id+ 1, 892.593, 2810.91, 86.4438, NULL), 
(@entry, @id := @id+ 1, 875.519, 2806.39, 81.961, NULL), 
(@entry, @id := @id+ 1, 854.392, 2800.24, 83.5591, NULL), 
(@entry, @id := @id+ 1, 801.608, 2784.76, 76.2802, NULL), 
(@entry, @id := @id+ 1, 749.569, 2827.86, 75.4519, NULL), 
(@entry, @id := @id+ 1, 746.148, 2851.48, 75.5912, NULL), 
(@entry, @id := @id+ 1, 755.357, 2883.45, 74.7007, NULL), 
(@entry, @id := @id+ 1, 742.717, 2904.04, 74.6945, NULL), 
(@entry, @id := @id+ 1, 680.361, 2958.9, 74.9462, NULL), 
(@entry, @id := @id+ 1, 666.782, 2981.86, 74.6082, NULL), 
(@entry, @id := @id+ 1, 659.627, 2990.9, 79.4118, NULL), 
(@entry, @id := @id+ 1, 652.523, 2998.18, 74.6114, NULL), 
(@entry, @id := @id+ 1, 626.525, 3018.83, 74.9584, NULL), 
(@entry, @id := @id+ 1, 615.27, 3036.96, 76.3462, NULL), 
(@entry, @id := @id+ 1, 614.827, 3097.02, 86.6553, NULL), 
(@entry, @id := @id+ 1, 617.181, 3139.57, 87.7514, NULL);

SET @id = 0;
SET @entry = 59499;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 577.366, 3148.85, 87.346, NULL), 
(@entry, @id := @id+ 1, 554.24, 3161.87, 77.325, NULL), 
(@entry, @id := @id+ 1, 538.584, 3211.28, 75.9284, NULL), 
(@entry, @id := @id+ 1, 512.599, 3230.89, 74.053, NULL), 
(@entry, @id := @id+ 1, 508.76, 3260.13, 77.5314, NULL), 
(@entry, @id := @id+ 1, 519.125, 3313.21, 73.1593, NULL), 
(@entry, @id := @id+ 1, 524.149, 3328.19, 78.111, NULL), 
(@entry, @id := @id+ 1, 551.182, 3363.74, 77.8148, NULL), 
(@entry, @id := @id+ 1, 647.98, 3400.74, 97.0092, NULL), 
(@entry, @id := @id+ 1, 683.443, 3440.83, 110.622, NULL), 
(@entry, @id := @id+ 1, 696.219, 3472.66, 118.161, NULL), 
(@entry, @id := @id+ 1, 745.56, 3496.28, 135.538, NULL), 
(@entry, @id := @id+ 1, 756.682, 3523.21, 139.03, NULL), 
(@entry, @id := @id+ 1, 742.424, 3597.72, 140.545, NULL);

SET @id = 0;
SET @entry = 57742;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 270.537, 3877.86, 74.9582, NULL),
(@entry, @id := @id+ 1, 307.495, 3885.75, 78.3896, NULL),
(@entry, @id := @id+ 1, 364.188, 3885.47, 79.1601, NULL),
(@entry, @id := @id+ 1, 429.778, 3885.23, 79.2903, NULL),
(@entry, @id := @id+ 1, 449.465, 3871.15, 79.4622, NULL),
(@entry, @id := @id+ 1, 464.343, 3841.58, 80.2196, NULL),
(@entry, @id := @id+ 1, 468.031, 3821.4, 85.7641, NULL),
(@entry, @id := @id+ 1, 467.986, 3800.75, 80.7985, NULL),
(@entry, @id := @id+ 1, 463.745, 3761.22, 82.4899, NULL),
(@entry, @id := @id+ 1, 454.268, 3733.09, 82.1149, NULL),
(@entry, @id := @id+ 1, 422.182, 3690.9, 81.5705, NULL),
(@entry, @id := @id+ 1, 403.836, 3661.79, 81.3348, NULL),
(@entry, @id := @id+ 1, 403.782, 3629.5, 91.7523, NULL),
(@entry, @id := @id+ 1, 423.51, 3624.41, 91.9309, NULL),
(@entry, @id := @id+ 1, 454.175, 3626.22, 81.0594, NULL),
(@entry, @id := @id+ 1, 510.762, 3627.2, 87.592, NULL),
(@entry, @id := @id+ 1, 556.417, 3589.8, 93.4863, NULL),
(@entry, @id := @id+ 1, 584.172, 3581.42, 95.4726, NULL),
(@entry, @id := @id+ 1, 599.823, 3596.74, 104.971, NULL),
(@entry, @id := @id+ 1, 608.711, 3627.78, 123.258, NULL),
(@entry, @id := @id+ 1, 632.601, 3630.45, 135.198, NULL),
(@entry, @id := @id+ 1, 655.783, 3607.51, 146.08, NULL),
(@entry, @id := @id+ 1, 676.495, 3600.47, 146.439, NULL),
(@entry, @id := @id+ 1, 737.531, 3604.66, 140.596, NULL);


UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_panda_announcer' WHERE `entry` = 57712;
DELETE FROM `creature_text` WHERE entry = 57712;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(57712, 0, 0, 'Здравствуй, друг! Если хочешь, можешь взять мою повозку. Она отвезет тебя на крестьянский двор Дай-Ло.', 12, 0, 100, 3, 0, 0, 'Хозяин повозки'),
(57712, 1, 0, 'Здравствуй, друг! Если хочешь, можешь взять мою повозку. Она отвезет тебя в Храм Пяти Рассветов.', 12, 0, 100, 3, 0, 0, 'Хозяин повозки');

-- ----------------------------------------
-- Q: 29680 Missing Mallet
-- ----------------------------------------
DELETE FROM `creature_text` WHERE entry = 55477;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(55477, 0, 0, 'Проснись уже!', 12, 0, 100, 15, 0, 27345, 'Цзи Огненная Лапа'),
(55477, 1, 0, 'Да', 12, 0, 100, 509, 0, 27350, 'Цзи Огненная Лапа'),
(55477, 2, 0, 'когда же', 12, 0, 100, 507, 0, 27352, 'Цзи Огненная Лапа'),
(55477, 3, 0, '%s вздыхает.', 16, 0, 100, 0, 0, 0, 'Цзи Огненная Лапа');

-- ----------------------------------------
-- Q: 29771 Stronger Than Wood
-- ----------------------------------------
UPDATE `quest_template` SET `CompleteScript` = '29771' WHERE `Id` = 29771;
DELETE FROM `quest_end_scripts` WHERE id = 29771;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29771', '0', '15', '108827', '2', '0', '0', '0', '0', '0');

-- cast 129272 Jojo Ironbrow
UPDATE `creature_template` SET `ScriptName` = 'mob_jojo_ironbrow_2' WHERE `entry` = 57669;

DELETE FROM `creature_text` WHERE entry = 57669;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(57669, 0, 0, 'Наши ремесленники выстругивают отличные доски. Эти доски могут выдержать даже самую сильную бурю. Для моего сокрушительного черепа они не прочнее воды.', 12, 0, 100, 1, 0, 0, 'Йо-Йо Железная Бровь'),
(57669, 1, 0, 'Пандаренам не по силам соорудить барьер, который остановил бы меня.', 12, 0, 100, 2, 0, 0, 'Йо-Йо Железная Бровь');

DELETE FROM `conditions` WHERE SourceEntry = 108831;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 108831, 0, 0, 31, 0, 3, 57667, 0, 0, 0, '', 'Cast - Only - 57667');

DELETE FROM `spell_target_position` WHERE id in (108830, 108827);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('108830', '860', '598.3958', '3132.111', '89.17931', '0.122173'),
('108827', '860', '601.6198', '3132.89', '89.0976', '3.316126');

-- ----------------------------------------
-- Q: 29774 Not In the Face!
-- ----------------------------------------
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_water_spirit_dailo' WHERE  `entry` = 55556;
DELETE FROM smart_scripts WHERE entryorguid = 55556;

DELETE FROM `areatrigger_scripts`  WHERE `ScriptName` LIKE 'AreaTrigger_at_middle_temple_from_east';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES ('8588', 'AreaTrigger_at_middle_temple_from_east');

-- ----------------------------------------
-- Q: 29776 Morning Breeze Village
-- ----------------------------------------
UPDATE `creature_template` SET `gossip_menu_id` = '13158' WHERE `entry` = 54786;
DELETE FROM `gossip_menu` WHERE `entry`= 13158;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(13158, 18536); -- 54786

DELETE FROM `gossip_menu_option` WHERE `menu_id`=13158;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(13158, 0, 0, 'Я хочу вернуться на вершину храма!', 1, 2, 0, 0, 0, 0, '');
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 15 AND SourceGroup = 13158;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('15', '13158', '0', '0', '0', '9', '0', '29776', '0', '0', '0', '0', '', NULL),
('15', '13158', '0', '0', '1', '28', '0', '29776', '0', '0', '0', '0', '', NULL),
('15', '13158', '0', '0', '2', '8', '0', '29776', '0', '0', '0', '0', '', NULL);

DELETE FROM `conditions` WHERE SourceEntry = 104396;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 104396, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', 'Cast - Only on Player'),
(13, 2, 104396, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', 'Cast - Only on Player');

DELETE FROM `spell_target_position` WHERE id = 104450;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('104450', '860', '909.137', '3610.38', '252.092', '3.997228');

UPDATE `creature_template` SET `InhabitType` = '4', `VehicleId` = '1800', `ScriptName` = 'npc_wind_vehicle' WHERE `creature_template`.`entry` = 55685;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 55685;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('55685', '46598', '1', '0');

SET @id = 0;
SET @entry = 55685;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 922.8226, 3604.356, 196.415, NULL), 
(@entry, @id := @id+ 1, 923.8143, 3604.228, 196.415, NULL), 
(@entry, @id := @id+ 1, 930.6059, 3609.285, 201.1691, NULL), 
(@entry, @id := @id+ 1, 938.9011, 3615.786, 203.6904, NULL), 
(@entry, @id := @id+ 1, 950.2917, 3614.42, 204.5032, NULL), 
(@entry, @id := @id+ 1, 960.1268, 3607.947, 209.4728, NULL), 
(@entry, @id := @id+ 1, 951.7205, 3595.486, 218.8211, NULL), 
(@entry, @id := @id+ 1, 941.7274, 3596.609, 228.3404, NULL), 
(@entry, @id := @id+ 1, 932.559, 3604.833, 235.3123, NULL), 
(@entry, @id := @id+ 1, 939.1528, 3613.667, 242.6738, NULL), 
(@entry, @id := @id+ 1, 946.7136, 3611.303, 250.3387, NULL), 
(@entry, @id := @id+ 1, 948.6129, 3602.809, 255.2892, NULL), 
(@entry, @id := @id+ 1, 942.1215, 3596.853, 257.2684, NULL), 
(@entry, @id := @id+ 1, 933.0104, 3600.142, 256.6022, NULL), 
(@entry, @id := @id+ 1, 920.4496, 3604.771, 253.1732, NULL), 
(@entry, @id := @id+ 1, 920.4496, 3604.771, 253.1732, NULL);

UPDATE `creature_template` SET `AIName`='', `ScriptName` = 'mob_master_shang_xi_temple' WHERE `entry` = 54786;
DELETE FROM smart_scripts WHERE entryorguid = 54786;

DELETE FROM `creature_text` WHERE entry =54786;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(54786, 0, 0, 'Добро пожаловать, Хо. Наш народ соскучился по твоему теплу.', 12, 0, 100, 2, 0, 27788, 'Мастер Шан Си'),
(54786, 1, 0, 'Тебе удалось справиться со всеми моими испытаниями. У тебя получилось найти Хо и благополучно привести его в храм.', 12, 0, 100, 1, 0, 27789, 'Мастер Шан Си'),
(54786, 2, 0, 'Нам предстоит решить гораздо более сложную задачу, мои ученики. Шэнь-Цзынь Су страдает от боли. Если мы ничего не предпримем, сама земля, на которой мы стоим, может погибнуть. И мы вместе с ней.', 12, 0, 100, 1, 0, 27790, 'Мастер Шан Си'),
(54786, 3, 0, 'Мы должны поговорить с Шэнь-Цзынь Су и узнать, как исцелить его. А для этого нужно вернуть на свои места четырех духов стихий. Хо был первым.', 12, 0, 100, 1, 0, 27791, 'Мастер Шан Си'),
(54786, 4, 0, 'Цзи, я хочу, чтобы ты отправился на крестьянский двор Дай-Ло и разыскал Угоу, духа земли.', 12, 0, 100, 1, 0, 27792, 'Мастер Шан Си'),
(54786, 5, 0, 'Аиса, я хочу, чтобы ты отправилась к Поющим прудам и разыскала Шу, духа воды.', 12, 0, 100, 1, 0, 27793, 'Мастер Шан Си'),
(54786, 6, 0, 'Ты же будешь направлять наши усилия. Поговори со мной перед тем, как отправиться на восток, к Поющим прудам, и встретиться с Аисой.', 12, 0, 100, 1, 0, 27794, 'Мастер Шан Си'),
(54786, 7, 0, 'Ты снова здесь, вместе с духами воды и земли. Старый учитель гордится тобой.', 12, 0, 100, 1, 0, 27776, 'Мастер Шан Си');

UPDATE `creature_template` SET `ScriptName` = 'npc_panda_announcer' WHERE `entry` = 55694;
DELETE FROM `creature_text` WHERE entry =55694;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(55694, 0, 0, 'Эй! Деревня Утреннего Бриза – это сюда.', 12, 0, 100, 0, 0, 27294, 'Цзи Огненная Лапа');

UPDATE `creature_template` SET `ScriptName` = 'npc_panda_announcer' WHERE `entry` = 64885;
DELETE FROM `creature_text` WHERE entry =64885;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(64885, 0, 0, 'Здравствуй, $n! Хранитель истории внизу как раз начинает урок, может, ты хочешь послушать?', 12, 0, 100, 3, 0, 0, 'Хранитель истории Цзань');


UPDATE `creature_template` SET `ScriptName` = 'npc_panda_history_leason' WHERE `entry` = 64875;
DELETE FROM `creature_text` WHERE entry =64875;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(64875, 0, 0, 'Он открыл зонтик, воткнул в землю и сел в его прохладной тени.', 12, 0, 100, 6, 0, 0, 'Хранительница истории Амай'),
(64875, 1, 0, 'Он закрыл глаза, и стал единым целым с землей. А потом – знаете, что случилось потом?', 12, 0, 100, 2, 0, 0, 'Хранительница истории Амай'),
(64875, 2, 0, 'Его зонтик... пророс! У него выросли корни, он стал деревом, и на нем расцвели цветы!', 12, 0, 100, 5, 0, 0, 'Хранительница истории Амай'),
(64875, 3, 0, 'Да, это правда. Можете пойти в Лес Посохов и увидеть его собственными глазами.', 12, 0, 100, 1, 0, 0, 'Хранительница истории Амай'),
(64875, 4, 0, 'Окруженный посохами всех предков, что были до нас, посохами, выросшими в гигантские деревья.', 12, 0, 100, 274, 0, 0, 'Хранительница истории Амай'),
(64875, 5, 0, 'Это не грустная история! Сам Лю Лан говорил: \"Не стоит сожалеть о жизни, прожитой не зря\".', 12, 0, 100, 1, 0, 0, 'Хранительница истории Амай'),
(64875, 6, 0, 'А он, я думаю, прожил очень хорошую жизнь. Всем, что у нас есть, мы обязаны Лю Лану, первому пандарену-путешественнику.', 12, 0, 100, 273, 0, 0, 'Хранительница истории Амай'),
(64875, 7, 0, 'Мы рассказываем его историю, чтобы память о нем не истерлась никогда.', 12, 0, 100, 2, 0, 0, 'Хранительница истории Амай'),
(64875, 8, 0, 'Спасибо, Жуолинь! Это было прекрасно.', 12, 0, 100, 21, 0, 0, 'Хранительница истории Амай'),
(64875, 9, 0, 'Можешь спеть ее еще раз, для тех, кто только что пришел?', 12, 0, 100, 6, 0, 0, 'Хранительница истории Амай'),
(64875, 10, 0, 'Это песня о Лю Лане, первом пандарене-путешественнике.', 12, 0, 100, 1, 0, 0, 'Хранительница истории Амай'),
(64875, 11, 0, 'Песня написана на древнем наречии, языке императоров и ученых. Вряд ли сейчас кто-то говорит на нем.', 12, 0, 100, 6, 0, 0, 'Хранительница истории Амай'),
(64875, 12, 0, 'Она рассказывает о его приключениях.', 12, 0, 100, 273, 0, 0, 'Хранительница истории Амай'),
(64875, 13, 0, 'Храбрый Лю Лан оседлал морскую черепаху и отправился исследовать мир.', 12, 0, 100, 1, 0, 0, 'Хранительница истории Амай'),
(64875, 14, 0, 'Кто-нибудь помнит, как звали черепаху? Инь?', 12, 0, 100, 25, 0, 0, 'Хранительница истории Амай');

-- ----------------------------------------
-- Q: 29778 Rewritten Wisdoms
-- ----------------------------------------

-- spell: 104126
DELETE FROM `db_script_string` WHERE `entry` in ( 2000009994, 2000009995, 2000009996, 2000009997, 2000009998, 2000009999);
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc8`) VALUES 
('2000009994', 'Хлопушки – бросать. Банану – есть.', 'Хлопушки – бросать. Банану – есть.'),
('2000009995', 'С мокрый мех плохо спать.', 'С мокрый мех плохо спать.'),
('2000009996', 'В каках не кататься, а то пахнуть плохо.', 'В каках не кататься, а то пахнуть плохо.'),
('2000009997', 'Банану чистить, потом есть.', 'Банану чистить, потом есть.'),
('2000009998', 'Свой хвост не тянуть, когда другой есть.', 'Свой хвост не тянуть, когда другой есть.'),
('2000009999', 'Кака не для есть, а для бросать.', 'Кака не для есть, а для бросать.');

-- ----------------------------------------
-- Q: 29783 Stronger Than Stone
-- ----------------------------------------

UPDATE `quest_template` SET `CompleteScript` = '29783' WHERE `Id` = 29783;
DELETE FROM `quest_end_scripts` WHERE id = 29783;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29783', '0', '15', '108847', '2', '0', '0', '0', '0', '0');

-- cast 129272 Jojo Ironbrow
UPDATE `creature_template` SET `ScriptName` = 'mob_jojo_ironbrow_3' WHERE `entry` = 57670;

DELETE FROM `creature_text` WHERE entry =57670;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(57670, 0, 0, 'Эти камни – самые твердые, что есть на Шэнь-Цзынь Су, но и они не устоят перед мощью моих ударов.', 12, 0, 100, 1, 0, 0, 'Йо-Йо Железная Бровь'),
(57670, 1, 0, 'Ни одно разумное создание не усомнится в моей мощи.', 12, 0, 100, 2, 0, 0, 'Йо-Йо Железная Бровь');

-- 129294
DELETE FROM `conditions` WHERE SourceEntry = 108846;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 108846, 0, 0, 31, 0, 3, 57668, 0, 0, 0, '', 'Cast - Only - 57668');

DELETE FROM `spell_target_position` WHERE id in (108845, 108847);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('108845', '860', '1078.087', '4180.681', '205.8848', '3.892084'),
('108847', '860', '1075.602', '4177.969', '205.6298', '0.7853982');

-- ----------------------------------------
-- Q: 29782 Stronger Than Bone
-- ----------------------------------------
UPDATE `quest_template` SET `CompleteScript` = '29782' WHERE `Id` = 29782;
DELETE FROM `quest_end_scripts` WHERE id = 29782;
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('29782', '0', '15', '108858', '2', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `ScriptName` = 'mob_jojo_ironbrow_4' WHERE `entry` = 57692;
DELETE FROM `creature_text` WHERE entry =57692;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(57692, 0, 0, 'Невероятно! Никогда не видел столь искусной работы.', 12, 0, 100, 1, 0, 0, 'Йо-Йо Железная Бровь'),
(57692, 1, 0, 'Остается только одно. Разбить на куски! И тогда все раз и навсегда уверятся в силе моих могучих ударов.', 12, 0, 100, 1, 0, 0, 'Йо-Йо Железная Бровь'),
(57692, 2, 0, 'Ох... моя голова... Как больно! Я... В этом пьедестале, должно быть, содержится невероятная мощь... он мощнее, чем мой лоб.', 12, 0, 100, 18, 0, 0, 'Йо-Йо Железная Бровь'),
(57692, 3, 0, 'Я... я, пожалуй, прилягу... А то что-то голова разболелась...', 12, 0, 100, 0, 0, 0, 'Йо-Йо Железная Бровь');

DELETE FROM `spell_target_position` WHERE id in (108857, 108858);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('108857', '860', '1078.087', '4180.681', '205.8848', '3.892084'),
('108858', '860', '1075.535', '4177.896', '205.5825', '5.550147');

UPDATE `creature_template_addon` SET `auras` = '' WHERE `creature_template_addon`.`entry` = 57692;
UPDATE `creature_template` SET `VehicleId` = '1950' WHERE `creature_template`.`entry` = 57690;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 57690;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('57690', '46598', '1', '0');
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = 57690;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('57690', '57691', '0', '1', '', '8', '0');

-- ----------------------------------------
-- Q: 29780 Do No Evil
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredPOI1` = '263756', `RequiredUnkFlag1` = '1' WHERE `quest_template`.`Id` = 29780;
UPDATE `creature_template` SET `mindmg` = '20', `maxdmg` = '30', `attackpower` = '15', `ScriptName` = 'mob_huojin_monk' WHERE `entry` = 65558;
DELETE FROM `creature_text` WHERE entry =65558;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(65558, 0, 0, 'Давай возьмемся за это вместе!', 12, 0, 100, 5, 0, 27320, 'Цзи Огненная Лапа'),
(65558, 1, 0, 'Мне нравится твой стиль боя!', 12, 0, 100, 5, 0, 27322, 'Цзи Огненная Лапа'),
(65558, 1, 1, 'Это все, на что ты способен?!', 12, 0, 100, 5, 0, 27316, 'Цзи Огненная Лапа'),
(65558, 1, 2, 'Эта обезьяна нарывается!', 12, 0, 100, 5, 0, 27317, 'Цзи Огненная Лапа'),
(65558, 1, 3, 'Еще одной мартышкой меньше. Неплохо!', 12, 0, 100, 5, 0, 27315, 'Цзи Огненная Лапа'),
(65558, 2, 0, 'Увидимся у причала!', 12, 0, 100, 0, 0, 27319, 'Цзи Огненная Лапа');

DELETE FROM `spell_script_names` WHERE spell_id = 105306;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('105306', 'spell_summon_ji_yung');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=55633;
DELETE FROM smart_scripts WHERE entryorguid = 55633;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(55633, 0, 0, 0, 60, 0, 100, 0, 1000, 1000, 3000, 3000, 11, 127940, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 127940'),
(55633, 0, 1, 0, 60, 0, 100, 0, 12000, 12000, 10000, 10000, 75, 109104, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'add aura 127940');

-- ----------------------------------------
-- Q: 29785 Dafeng, the Spirit of Air
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'mob_aysa_wind_temple_escort' WHERE `entry` = 55744;
DELETE FROM `creature_text` WHERE entry =55744;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(55744, 0, 0, 'Стой!', 12, 0, 100, 1, 0, 27401, 'Аиса Воспевающая Облака'),
(55744, 1, 0, 'Когда ветер стихнет, нам нужно добежать до перехода между залами!', 12, 0, 100, 1, 0, 27401, 'Аиса Воспевающая Облака'),
(55744, 2, 0, 'Дождись следующего удачного момента. Встретимся на той стороне зала.', 12, 0, 100, 1, 0, 27402, 'Аиса Воспевающая Облака');

SET @id = 0;
SET @entry = 55744;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 653.1528, 4224.64, 202.9091, NULL),
(@entry, @id := @id+ 1, 649.3229, 4224.635, 202.6591, NULL),
--
(@entry, @id := @id+ 1, 619.8854, 4249.558, 202.6017, NULL),
(@entry, @id := @id+ 1, 617.8068, 4251.757, 202.9503, NULL),
(@entry, @id := @id+ 1, 611.4601, 4257.678, 203.2988, NULL),
(@entry, @id := @id+ 1, 603.9288, 4261.938, 206.5522, NULL),
(@entry, @id := @id+ 1, 598.5729, 4266.665, 206.5522, NULL), -- cast 104612
--
(@entry, @id := @id+ 1, 580.1649, 4283.193, 210.1953, NULL),
(@entry, @id := @id+ 1, 562.1805, 4298.959, 210.5253, NULL),
(@entry, @id := @id+ 1, 548.1077, 4310.887, 210.1953, NULL),
(@entry, @id := @id+ 1, 544.1979, 4315.187, 212.2319, NULL); -- 104748

UPDATE `creature_template` SET `flags_extra` = '128', `ScriptName` = 'mob_frightened_wind' WHERE `entry` = 55665;

-- terrain phasing id 34604
UPDATE creature set phaseMask = 2 WHERE id = 55665;
UPDATE gameobject set phaseMask = 2 WHERE id = 209685;

-- ----------------------------------------
-- Q: 29786 Battle for the Skies
-- ----------------------------------------
DELETE FROM `creature_text` WHERE entry =64506;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(64506, 0, 0, 'Ты все правильно делаешь!', 12, 0, 100, 0, 0, 27380, 'Аиса Воспевающая Облака'),
(64506, 1, 0, 'Получилось! Теперь атакуем его, пока он не взлетел!', 12, 0, 100, 0, 0, 27381, 'Аиса Воспевающая Облака'),
(64506, 1, 1, 'Он на земле! Давай же прикончим его!', 12, 0, 100, 0, 0, 27382, 'Аиса Воспевающая Облака');

UPDATE `creature_template` SET `ScriptName` = 'boss_zhao_ren' WHERE `entry` = 55786;
UPDATE `creature_template` SET `ScriptName` = 'npc_rocket_launcher' WHERE `entry` = 64507;

-- terrain phasing id 34094.
UPDATE `creature` SET `phaseMask` = '4' WHERE id in (55786, 64506, 64505, 64507);

-- terrain phasing id 524. Complete q29786
UPDATE `creature` SET `phaseMask` = '8' WHERE `guid` = 802610+6231 AND id = 55583;
UPDATE `creature` SET `phaseMask` = '8' WHERE `guid` = 802611+6231 AND id = 55595;
UPDATE `creature` SET `phaseMask` = '8' WHERE `guid` = 802609+6231 AND id = 55586;
UPDATE `creature` SET `phaseMask` = '8' WHERE id = 55874;

-- ----------------------------------------
-- Q: 29787 Worthy of Passing
-- ----------------------------------------
DELETE FROM `creature_text` WHERE entry =56159;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56159, 0, 0, 'Идем, дитя. Нам осталось совершить вместе последнее путешествие, и твое обучение будет завершено.', 12, 0, 100, 1, 0, 27797, 'Мастер Шан Си'),
(56159, 1, 0, 'Путь Старейшин приведет нас в Лес Посохов – священную землю, куда дозволено ступать лишь достойным.', 12, 0, 100, 1, 0, 27800, 'Мастер Шан Си'),
(56159, 2, 0, 'Есть много способов проявить себя. Я же прошу от тебя простейшего. Я должен знать, что ты без колебаний будешь сражаться за наш народ и что с тобой наши люди будут в безопасности.', 12, 0, 100, 1, 0, 27801, 'Мастер Шан Си'),
(56159, 3, 0, 'Одержи победу над Стражем Старейшин, и мы сможем пройти.', 12, 0, 100, 1, 0, 27802, 'Мастер Шан Си'),
(56159, 4, 0, 'Теперь ты гораздо сильнее, чем раньше. Это хорошо. Вскоре тебе понадобится эта сила.', 12, 0, 100, 1, 0, 27803, 'Мастер Шан Си');

DELETE FROM `creature` WHERE `id` = 56274;

UPDATE `creature_template` SET `ScriptName` = 'mob_master_shang_xi_after_zhao_escort' WHERE `entry` = 56159;
SET @id = 0;
SET @entry = 56159;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 776.5261, 4178.652, 207.064, NULL),
(@entry, @id := @id+ 1, 801.6656, 4189.778, 207.3955, NULL),
(@entry, @id := @id+ 1, 827.309, 4205.264, 199.727, NULL),
(@entry, @id := @id+ 1, 839.7535, 4215.792, 197.8256, NULL),
(@entry, @id := @id+ 1, 840.4375, 4230.833, 198.0775, NULL),
(@entry, @id := @id+ 1, 842.5364, 4245.484, 196.8491, NULL),
(@entry, @id := @id+ 1, 845.007, 4267.588, 196.8246, NULL),
-- say id 1
(@entry, @id := @id+ 1, 843.8195, 4301.174, 210.9836, NULL),
-- say id 2
(@entry, @id := @id+ 1, 843.2621, 4339.104, 223.9808, NULL),
-- say id 3
(@entry, @id := @id+ 1, 828.719, 4351.882, 224.0418, NULL),
(@entry, @id := @id+ 1, 830.4548, 4362.075, 223.7731, NULL),
-- pause
(@entry, @id := @id+ 1, 874.1077, 4459.631, 241.1889, NULL);

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_panda_announcer' WHERE `entry` = 55672;
DELETE FROM `creature_text` WHERE entry =55672;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(55672, 0, 0, 'Вот мы и на месте. Мне понадобится твоя помощь в приготовлениях.', 12, 0, 100, 1, 0, 27805, 'Мастер Шан Си');
-- terrain phasing id 34653 show before complete 29790
UPDATE creature set phaseMask = 1 WHERE id = 55672;
DELETE FROM `locales_creature_text` WHERE `entry` = 55672;
UPDATE `creature_template_addon` SET `auras` = '108900 65499 126160' WHERE `entry` = 55672;

-- ----------------------------------------
-- Q: 29790 Passing Wisdom
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'mob_master_shang_xi_thousand_staff' WHERE `entry` = 56686;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 56686;
DELETE FROM `creature_text` WHERE entry =56686;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56686, 0, 0, 'Три тысячи лет мы передаем знания наших предков новым поколениям. Старики – молодым. Учителя – ученикам.', 12, 0, 100, 1, 0, 27807, 'Мастер Шан Си'),
(56686, 1, 0, 'В конце своей жизни каждый старейшина должен уйти и воткнуть свой посох рядом с посохами предков. Сегодня и мой посох станет частью этого леса.', 12, 0, 100, 1, 0, 27808, 'Мастер Шан Си'),
(56686, 2, 0, 'Наш народ очень давно живет на спине великой черепахи Шэнь-Цзынь Су. Но вот уже много веков никто не разговаривал с ним.', 12, 0, 100, 1, 0, 27809, 'Мастер Шан Си'),
(56686, 3, 0, 'Сейчас Шэнь-Цзынь Су болен, и всем нам грозит опасность. С помощью духов стихий ты прервешь вековое молчание. Ты поговоришь с ним.', 12, 0, 100, 1, 0, 27810, 'Мастер Шан Си'),
(56686, 4, 0, 'Аиса и Цзи привели сюда духов стихий. Ты отправишься с ними, поговоришь с великим Шэнь-Цзынь Су и сделаешь все, что потребуется для спасения нашего народа.', 12, 0, 100, 1, 0, 27811, 'Мастер Шан Си'),
(56686, 5, 0, 'Тебе многого удалось достичь. Я вижу в тебе великого героя... Я оставляю судьбу этой земли в твоих руках.', 12, 0, 100, 396, 0, 27812, 'Мастер Шан Си');

DELETE FROM `spell_target_position` WHERE id = 109335;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('109335', '860', 873.09, 4462.25, 241.27, 3.80);

DELETE FROM `conditions` WHERE SourceEntry = 109336;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 109336, 0, 0, 31, 0, 3, 57874, 0, 0, 0, '', 'Cast - Only - 57668');

UPDATE creature set phaseMask = 16 WHERE id = 54786;

-- ----------------------------------------
-- Q: 29791 The Suffering of Shen-zin Su
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'mob_aisa_pre_balon_event' WHERE `entry` = 56662;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 56662;
DELETE FROM `creature_text` WHERE entry =56662;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56662, 0, 0, 'Мы готовы отправиться в любой момент, $n.', 12, 0, 100, 1, 0, 27428, 'Аиса Воспевающая Облака'),
(56662, 1, 0, 'Забирайся.', 12, 0, 100, 1, 0, 27429, 'Аиса Воспевающая Облака'),
(56662, 2, 0, 'Не слушай его. Нас ждут важные дела.', 12, 0, 100, 1, 0, 27430, 'Аиса Воспевающая Облака');

DELETE FROM `creature_text` WHERE entry =56663;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56663, 0, 0, 'Слушай, если хочешь побродить по лесу, мы с Аисой подождем тебя здесь... Ну, ты понимаешь, да?', 12, 0, 100, 1, 0, 27296, 'Цзи Огненная Лапа');

UPDATE `creature_template` SET `IconName` = 'vehichleCursor', `unit_flags` = '33536', `npcflag` = '16777216', `VehicleId` = '1887' WHERE `entry` = 55918;
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = 55918;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('55918', '56663', '1', '1', '', '8', '0');
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 55918;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55918, 46598, 1, 0);
UPDATE `creature_template_addon` SET `auras` = '49414' WHERE `entry` = 56663;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 55918;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55918, 46598, 1, 0),
(55918, 128815, 1, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 55918;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)VALUES 
(18, 55918, 128815, 9, 0, 29791, 0, 0, 'Required quest active for spellclick'),
(18, 55918, 128815, 31, 0, 4, 0, 0, 'Spellclick for player'),
(18, 55918, 46598, 31, 0, 3, 0, 0, 'Spellclick for npc');

UPDATE `creature_template` SET `VehicleId` = '1820', `InhabitType` = '4', `ScriptName` = 'mop_air_balloon' WHERE `entry` = 55649;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 55649;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55649, 46598, 1, 0);
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = 55649;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('55649', '56660', '2', '1', '', '8', '0'),
('55649', '65476', '3', '1', '', '8', '0'),
('55649', '65477', '4', '1', '', '8', '0');

UPDATE `creature_template` SET `InhabitType` = '4' WHERE `entry` in (56676, 57769);

DELETE FROM `conditions` WHERE SourceEntry in (114888, 114898, 106759, 118571, 118572);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 114888, 0, 0, 31, 0, 3, 57769, 0, 0, 0, '', 'Cast - ON - 57769'),
(13, 3, 114898, 0, 0, 31, 0, 3, 57769, 0, 0, 0, '', 'Cast - ON - 57769'),
(13, 1, 106759, 0, 0, 31, 0, 3, 56676, 0, 0, 0, '', 'Cast - ON - 56676'),
(13, 1, 118571, 0, 0, 31, 0, 3, 57769, 0, 0, 0, '', 'Cast - ON - 57769'),
(13, 1, 118572, 0, 0, 31, 0, 3, 57769, 0, 0, 0, '', 'Cast - ON - 57769');

DELETE FROM `spell_target_position` WHERE id = 105002;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('105002', '860', '915.559', '4563.667', '231.0833', '2.298086');

DELETE FROM `creature_text` WHERE entry =56661;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56661, 0, 0, 'Цзи... они же были в Лесу Посохов. Неужели ты не знаешь, где теперь мастер Шан?', 12, 0, 100, 1, 0, 27431, 'Аиса Воспевающая Облака'), -- 17:24:51.000
(56661, 1, 0, 'Цзи, будь почтителен с Шэнь-Цзынь Су.', 12, 0, 100, 1, 0, 27432, 'Аиса Воспевающая Облака'), -- 17:25:07.000
(56661, 2, 0, 'Не заставляй нас краснеть за тебя.', 12, 0, 100, 1, 0, 27433, 'Аиса Воспевающая Облака'), -- 17:25:18.000
(56661, 3, 0, 'Шэнь-Цзынь Су, мы потомки Лю Лана. Мы почувствовали твою боль и хотим помочь.', 14, 0, 100, 1, 0, 27434, 'Аиса Воспевающая Облака'), -- 17:25:31.000
(56661, 4, 0, 'Что случилось с тобой, Шэнь-Цзынь Су? Что мы можем сделать?', 14, 0, 100, 6, 0, 27435, 'Аиса Воспевающая Облака'), -- 17:25:38.000
(56661, 5, 0, 'Конечно, Шэнь-Цзынь Су! Но твой панцирь огромен, и я не знаю, где в нем может быть эта заноза.', 14, 0, 100, 1, 0, 27436, 'Аиса Воспевающая Облака'), -- 17:26:40.000
(56661, 6, 0, 'Мы найдем ее и вытащим. Даем слово!', 14, 0, 100, 1, 0, 27437, 'Аиса Воспевающая Облака'), -- 17:27:02.000
(56661, 7, 0, 'Скоро мы это узнаем.', 12, 0, 100, 1, 0, 27438, 'Аиса Воспевающая Облака'), -- 17:27:29.000
(56661, 8, 0, 'Да, корабль. Очень большой корабль. Заноза оказалась крупнее, чем я думала.', 12, 0, 100, 1, 0, 27439, 'Аиса Воспевающая Облака'), -- 17:27:50.000
(56661, 9, 0, 'Кто-то врезался в наш остров. Но достать такую занозу будет сложнее, чем мы предполагали.', 12, 0, 100, 1, 0, 27440, 'Аиса Воспевающая Облака'), -- 17:28:04.000
(56661, 10,0, 'Расскажем обо всем старейшине Шаопаю. Он даст нам совет.', 12, 0, 100, 1, 0, 27441, 'Аиса Воспевающая Облака'); -- 17:28:10.000

DELETE FROM `creature_text` WHERE entry =56660;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56660, 0, 0, 'А где мастер Шан?', 12, 0, 100, 6, 0, 27297, 'Цзи Огненная Лапа'), -- 17:24:47.000
(56660, 1, 0, 'Да, но я все равно надеялся... Я буду скучать по старику.', 12, 0, 100, 1, 0, 27298, 'Цзи Огненная Лапа'), -- 17:24:57.000
(56660, 2, 0, 'Я всегда почтителен! Ты меня обижаешь, Аиса.', 12, 0, 100, 6, 0, 27299, 'Цзи Огненная Лапа'), -- 17:25:13.000
(56660, 3, 0, 'Заноза?.. Жаль, я не захватил с собой пинцет.', 12, 0, 100, 6, 0, 27300, 'Цзи Огненная Лапа'), -- 17:27:16.000
(56660, 4, 0, 'Почему такое огромное существо страдает из-за какой-то щепки?', 12, 0, 100, 6, 0, 27301, 'Цзи Огненная Лапа'), -- 17:27:22.000
(56660, 5, 0, 'Ты только посмотри! Это что, корабль?!', 12, 0, 100, 5, 0, 27302, 'Цзи Огненная Лапа'), -- 17:27:43.000
(56660, 6, 0, 'И прилетели на нем вовсе не пандарены. У них нет меха.', 12, 0, 100, 1, 0, 27303, 'Цзи Огненная Лапа'); -- 17:27:57.000

DELETE FROM `creature_text` WHERE entry =56676;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56676, 0, 0, 'Боль мучает меня, но сердце мое радуется, что внуки Лю Лана не забыли обо мне.', 12, 0, 100, 0, 0, 27822, 'Шэнь-Цзынь Су'), -- 17:25:44.000
(56676, 1, 0, 'У меня в боку заноза, и я никак не могу от нее избавиться.', 12, 0, 100, 0, 0, 27823, 'Шэнь-Цзынь Су'), -- 17:25:58.000
(56676, 2, 0, 'Боль просто невыносима. Я больше не могу плыть прямо!', 12, 0, 100, 0, 0, 27824, 'Шэнь-Цзынь Су'), -- 17:26:12.000
(56676, 3, 0, 'Прошу вас, дети, вытащите эту занозу. Я не могу сделать это сам.', 12, 0, 100, 0, 0, 27825, 'Шэнь-Цзынь Су'), -- 17:26:25.000
(56676, 4, 0, 'Она в том лесу, где пандарены никогда не бывают. Летите вдоль гор – и найдете ее.', 12, 0, 100, 0, 0, 27826, 'Шэнь-Цзынь Су'), -- 17:26:47.000 
(56676, 5, 0, 'Спасибо, дети мои.', 12, 0, 100, 0, 0, 27827, 'Шэнь-Цзынь Су'); -- 17:27:09.000

-- head and voice
UPDATE `creature` SET `isActive` = '1' WHERE `id` in (57769, 56676);
UPDATE `creature_template` SET `flags_extra` = '128' WHERE `creature_template`.`entry` = 56676;

SET @id = 0;
SET @entry = 55649;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 934.2396, 4571.044, 233.6516, NULL),
(@entry, @id := @id+ 1, 1015.715, 4604.329, 216.5495, NULL),
(@entry, @id := @id+ 1, 1056.448, 4658.655, 187.7374, NULL),
(@entry, @id := @id+ 1, 1081.418, 4796.375, 157.6622, NULL),
(@entry, @id := @id+ 1, 1091.849, 4926.616, 137.9268, NULL),
(@entry, @id := @id+ 1, 1026.328, 5137.097, 138.0555, NULL),
(@entry, @id := @id+ 1, 818.2934, 5216.31, 134.6396, NULL),
(@entry, @id := @id+ 1, 621.7153, 5132.557, 142.15, NULL),
(@entry, @id := @id+ 1, 547.2552, 5035.906, 130.4939, NULL),
(@entry, @id := @id+ 1, 440.7517, 4867.261, 117.5795, NULL),
(@entry, @id := @id+ 1, 403.5208, 4650.163, 81.13639, NULL),
(@entry, @id := @id+ 1, 341.3038, 4475.935, 75.50136, NULL),
(@entry, @id := @id+ 1, 222.5573, 4369.272, 93.21405, NULL),
(@entry, @id := @id+ 1, 164.7587, 4297.126, 112.2426, NULL),
(@entry, @id := @id+ 1, 131.7517, 4156.708, 124.6377, NULL), -- 105010
(@entry, @id := @id+ 1, 123.9514, 4109.052, 124.6377, NULL),
(@entry, @id := @id+ 1, 112.0469, 3931.905, 128.3417, NULL),
(@entry, @id := @id+ 1, 218.5, 3824.769, 137.5752, NULL),
(@entry, @id := @id+ 1, 388.9236, 3765.605, 159.4655, NULL),
(@entry, @id := @id+ 1, 596.5712, 3689.253, 183.0423, NULL),
(@entry, @id := @id+ 1, 745.1858, 3664.532, 194.0496, NULL); -- 60603 + 45472

-- ----------------------------------------
-- Q: 29792 Bidden to Greatness
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredIdCount1` = '1', `RequiredIdCount2` = '1', `RequiredPOI1` = '263982', `RequiredPOI2` = '263983' WHERE `quest_template`.`Id` = 29792;

UPDATE `creature_template` SET `ScriptName` = 'mob_mandori_escort' WHERE `entry` in (59986, 59988, 59989);

DELETE FROM `creature_text` WHERE entry =59986;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(59986, 0, 0, 'Ладно, приступим.', 12, 0, 100, 432, 0, 27420, 'Аиса Воспевающая Облака'),
(59986, 1, 0, 'Э-э...', 12, 0, 100, 432, 0, 27421, 'Аиса Воспевающая Облака'),
(59986, 2, 0, 'Ворота заклинило.', 12, 0, 100, 274, 0, 27422, 'Аиса Воспевающая Облака'),
(59986, 3, 0, 'Альянса? Если это их корабль потерпел крушение, мы должны с ними связаться. Йо-йо, не мог бы ты пойти со мной?', 12, 0, 100, 6, 0, 27419, 'Аиса Воспевающая Облака');

DELETE FROM `creature_text` WHERE entry =59988;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(59988, 0, 0, 'Дай-ка попробую.', 12, 0, 100, 5, 0, 27339, 'Цзи Огненная Лапа'),
(59988, 1, 0, 'Их там валуном что ли подперли? Не открываются!', 12, 0, 100, 23, 0, 27340, 'Цзи Огненная Лапа'),
(59988, 2, 0, 'Молодчина, Йо-йо!', 12, 0, 100, 0, 0, 27341, 'Цзи Огненная Лапа'),
(59988, 3, 0, 'Керга, мы должны убрать этот корабль с острова. Если мы поможем твоей команде, поможете ли вы нам?', 12, 0, 100, 1, 0, 27333, 'Цзи Огненная Лапа'),
(59988, 4, 0, 'Уж что что, а пропавших мы искать умеем. Мы этим займемся.', 12, 0, 100, 1, 0, 27334, 'Цзи Огненная Лапа');

DELETE FROM `creature_text` WHERE entry =60042;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60042, 0, 0, 'Это твои друзья, Вэй?', 12, 0, 100, 6, 0, 28120, 'Корга Крепкая Грива'),
(60042, 1, 0, 'Я – Корга Крепкая Грива, некогда пленник Альянса, ныне же – свободный и, увы, безоружный таурен. Рад встрече с вами, пандарены.', 12, 0, 100, 66, 0, 28121, 'Корга Крепкая Грива'),
(60042, 2, 0, 'С радостью, мой новый друг. Наш инженер пропал в лесу, сначала нам нужно найти его.', 12, 0, 100, 1, 0, 28122, 'Корга Крепкая Грива');

DELETE FROM `creature_text` WHERE entry =55943;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(55943, 0, 0, 'Никогда в жизни не встречал их. Впрочем, пандарены не бывают плохими.', 12, 0, 100, 0, 0, 28090, 'Вэй Бледная Ярость');

-- 115447
DELETE FROM `spell_target_position` WHERE id in (115426, 115435);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('115426', '860', '695.26', '3600.99', '142.38', '3.04'),
('115435', '860', '566.52', '3583.46', '92.16', '3.14');

DELETE FROM `conditions` WHERE SourceEntry in (115332, 115335, 115337);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 115332, 0, 0, 31, 0, 3, 59962, 0, 0, 0, '', 'Cast - Only - 59962'),
(13, 1, 115335, 0, 0, 31, 0, 3, 59960, 0, 0, 0, '', 'Cast - Only - 59960'),
(13, 1, 115337, 0, 0, 31, 0, 3, 59963, 0, 0, 0, '', 'Cast - Only - 59963');

-- CUSTOM VISIBILITY FOR TRIGERS - 59962, 59960, 59963
UPDATE `creature_template` SET `ScriptName` = 'mob_mandori_triger', `flags_extra` = '0' WHERE `entry` = 59962;
UPDATE `creature_addon` SET `auras` = '94222' WHERE `creature_addon`.`guid` = 802805+6231;
UPDATE `creature_addon` SET `auras` = '94222' WHERE `creature_addon`.`guid` = 802803+6231;
UPDATE `creature_addon` SET `auras` = '115672 94222' WHERE `creature_addon`.`guid` = 802804+6231;
UPDATE `creature_template_addon` SET `auras` = '115354 115672' WHERE `creature_template_addon`.`entry` = 59989;

SET @id = 0;
SET @entry = 59986;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 669.9549, 3601.26, 146.9476, NULL),
(@entry, @id := @id+ 1, 658.6858, 3604.403, 146.6792, NULL),
(@entry, @id := @id+ 1, 647.2552, 3614.688, 142.6406, NULL),
(@entry, @id := @id+ 1, 638.5504, 3625.577, 137.8199, NULL),
(@entry, @id := @id+ 1, 625.7934, 3630.421, 132.36, NULL),
(@entry, @id := @id+ 1, 611.5254, 3625.836, 124.2662, NULL),
(@entry, @id := @id+ 1, 602.8848, 3614.83, 115.7662, NULL),
(@entry, @id := @id+ 1, 598.0799, 3601.406, 107.2206, NULL),
(@entry, @id := @id+ 1, 588.3066, 3586.288, 97.52676, NULL),
(@entry, @id := @id+ 1, 571.2014, 3584.595, 94.91946, NULL),
(@entry, @id := @id+ 1, 571.2014, 3584.595, 94.91946, NULL), -- Дубль
(@entry, @id := @id+ 1, 568.724, 3584.41, 94.76944, NULL),
--
(@entry, @id := @id+ 1, 571.8, 3586.57, 94.82584, NULL),
(@entry, @id := @id+ 1, 499.3385, 3611.266, 85.44111, NULL),
(@entry, @id := @id+ 1, 479.4809, 3622.007, 81.81779, NULL),
(@entry, @id := @id+ 1, 462.6892, 3628.663, 78.4108, NULL),
(@entry, @id := @id+ 1, 443.7552, 3632.061, 85.1813, NULL),
(@entry, @id := @id+ 1, 436.3767, 3631.753, 88.03299, NULL),
(@entry, @id := @id+ 1, 428.1528, 3631.595, 91.02669, NULL),
(@entry, @id := @id+ 1, 422.5039, 3633.635, 92.88139, NULL),
--
(@entry, @id := @id+ 1, 424.3941, 3676.559, 78.70142, NULL),
(@entry, @id := @id+ 1, 435.7865, 3704.581, 81.56339, NULL),
(@entry, @id := @id+ 1, 445.507, 3718.959, 82.68839, NULL),
(@entry, @id := @id+ 1, 457.1354, 3734.84, 82.35698, NULL),
(@entry, @id := @id+ 1, 464.3438, 3756.657, 82.74565, NULL);

SET @id = 0;
SET @entry = 59988;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 675.0035, 3599.222, 146.6835, NULL),
(@entry, @id := @id+ 1, 659.3333, 3601.18, 146.9494, NULL),
(@entry, @id := @id+ 1, 649.132, 3609.039, 144.572, NULL),
(@entry, @id := @id+ 1, 639.2743, 3619.913, 139.0959, NULL),
(@entry, @id := @id+ 1, 630.9132, 3625.345, 134.73, NULL),
(@entry, @id := @id+ 1, 620.4601, 3625.379, 129.0705, NULL),
(@entry, @id := @id+ 1, 610.5703, 3618.582, 121.2662, NULL),
(@entry, @id := @id+ 1, 605.4132, 3610.27, 114.0016, NULL),
(@entry, @id := @id+ 1, 600.7188, 3595.637, 104.6699, NULL),
(@entry, @id := @id+ 1, 593.5364, 3583.125, 98.30069, NULL),
(@entry, @id := @id+ 1, 585.7361, 3577.585, 95.3511, NULL),
(@entry, @id := @id+ 1, 573.84, 3577.94, 95.10342, NULL),
--
(@entry, @id := @id+ 1, 571.661, 3578.93, 94.99271, NULL),
(@entry, @id := @id+ 1, 536.6077, 3584.865, 92.3869, NULL),
(@entry, @id := @id+ 1, 519.8924, 3588.034, 90.32192, NULL),
(@entry, @id := @id+ 1, 507.599, 3595.431, 87.50808, NULL),
(@entry, @id := @id+ 1, 498, 3608.744, 85.53165, NULL),
(@entry, @id := @id+ 1, 486.6979, 3617.666, 83.69584, NULL),
(@entry, @id := @id+ 1, 461.1267, 3629.013, 78.84695, NULL),
(@entry, @id := @id+ 1, 442.882, 3633.776, 85.53565, NULL),
(@entry, @id := @id+ 1, 430.9445, 3634.43, 90.31693, NULL),
(@entry, @id := @id+ 1, 424.5833, 3635.575, 92.82523, NULL),
(@entry, @id := @id+ 1, 424.5833, 3635.575, 92.82523, NULL),
--
(@entry, @id := @id+ 1, 424.5833, 3635.575, 92.82523, NULL);

SET @id = 0;
SET @entry = 59989;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 677.283, 3600.503, 146.4497, NULL),
(@entry, @id := @id+ 1, 665.5313, 3600.911, 147.0744, NULL),
(@entry, @id := @id+ 1, 656.7413, 3604.108, 146.6406, NULL),
(@entry, @id := @id+ 1, 645.9774, 3614.137, 142.466, NULL),
(@entry, @id := @id+ 1, 638.6007, 3623.51, 138.1412, NULL),
(@entry, @id := @id+ 1, 628.1059, 3628.785, 133.3819, NULL),
(@entry, @id := @id+ 1, 616.4792, 3626.98, 127.1512, NULL),
(@entry, @id := @id+ 1, 607.2969, 3622.048, 120.8303, NULL),
(@entry, @id := @id+ 1, 602.5174, 3612.569, 114.3488, NULL),
(@entry, @id := @id+ 1, 598.3073, 3598.223, 105.4915, NULL),
(@entry, @id := @id+ 1, 594.8047, 3587.792, 100.2768, NULL),
(@entry, @id := @id+ 1, 579.3159, 3582.013, 95.11411, NULL),
--
(@entry, @id := @id+ 1, 569.9028, 3582.063, 95.02676, NULL),
(@entry, @id := @id+ 1, 499.5573, 3608.757, 85.59282, NULL),
(@entry, @id := @id+ 1, 480.7305, 3618.067, 82.44596, NULL),
(@entry, @id := @id+ 1, 458.9931, 3626.623, 79.32852, NULL),
(@entry, @id := @id+ 1, 445.6858, 3629.406, 84.4866, NULL),
(@entry, @id := @id+ 1, 432.7109, 3628.783, 89.40828, NULL),
(@entry, @id := @id+ 1, 424.2535, 3628.505, 91.83723, NULL),
(@entry, @id := @id+ 1, 418.0625, 3630.886, 93.03218, NULL),
--
(@entry, @id := @id+ 1, 418.0573, 3675.714, 80.21563, NULL),
(@entry, @id := @id+ 1, 433.3663, 3706.94, 81.56339, NULL),
(@entry, @id := @id+ 1, 443.5052, 3720.292, 82.90519, NULL),
(@entry, @id := @id+ 1, 455.2448, 3735.099, 82.29875, NULL),
(@entry, @id := @id+ 1, 461.1927, 3755.536, 82.85698, NULL),
--
(@entry, @id := @id+ 1, 461.1927, 3755.536, 82.85698, NULL);

-- ----------------------------------------
-- Q: 30589 Wrecking the Wreck
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'npc_ji_yuan' WHERE `entry` = 60900;
DELETE FROM `creature_text` WHERE entry =60900;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60900, 0, 0, 'Давай-ка разыщем этого инженера. Может быть, убрать занозу будет не так уж и сложно.', 12, 0, 100, 396, 0, 27335, 'Цзи Огненная Лапа');

-- ----------------------------------------
-- Q: 29794 None Left Behind
-- ----------------------------------------
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_injured_sailor_rescue_controller' WHERE `entry` = 56476;
UPDATE `creature_template` SET `npcflag` = '16777216', `AIName` = '', `ScriptName` = 'npc_hurted_soldier' WHERE `entry` = 55999;
DELETE FROM smart_scripts WHERE entryorguid = 55999;

-- 
DELETE FROM `creature_text` WHERE entry =56236;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56236, 0, 0, 'Мне удалось выжить только благодаря тебе... Я этого не забуду.', 12, 0, 100, 18, 0, 0, 'Раненый матрос'),
(56236, 0, 1, 'Смерть была совсем близко! Спасибо, $gнезнакомец:незнакомка;.', 12, 0, 100, 18, 0, 0, 'Раненый матрос'),
(56236, 0, 2, 'Спасибо за своевременное освобождение, |3-6($c).', 12, 0, 100, 2, 0, 0, 'Раненый матрос');

UPDATE `creature_template` SET `VehicleId` = '1785' WHERE `entry` = 56236;

DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = '-105520';
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('-105520', '56236', '0', '1', 'q29794', '8', '30000');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 55999;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55999, 105520, 3, 0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 105520;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)
VALUES (18, 55999, 105520, 9, 0, 29794, 0, 0, 'Required quest active for spellclick');

-- ----------------------------------------
-- Q: 29798 An Ancient Evil
-- ----------------------------------------
UPDATE `creature_template` SET `RegenHealth` = '1', `ScriptName` = 'boss_vordraka' WHERE `entry` = 56009;

UPDATE `creature_template` SET `npcflag` =2, `mindmg` = '20', `maxdmg` = '30', `attackpower` = '15',`AIName` = '', `ScriptName` = 'npc_aysa_cloudsinger' WHERE `entry` = 56416;
DELETE FROM smart_scripts WHERE entryorguid = 56416;
DELETE FROM `creature_text` WHERE entry =56416;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56416, 0, 0, 'Хвала Шэнь-Цзынь Су, что ты здесь. Твоя помощь мне очень пригодится.', 12, 0, 100, 0, 0, 27384, 'Аиса Воспевающая Облака'),
(56416, 1, 0, 'Отходи в сторону, когда он поднимет оружие. Он еще опаснее, чем кажется.', 12, 0, 100, 0, 0, 27385, 'Аиса Воспевающая Облака'),
(56416, 2, 0, 'Он призывает помощников! Я отвлеку его, пока ты расправляешься с ними.', 12, 0, 100, 0, 0, 27386, 'Аиса Воспевающая Облака'),
(56416, 3, 0, 'Мы изматываем его. Еще немного!', 12, 0, 100, 0, 0, 27387, 'Аиса Воспевающая Облака'),
(56416, 4, 0, 'Не знаю, что бы я делала без тебя. Твоя помощь очень кстати.', 12, 0, 100, 0, 0, 0, 'Аиса Воспевающая Облака');

-- 56416 in the ship near boss
UPDATE `creature_addon` SET `auras` = '117326 83305' WHERE `guid` = 803083+6231;
UPDATE `creature_addon` SET `auras` = '83305' WHERE `guid` = 803073+6231;
DELETE FROM `creature` WHERE `guid` = 809316 AND id = 56416;

-- ----------------------------------------
-- Q: 30767 Risking It All
-- ----------------------------------------
UPDATE `creature_template` SET `ScriptName` = 'mob_aysa_gunship_crash_escort' WHERE `entry` = 60729;

DELETE FROM `creature_text` WHERE entry =60729;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60729, 0, 0, 'Если мы позволим Цзи сделать это, Шэнь-Цзынь Су может погибнуть! За мной, $p! Быстрее!', 12, 0, 100, 5, 0, 27412, 'Аиса Воспевающая Облака'),
(60729, 1, 0, 'Остановись, Цзи! Это глупо и безрассудно!', 12, 0, 100, 5, 0, 27413, 'Аиса Воспевающая Облака'),
(60729, 2, 0, 'Если ты дашь нам время, мы его найдем.', 12, 0, 100, 274, 0, 27414, 'Аиса Воспевающая Облака'),
(60729, 3, 0, 'Поступая так, мы рискуем всем!', 12, 0, 100, 5, 0, 27415, 'Аиса Воспевающая Облака'),
(60729, 4, 0, 'Цзи... если ты считаешь, что другого выхода нет, я не буду тебе мешать. Но ты ставишь на карту все. Надеюсь, ты окажешься прав.', 12, 0, 100, 1, 0, 27416, 'Аиса Воспевающая Облака'),
(60729, 5, 0, 'Аиса вздыхает.', 16, 0, 100, 274, 0, 0, 'Аиса Воспевающая Облака');

-- 117597
DELETE FROM `creature_text` WHERE entry =60741;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60741, 0, 0, 'Аиса, это наш единственный шанс. Мы взорвем корабль и залечим рану. У нас нет другого выхода.', 12, 0, 100, 1, 0, 27329, 'Цзи Огненная Лапа'),
(60741, 1, 0, 'Ты предлагаешь просто сидеть и ждать, пока нас осенит? Шэнь-Цзынь Су может погибнуть, если мы не взорвем корабль!', 12, 0, 100, 6, 0, 27330, 'Цзи Огненная Лапа'),
(60741, 2, 0, 'Лучше рискнуть всем, пытаясь спасти его, чем бездействовать.', 12, 0, 100, 1, 0, 27331, 'Цзи Огненная Лапа');

DELETE FROM `spell_target_position` WHERE id in (117497, 117597);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('117497', '860', '286.9531', '4004.331', '74.77346', '5.064899'),
('117597', '860', '230.314', '4006.68', '87.2803', '3.385939');

SET @id = 0;
SET @entry = 60729;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 291.7361, 4001.672, 75.32141, NULL),
(@entry, @id := @id+ 1, 270.146, 4005.15, 67.9128, NULL),
(@entry, @id := @id+ 1, 252.668, 4007.32, 78.1784, NULL),
(@entry, @id := @id+ 1, 238.963, 4009.03, 77.0572, NULL),
(@entry, @id := @id+ 1, 237.239, 3998.46, 76.2702, NULL),
(@entry, @id := @id+ 1, 259.427, 3993.69, 89.0894, NULL),
(@entry, @id := @id+ 1, 263.162, 3997.81, 89.3715, NULL),
-- cast 117600
(@entry, @id := @id+ 1, 235.0417, 4007.537, 87.66889, NULL),
(@entry, @id := @id+ 1, 236.8106, 4007.705, 87.85663, NULL),
(@entry, @id := @id+ 1, 239.453, 3942.2, 62.5987, NULL);

-- ----------------------------------------
-- Q: 29799 The Healing of Shen-zin Su
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredIdCount1` = '1' WHERE `quest_template`.`Id` = 29799;

DELETE FROM `creature` WHERE `id` in (60780, 60858, 60878, 60896 ); 
UPDATE `creature` SET phaseMask = 0x32 WHERE id = 60834;

DELETE FROM `creature_text` WHERE entry =56418;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56418, 0, 0, 'Оставайся поблизости и защищай лекарей! От этого зависят наши жизни!', 14, 0, 100, 0, 0, 27287, 'Цзи Огненная Лапа'),
(56418, 0, 1, 'Если лекари погибнут, Шэнь-Цзынь Су умрет, и все мы вместе с ним. Защищай их!', 14, 0, 100, 0, 0, 27288, 'Цзи Огненная Лапа'),
(56418, 0, 2, 'Найди лекарей и помоги им в бою. Они должны заниматься раной.', 14, 0, 100, 0, 0, 27285, 'Цзи Огненная Лапа');

UPDATE `creature_template` SET `ScriptName` = 'npc_ji_end_event' WHERE `entry` = 56418;
UPDATE `creature_template` SET `ScriptName` = 'npc_shen_healer' WHERE `entry` in (60878, 60896);
UPDATE `creature_template` SET  `mindmg` = '20', `maxdmg` = '26', `attackpower` = '13' WHERE `entry` in (60858, 60780);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=60858;
DELETE FROM smart_scripts WHERE entryorguid = 60858;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(60858, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 10000, 10000, 11, 128533, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cast Spell 128533');

-- ----------------------------------------
-- Q: 29800 New Allies
-- ----------------------------------------
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_panda_announcer' WHERE `entry` in (60888, 60889);
DELETE FROM `creature_text` WHERE entry =60888;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60888, 0, 0, 'Я терплю твое присутствие только из уважения к нашим новым союзникам. Не испытывай мое терпение.', 12, 0, 100, 0, 0, 28117, 'Корга Крепкая Грива');
DELETE FROM `creature_text` WHERE entry =60889;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(60889, 0, 0, 'Отойди, таурен, или снова окажешься в цепях.', 12, 0, 100, 15, 0, 27522, 'Делора Львиное Сердце');

-- ----------------------------------------
-- Q: 31450 A New Fate
-- ----------------------------------------
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_shang_xi_choose_faction' WHERE `entry` = 56013;
DELETE FROM `gossip_menu_option` WHERE `menu_id` = 13726;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(13726, 0, 0, 'I''m ready to decide.', 1, 3, 0, 0, 0, 0, ''),
(13726, 1, 0, 'I would like to go to Stormwind', 1, 3, 0, 0, 0, 0, ''),
(13726, 2, 0, 'I would like to go to Orgrimmar', 1, 3, 0, 0, 0, 0, '');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 15 AND SourceGroup = 13726;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('15', '13726', '0', '0', '0', '16', '0', '8388616', '0', '0', '0', '0', '', 'RACE_PANDAREN_NEUTRAL'),
('15', '13726', '1', '0', '0', '16', '0', '16777224', '0', '0', '0', '0', '', 'Req. RACE_PANDAREN_ALLI'),
('15', '13726', '2', '0', '0', '16', '0', '33554440', '0', '0', '0', '0', '', 'Req. RACE_PANDAREN_HORDE');

DELETE FROM `creature_text` WHERE entry =56013;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(56013, 0, 0, 'Вместе вы сделали большое дело – спасли Шэнь-Цзынь Су. Мы гордимся вами.', 12, 0, 100, 1, 0, 27784, 'Дух мастера Шан Си'),
(56013, 1, 0, 'Но ваши приключения только начинаются. Эти новые союзники пришли из мира, которому требуется наша помощь.', 12, 0, 100, 1, 0, 27785, 'Дух мастера Шан Си'),
(56013, 2, 0, 'А ты, Цзи? Ты присоединишься к Орде, когда они отправятся домой?', 12, 0, 100, 6, 0, 27786, 'Дух мастера Шан Си'),
(56013, 3, 0, 'А ты? Каков твой выбор?', 12, 0, 100, 6, 0, 27787, 'Дух мастера Шан Си');

DELETE FROM `creature_text` WHERE entry =57721;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(57721, 0, 0, 'Я бы хотела сопроводить этих воинов Альянса домой.', 12, 0, 100, 1, 0, 27405, 'Аиса Воспевающая Облака');

DELETE FROM `creature_text` WHERE entry =57720;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(57720, 0, 0, 'Да... Наверное, это и к лучшему. Они понравились мне. И, похоже, я тоже могу оказаться им полезен.', 12, 0, 100, 273, 0, 27305, 'Цзи Огненная Лапа');

-- ----------------------------------------
-- Q: 31013 The Horde Way
-- ----------------------------------------
UPDATE `quest_template` SET `StartScript` = '31013' WHERE `Id` = 31013;
DELETE FROM `quest_start_scripts` WHERE id = 31013;
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
 ('31013', '0', '15', '120753', '2', '0', '0', '0', '0', '0');

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'mob_garosh_hord_way' WHERE `entry` = 62087;

-- 0xF130F287002E50A8
DELETE FROM `creature_text` WHERE entry =62087;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(62087, 0, 0, 'Присоединиться к Орде – это правильное решение.', 12, 0, 100, 273, 0, 30746, 'Гаррош Адский Крик'),
(62087, 1, 0, 'Некоторые зовут нас варварами... \"дикими расами\" Азерота.', 12, 0, 100, 396, 0, 30747, 'Гаррош Адский Крик'),
(62087, 2, 0, 'Но они просто глупы и слепы. Посмотрите вокруг, пандарены!', 12, 0, 100, 274, 0, 30748, 'Гаррош Адский Крик'),
(62087, 3, 0, 'Орки – самые лучшие воины в мире.', 12, 0, 100, 397, 0, 30749, 'Гаррош Адский Крик'),
(62087, 4, 0, 'Таурены тоже доказали свою полезность. Посмотрите на этого шамана.', 12, 0, 100, 6, 0, 30750, 'Гаррош Адский Крик'),
(62087, 5, 0, 'Даже эльфы крови могут держать в руках меч.', 12, 0, 100, 396, 0, 30751, 'Гаррош Адский Крик'),
(62087, 6, 0, 'Каждый в моей Орде вносит вклад в общее дело, и вы не станете исключением.', 12, 0, 100, 396, 0, 30752, 'Гаррош Адский Крик'),
(62087, 7, 0, 'Вы понимаете это, пандарены?', 12, 0, 100, 6, 0, 30753, 'Гаррош Адский Крик'),
(62087, 8, 0, 'Хм. Хорошо.', 12, 0, 100, 0, 0, 30754, 'Гаррош Адский Крик'),
(62087, 9, 0, 'Идем дальше. Я знаю, что кроме вас остров покинули и другие пандарены.', 12, 0, 100, 396, 0, 30755, 'Гаррош Адский Крик'),
(62087, 10, 0, 'Некоторые из них решили присоединиться к Альянсу.', 12, 0, 100, 14, 0, 30756, 'Гаррош Адский Крик'),
(62087, 11, 0, 'Теперь они ваши враги.', 12, 0, 100, 397, 0, 30757, 'Гаррош Адский Крик'),
(62087, 12, 0, 'Среди них могут быть ваши друзья и родные, решившие противостоять Орде. Значит, больше они не друзья вам... и не члены вашей семьи.', 12, 0, 100, 396, 0, 30758, 'Гаррош Адский Крик'),
(62087, 13, 0, 'В тот момент, когда они напялили на себя накидку Альянса, они умерли для вас. Я не потерплю никаких связей с противниками. Тех, кто предаст Орду, ждет смерть!', 12, 0, 100, 274, 0, 30759, 'Гаррош Адский Крик'),
(62087, 14, 0, 'Я понятно выразился?', 12, 0, 100, 5, 0, 30760, 'Гаррош Адский Крик'),
(62087, 15, 0, 'Хорошо.', 12, 0, 100, 0, 0, 30761, 'Гаррош Адский Крик'),
(62087, 16, 0, 'Встретимся на Аллее Чести. У меня есть подарок для вас.', 12, 0, 100, 396, 0, 30762, 'Гаррош Адский Крик');

SET @id = 0;
SET @entry = 62087;
DELETE FROM `script_waypoint` WHERE `entry` = @entry;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES 
(@entry, @id := @id+ 1, 1665.713, -4344.802, 26.26202, NULL),
(@entry, @id := @id+ 1, 1661.795, -4346.851, 26.33014, NULL),   -- 18:12:25.000
(@entry, @id := @id+ 1, 1658.884, -4348.58, 26.36691, NULL),
(@entry, @id := @id+ 1, 1661.288, -4343.878, 26.33483, NULL),
(@entry, @id := @id+ 1, 1662.198, -4341.984, 26.33634, NULL),
(@entry, @id := @id+ 1, 1659.948, -4338.556, 26.34779, NULL),
(@entry, @id := @id+ 1, 1659.629, -4345.505, 26.36073, NULL),
(@entry, @id := @id+ 1, 1658.51, -4354.894, 26.37214, NULL),
(@entry, @id := @id+ 1, 1656.589, -4357.963, 26.35595, NULL),
(@entry, @id := @id+ 1, 1654.036, -4359.858, 26.33619, NULL),
(@entry, @id := @id+ 1, 1650.467, -4360.143, 26.33435, NULL),
(@entry, @id := @id+ 1, 1647.595, -4358.606, 26.36272, NULL),
--
(@entry, @id := @id+ 1, 1650.32, -4357.35, 26.33648, NULL),
--
(@entry, @id := @id+ 1, 1639.502, -4358.743, 26.75204, NULL),
(@entry, @id := @id+ 1, 1637.854, -4359.377, 26.75178, NULL),
--
(@entry, @id := @id+ 1, 1637.854, -4359.377, 26.75178, NULL),
--
(@entry, @id := @id+ 1, 1627.727, -4365.224, 24.57568, NULL),
(@entry, @id := @id+ 1, 1626.149, -4368.028, 24.59827, NULL),
(@entry, @id := @id+ 1, 1624.148, -4373.868, 24.61423, NULL),
(@entry, @id := @id+ 1, 1621.009, -4375.174, 24.6211, NULL),
(@entry, @id := @id+ 1, 1617.45, -4374.219, 24.62789, NULL),
(@entry, @id := @id+ 1, 1613.497, -4373.184, 24.62625, NULL),
(@entry, @id := @id+ 1, 1610.83, -4373.624, 24.61312, NULL),
(@entry, @id := @id+ 1, 1607.936, -4375.203, 23.12599, NULL),
(@entry, @id := @id+ 1, 1604.688, -4377.604, 21.028, NULL),
(@entry, @id := @id+ 1, 1600, -4379.834, 20.59395, NULL),
(@entry, @id := @id+ 1, 1600, -4379.834, 20.59395, NULL);


DELETE FROM `creature_text` WHERE entry =62081;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(62081, 0, 0, 'Смотри!', 12, 0, 100, 5, 0, 0, 'Цзи Огненная Лапа'),
(62081, 1, 0, 'Ну, это хорошая новость. Как только присоединимся к Орде, у нас всегда будет полно интересных дел.', 12, 0, 100, 1, 0, 0, 'Цзи Огненная Лапа'),
(62081, 2, 0, 'Император Адский Крик, я Цзи...', 12, 0, 100, 1, 0, 27289, 'Цзи Огненная Лапа'),
(62081, 3, 0, 'Да, вождь.', 12, 0, 100, 2, 0, 27290, 'Цзи Огненная Лапа'),
(62081, 4, 0, 'Да... Да, конечно...', 12, 0, 100, 273, 0, 27291, 'Цзи Огненная Лапа'),
(62081, 5, 0, 'Он... Он разделил город?', 12, 0, 100, 1, 0, 0, 'Цзи Огненная Лапа');

-- Pandashan
DELETE FROM `areatrigger_scripts`  WHERE `ScriptName` LIKE 'AreaTrigger_at_bassin_curse';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6986, 'AreaTrigger_at_bassin_curse'),
(6987, 'AreaTrigger_at_bassin_curse'),
(6988, 'AreaTrigger_at_bassin_curse'),
(6989, 'AreaTrigger_at_bassin_curse'),
(6990, 'AreaTrigger_at_bassin_curse'),
(6991, 'AreaTrigger_at_bassin_curse'),
(6992, 'AreaTrigger_at_bassin_curse'),
(7011, 'AreaTrigger_at_bassin_curse'),
(7012, 'AreaTrigger_at_bassin_curse');

DELETE FROM `areatrigger_scripts`  WHERE `ScriptName` LIKE 'AreaTrigger_at_temple_entrance';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7835, 'AreaTrigger_at_temple_entrance');

DELETE FROM `areatrigger_scripts`  WHERE `ScriptName` LIKE 'AreaTrigger_at_rescue_soldiers';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7087, 'AreaTrigger_at_rescue_soldiers');

DELETE FROM `areatrigger_scripts`  WHERE `ScriptName` LIKE 'AreaTrigger_at_wind_temple_entrance';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7041, 'AreaTrigger_at_wind_temple_entrance');