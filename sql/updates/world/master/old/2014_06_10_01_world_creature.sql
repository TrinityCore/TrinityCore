/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

DROP TABLE IF EXISTS `creature_copy`;
CREATE TABLE `creature_copy` (
  `guid` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Global Unique Identifier',
  `id` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Creature Identifier',
  `map` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
  `zoneId` int(11) NOT NULL DEFAULT '0',
  `areaId` int(11) NOT NULL DEFAULT '0',
  `spawnMask` int(11) unsigned NOT NULL DEFAULT '1',
  `phaseMask` int(11) unsigned NOT NULL DEFAULT '1',
  `modelid` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `equipment_id` mediumint(8) NOT NULL DEFAULT '0',
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  `orientation` float NOT NULL DEFAULT '0',
  `spawntimesecs` int(10) unsigned NOT NULL DEFAULT '120',
  `spawndist` float NOT NULL DEFAULT '0',
  `currentwaypoint` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `curhealth` int(10) unsigned NOT NULL DEFAULT '1',
  `curmana` int(10) unsigned NOT NULL DEFAULT '0',
  `MovementType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `npcflag` int(10) unsigned NOT NULL DEFAULT '0',
  `unit_flags` int(10) unsigned NOT NULL DEFAULT '0',
  `dynamicflags` int(10) unsigned NOT NULL DEFAULT '0',
  `isActive` tinyint(1) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`),
  KEY `idx_map` (`map`),
  KEY `idx_id` (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature System' AUTO_INCREMENT=0 ;
INSERT INTO creature_copy select * FROM creature;

-- Добавляем индексы для быстрой работы обработчика
ALTER TABLE `creature` ADD INDEX(`phaseMask`),
ADD INDEX(`spawnMask`),
ADD INDEX(`position_x`),
ADD INDEX(`position_y`),
ADD INDEX(`position_z`);

ALTER TABLE `creature_copy` ADD INDEX(`phaseMask`),
ADD INDEX(`spawnMask`),
ADD INDEX(`position_x`),
ADD INDEX(`position_y`),
ADD INDEX(`position_z`);

-- Удаление дубликатов
DELETE FROM creature WHERE guid in(SELECT creature.guid FROM `creature_copy` WHERE creature.id = creature_copy.id AND creature_copy.map = creature.map AND creature.guid != creature_copy.guid AND creature.position_x = creature_copy.position_x AND creature.position_y = creature_copy.position_y AND creature.position_z = creature_copy.position_z AND creature.spawnMask = creature_copy.spawnMask AND creature.phaseMask = creature_copy.phaseMask);

-- Чистка Фаз от дублей.
DELETE FROM creature WHERE guid in(SELECT creature.guid FROM `creature_copy` WHERE creature.id = creature_copy.id AND creature_copy.map = creature.map AND creature.guid != creature_copy.guid AND creature.position_x = creature_copy.position_x AND creature.position_y = creature_copy.position_y AND creature.position_z = creature_copy.position_z AND creature.spawnMask = creature_copy.spawnMask AND creature.phaseMask < creature_copy.phaseMask AND (creature_copy.phaseMask & creature.phaseMask) = creature.phaseMask);

-- Очистка аддонов и линков на гуид
ALTER TABLE `creature_addon` ADD INDEX(`path_id`);
DELETE FROM `creature_addon` WHERE guid not in (select guid from creature);
-- DELETE FROM waypoint_data WHERE id not in (SELECT path_id FROM creature_addon);
ALTER TABLE creature_addon DROP INDEX path_id;

-- Удаление временной таблицы
DROP TABLE creature_copy;

-- Удаление индексов
ALTER TABLE creature DROP INDEX position_x;
ALTER TABLE creature DROP INDEX position_y;
ALTER TABLE creature DROP INDEX position_z;
ALTER TABLE creature DROP INDEX phaseMask;
ALTER TABLE creature DROP INDEX spawnMask;