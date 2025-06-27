-- 
DROP TABLE IF EXISTS `pool_members`;
CREATE TABLE `pool_members` (
  `type` smallint(10) unsigned NOT NULL,
  `spawnId` int(10) unsigned NOT NULL,
  `poolSpawnId` int(10) unsigned NOT NULL,
  `chance` double unsigned NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`type`,`spawnId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`)
SELECT 0 as `type`, `guid` as `spawnId`, `pool_entry` as `poolSpawnId`, `chance`, `description` FROM `pool_creature`;

INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`)
SELECT 1 as `type`, `guid` as `spawnId`, `pool_entry` as `poolSpawnId`, `chance`, `description` FROM `pool_gameobject`;

INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`)
SELECT 2 as `type`, `pool_id` as `spawnId`, `mother_pool` as `poolSpawnId`, `chance`, `description` FROM `pool_pool`;

DROP TABLE IF EXISTS `pool_creature`;
DROP TABLE IF EXISTS `pool_gameobject`;
DROP TABLE IF EXISTS `pool_pool`;
