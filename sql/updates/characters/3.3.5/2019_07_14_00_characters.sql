-- 
DROP TABLE IF EXISTS `respawn`;
CREATE TABLE `respawn` (
  `type` smallint(10) unsigned NOT NULL,
  `spawnId` int(10) unsigned NOT NULL,
  `respawnTime` bigint(20) unsigned NOT NULL,
  `mapId` smallint(10) unsigned NOT NULL,
  `instanceId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`type`,`spawnId`,`instanceId`),
  KEY `idx_instance` (`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Stored respawn times';

INSERT INTO `respawn` (`type`,`spawnId`,`respawnTime`,`mapId`,`instanceId`)
SELECT 0 as `type`,`guid`,`respawnTime`,`mapId`,`instanceId` FROM `creature_respawn`;

INSERT INTO `respawn` (`type`,`spawnId`,`respawnTime`,`mapId`,`instanceId`)
SELECT 1 as `type`,`guid`,`respawnTime`,`mapId`,`instanceId` FROM `gameobject_respawn`;

DROP TABLE `creature_respawn`;
DROP TABLE `gameobject_respawn`;
