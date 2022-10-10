/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

UPDATE `creature_template` SET `ScriptName` = 'vehicle_golden_lotus_conteiner' WHERE `entry` in (71711, 71684, 71686);

UPDATE `creature_template` SET `InhabitType` = '3' WHERE `entry` in (71478, 71482, 71474, 71477, 71476, 71481);

DELETE FROM `spell_script_names` WHERE `spell_id` = 143559;

UPDATE `creature_template` SET `ScriptName` = 'npc_measure_of_sun' WHERE `entry` in (71482, 71474);

--
UPDATE `creature_template` SET `flags_extra` = '128' WHERE `creature_template`.`entry` = 71685;

--
DELETE FROM `spell_script_names` WHERE `spell_id` = 143434;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143434', 'spell_fallen_protectors_shadow_word_bane');

-- Calamity
DELETE FROM `spell_script_names` WHERE `spell_id` = 143491;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143491', 'spell_fallen_protectors_calamity');

--
UPDATE `creature_template_addon` SET `auras` = '143708' WHERE `entry` in (71478, 71482, 71474, 71477, 71476, 71481);

--
UPDATE `creature_template` SET `ScriptName` = 'npc_measure_of_he' WHERE `entry` in (71478);

--
UPDATE `creature_template` SET `ScriptName` = 'npc_measure_of_rook' WHERE `entry` in (71476, 71477, 71481);

--
DELETE FROM `spell_script_names` WHERE `spell_id` = 143822;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143822', 'spell_fallen_protectors_mark_of_anguish_select_first_target');

--
DELETE FROM `spell_script_names` WHERE `spell_id` = 144079;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('144079', 'spell_fallen_protectors_shadow_weakness_prock');

--
DELETE FROM `spell_script_names` WHERE `spell_id` = 143840;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143840', 'spell_fallen_protectors_mark_of_anguish');


--
DELETE FROM `creature_text` WHERE entry =71479;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(71479, 0, 0, '|TInterface/\Icons/\ability_rogue_deadliness:20|t%s создает |cFFFF0000|Hspell:143840|h[Знак страданий]|h|r!', 41, 0, 100, 0, 0, 0, 0),
(71479, 1, 0, '%s подает сигнал о помощи.', 16, 0, 100, 0, 0, 0, 0),
(71479, 2, 0, '|TInterface/\Icons/\ability_priest_pathofthedevout:20|t%s начинает произносить заклинание |cFFFF0000|Hspell:143497|h[Узы Золотого Лотоса]|h|r.', 41, 0, 100, 0, 0, 0, 0),
(71479, 3, 0, '%s начинает медитировать, чтобы излечить свои раны.', 16, 0, 100, 0, 0, 0, 'Хэ Легкая Нога');
