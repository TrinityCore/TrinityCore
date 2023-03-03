/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

--
DELETE FROM `spell_script_names` WHERE `spell_id` = 143842;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143842', 'spell_fallen_protectors_mark_of_anguish_transfer');

--
DELETE FROM `spell_scripts` WHERE id  = 144081;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('144081', '0', '0', '15', '144176', '0', '0', '0', '0', '0', '0');

--
DELETE FROM `creature_text` WHERE entry =71475;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(71475, 0, 0, 'Ты... Рук знает тебя...', 14, 0, 100, 396, 0, 38718, 0),
(71475, 1, 0, 'Рук... не знает... все... в тумане...', 14, 0, 100, 396, 0, 38720, 0),
(71475, 2, 0, 'Пожалуйста, помогите...', 14, 0, 100, 396, 0, 38722, 0),
(71475, 3, 0, 'Сунь... Хэ... Помогите.', 14, 0, 100, 0, 0, 38716, 'Рук Каменная Ступня'),
(71475, 4, 0, '|TInterface/\Icons/\spell_monk_ringofpeace:20|t%s призывает |cFFFF0000|Hspell:143955|h[страдание, печаль и уныние]|h|r!', 41, 0, 100, 0, 0, 38419, 0),
(71475, 5, 0, 'Руку нужна... помощь!', 14, 0, 100, 0, 0, 38419, 0),
(71475, 5, 1, 'Рук... в беде...', 14, 0, 100, 0, 0, 38728, 'Рук Каменная Ступня'),
(71475, 5, 2, 'Бейте... Рука!', 14, 0, 100, 0, 0, 38728, 'Рук Каменная Ступня'),
(71475, 6, 0, '|TInterface/\Icons/\ability_priest_pathofthedevout:20|t%s начинает произносить заклинание |cFFFF0000|Hspell:143497|h[Узы Золотого Лотоса]|h|r.', 41, 0, 100, 0, 0, 0, 0);


DELETE FROM `creature_text` WHERE entry =71480;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(71480, 0, 0, 'Наша судьба – безысходность. Это наше наказание.', 14, 0, 100, 396, 0, 38415, 0),
(71480, 1, 0, 'Получится ли у вас победить?', 14, 0, 100, 0, 0, 38413, 'Рук Каменная Ступня'),
(71480, 2, 0, '|TInterface/\Icons/\ability_priest_halo_shadow:20|t%s начинает произносить заклинание |cFFFF0000|Hspell:143491|h[Катастрофа]|h|r!', 41, 0, 100, 0, 0, 0, 0),
(71480, 3, 0, 'Ощутите боль нашей неудачи.', 14, 0, 100, 0, 0, 38727, 0),
(71480, 4, 0, 'Взываю к вам, защитники!', 14, 0, 100, 0, 0, 38420, 0),
(71480, 5, 0, '|TInterface/\Icons/\ability_priest_pathofthedevout:20|t%s начинает произносить заклинание |cFFFF0000|Hspell:143497|h[Узы Золотого Лотоса]|h|r.', 41, 0, 100, 0, 0, 0, 0),
(71480, 6, 0, 'Мы вернемся туда, где сбились с пути. Вы... очень добры.', 14, 0, 100, 0, 0, 38414, 'Сунь Доброе Сердце');

--
DELETE FROM `spell_scripts` WHERE id = 143958;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
('143958', '0', '0', '15', '144020', '0', '0', '0', '0', '0', '0');

--
DELETE FROM `spell_script_names` WHERE `spell_id` = 143962;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143962', 'spell_fallen_protectors_inferno_strike');