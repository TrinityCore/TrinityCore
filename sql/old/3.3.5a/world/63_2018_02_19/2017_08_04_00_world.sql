--
DROP TABLE IF EXISTS `instance_spawn_groups`;
CREATE TABLE `instance_spawn_groups` (
  `instanceMapId` smallint(5) unsigned not null,
  `bossStateId` tinyint unsigned not null,
  `bossStates` tinyint unsigned not null,
  `spawnGroupId` int unsigned not null,
  `flags` tinyint unsigned not null,
  PRIMARY KEY (`instanceMapId`,`bossStateId`,`spawnGroupId`,`bossStates`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
