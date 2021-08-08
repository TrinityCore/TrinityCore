alter table `instance_encounters` 
   change `lastEncounterDungeon` `lastEncounterDungeon` smallint(5) UNSIGNED default '0' NOT NULL comment 'If not 0, LfgDungeon.dbc entry for the instance it is last encounter in',
   drop primary key, 
   add primary key(`entry`, `lastEncounterDungeon`);
   
DELETE FROM `instance_encounters` WHERE `instance_encounters`.`entry` IN (
 1412, 1413, 1414,
 1439, 1416, 1417, 1418,
 1419, 1397, 1405, 1406,
 1304, 1303, 1305, 1306,
 1502,
 1522,
 1530
 );
 
INSERT INTO `instance_encounters` VALUES
-- Хмелеварня буйных портеров
(1412, 0, 56637, 0, ''),
(1413, 0, 56717, 0, ''),
(1414, 0, 59479, 465, 'last boss reward - normal'),
(1414, 0, 59479, 469, 'last boss reward - heroic'),
-- Храм нефритовой змеи
(1439, 0, 56439, 0, ''),
(1416, 0, 56732, 0, ''),
(1417, 0, 56843, 0, ''),
(1418, 0, 56448, 464, 'last boss reward - normal'),
(1418, 0, 56448, 468, 'last boss reward - heroic'),
-- Врата Заходящего Солнца
(1397, 0, 56906, 0, ''),
(1405, 0, 56589, 0, ''),
(1406, 0, 56636, 0, ''),
(1419, 0, 56877, 631, 'last boss reward - normal'),
(1419, 0, 56877, 471, 'last boss reward - heroic'),
-- Монастырь ШадоПан
(1304, 0, 56541, 0, ''),
(1303, 0, 56747, 0, ''),
(1305, 0, 56719, 0, ''),
(1306, 0, 56884, 466, 'last boss reward - normal'),
(1306, 0, 56884, 470, 'last boss reward - heroic'),
-- Осада храма Нюцзао
(1502, 0, 61634, 554, 'last boss reward - heroic'),
-- Залы Алого ордена
(1522, 0, 59303, 473, 'last boss reward - heroic'),
-- Некроситет
(1530, 0, 59080, 2  , 'last boss reward - normal');

-- Дворец МогуШан
UPDATE `instance_encounters` SET `lastEncounterDungeon` = 0 WHERE `entry` = 1441;
UPDATE `instance_encounters` SET `lastEncounterDungeon` = 467 WHERE `entry` = 1509; -- normal
UPDATE `instance_encounters` SET `lastEncounterDungeon` = 519 WHERE `entry` = 1510; -- heroic

-- Осада храма Нюцзао
UPDATE `instance_encounters` SET `lastEncounterDungeon` = 630 WHERE `entry` = 1502; -- normal

-- Залы Алого ордена
UPDATE `instance_encounters` SET `lastEncounterDungeon` = 0 WHERE `entry` = 1420;
UPDATE `instance_encounters` SET `lastEncounterDungeon` = 163 WHERE `entry` = 1422; -- normal