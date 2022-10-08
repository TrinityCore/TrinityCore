/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- The Great Bank Heist q14122
DELETE FROM `spell_script_names` WHERE `spell_id` = 67555;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('67555', 'spell_great_bank_heist');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('35486', '67476', '1', '0');
UPDATE `creature_template` SET `npcflag` = '16777216', `ScriptName` = 'npc_hack_bank_controller' WHERE `entry` = 35486;
DELETE FROM `creature` WHERE `id` = 35486;
DELETE FROM `creature_text` WHERE `entry` = 35486;
INSERT INTO `creature_text` (`entry`,`id` , `groupid`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
('35486', '0', '0', 'Вы собираетесь вломиться в хранилище и забрать свои личные сбережения!', '42', '0', '100', '0', '0', '0', ''), 
('35486', '0', '1', 'Хранилище будет взломано, когда |cFFFF2222полоска индикатора взлома достигнет 100 процентов!|r$B|TInterface\\Icons\\INV_Misc_coin_02.blp:64|t $BЕсли вы будете делать что-то не то или в неподходящий момент, это уменьшит процент взлома.', '42', '0', '100', '0', '0', '0', ''), 
('35486', '0', '2', 'Удачи!', '42', '0', '0', '0', '0', '0', ''),
('35486', '0', '3', 'Используйте |cFFFF2222невероятное гамма-излучение!|r$B|TInterface\\Icons\\INV_Misc_EngGizmos_20.blp:64|t', '42', '0', '100', '0', '0', '0', ''),
('35486', '0', '4', 'Время истекло!', '42', '0', '100', '0', '0', '0', ''),
('35486', '0', '5', 'Используйте |cFFFF2222взрывхлопушки!|r$B|TInterface\\Icons\\INV_Misc_Bomb_07.blp:64|t', '42', '0', '100', '0', '0', '0', ''), 
('35486', '0', '6', 'Используйте |cFFFF2222ухоскоп!|r$B|TInterface\\Icons\\INV_Misc_Ear_NightElf_02.blp:64|t', '42', '0', '100', '0', '0', '0', ''), 
('35486', '0', '7', 'Верно!', '42', '0', '100', '0', '0', '0', ''), 
('35486', '0', '8', 'Используйте |cFFFF2222дрель для каджа''мита!|r$B|TInterface\\Icons\\INV_Weapon_ShortBlade_21.blp:64|t', '42', '0', '100', '0', '0', '0', ''), 
('35486', '0', '9', 'Используйте |cFFFF2222универсальный набор отмычек|r!$B|TInterface\\Icons\\INV_Misc_EngGizmos_swissArmy.blp:64|t', '42', '0', '100', '0', '0', '0', ''),
('35486', '0', '10', 'Ошибка!', '42', '0', '100', '0', '0', '0', ''),
('35486', '0', '11', 'Победа! Вы получили свои личные сбережения!$B$B|TInterface\\Icons\\INV_Misc_coin_02.blp:64|t', '42', '0', '100', '0', '0', '0', ''),
('35486', '0', '12', '', '42', '0', '100', '0', '0', '0', ''); -- cleaner

DELETE FROM `spell_script_names` WHERE `spell_id` in (67526, 67508, 67524, 67525, 67522);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('67526', 'spell_bank_hacking_spells'), 
('67508', 'spell_bank_hacking_spells'), 
('67524', 'spell_bank_hacking_spells'), 
('67525', 'spell_bank_hacking_spells'), 
('67522', 'spell_bank_hacking_spells');

-- clean old hacks
UPDATE `gameobject_template` SET `type` = '5', `data1` = '0', `data2` = '0', `AIName` = '' WHERE `entry` = 195525;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 195525;
UPDATE `gameobject` SET id = 195449, phaseMask = 15  WHERE `id` = 195525 AND phaseMask = 8;