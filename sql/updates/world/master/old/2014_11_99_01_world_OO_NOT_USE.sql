/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

UPDATE `creature_template` SET unit_flags = unit_flags | 0x2 | 0x100 | 0x200 WHERE entry in (71685, 71683, 71695, 71711, 71684, 71686);
DELETE FROM `pet_stats` WHERE entry in (71996, 72000, 71995);
UPDATE `areatrigger_data` SET `activationDelay` = '500' WHERE `areatrigger_data`.`entry` = 1080;

--
REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES ('9267', 'at_siege_of_orgrimmar_portal_to_orgrimmar');

-- teleport from org.
REPLACE INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('149407', '1136', '748', '1113', '357', '0'),
('148034', '1136', '1322.31', '-5285.94', '9', '0'), -- alliance 
('148032', '1136', '1638.63', '-5261.68', '9', '0');

DELETE FROM creature where id in (73598, 73605);

-- teleport entry 73536
UPDATE `creature_template` SET `minlevel` = '90', `maxlevel` = '90', `npcflag` = '16777216', `unit_flags` = '512', `unit_flags2` = '34816' WHERE `creature_template`.`entry` = 73536;
REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
('73536', '148034', '3', '0'),  -- aliance
('73536', '148032', '3', '0');

DELETE FROM `conditions` WHERE SourceGroup = 73536;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('18', '73536', '148034', '0', '0', '6', '0', '469 ', '0', '0', '0', '0', '', 'Aliance'), 
('18', '73536', '148032', '0', '0', '6', '0', '67', '0', '0', '0', '0', '', 'Horde');

-- ServerToClient: SMSG_UPDATE_OBJECT (0x1792) Length: 55681 ConnectionIndex: 0 Time: 10/08/2014 19:36:05.000 Type: Unknown Opcode Type Number: 952691

-- alliance 223459

DELETE FROM `creature_text` WHERE entry in (73598, 73605);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(73598, 0, 0, 'Гордыня Гарроша выпустила последнего ша. Я не удивлена.', 12, 0, 100, 1, 0, 38090, 0),
(73598, 1, 0, 'Кровавый Вой.', 12, 0, 100, 5, 0, 28232, 'Лор''темар Терон'),
(73598, 2, 0, 'Это уже не новость, лорд. Пока мы с вами беседуем, флот короля Ринна уже подходит к Оргриммару.', 12, 0, 100, 5, 0, 38092, 'Лор''темар Терон'),
(73598, 3, 0, 'Предупреждаю, Лор''темар. Альянс осаждает город, мы уничтожим Адского Крика. Вам и вашим людям лучше не стоять у нас на пути.', 12, 0, 100, 25, 0, 38093, 'Лор''темар Терон'),
(73598, 4, 0, 'Вперед, герои! В портал! Осада Оргриммара началась!', 12, 0, 100, 1, 0, 38094, 'Леди Джайна Праудмур'),
--
(73605, 0, 0, 'Смотрите! Он оставил оружие!', 14, 0, 100, 25, 0, 38158, 0),
(73605, 1, 0, 'Гаррош совсем обезумел.', 12, 0, 100, 6, 0, 38159, 'Леди Джайна Праудмур'),
(73605, 2, 0, 'Как и наш. Мы с Сильваной направили корабли для поддержки восстания Вол''джина.', 12, 0, 100, 5, 0, 38160, 'Леди Джайна Праудмур'),
(73605, 3, 0, 'Всегда рад встрече с вами, леди Праудмур.', 12, 0, 100, 1, 0, 38161, 'Леди Джайна Праудмур');

209081