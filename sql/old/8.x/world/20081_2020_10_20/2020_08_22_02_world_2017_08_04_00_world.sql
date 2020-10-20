--
DROP TABLE IF EXISTS `instance_spawn_groups`;
CREATE TABLE `instance_spawn_groups` (
  `instanceMapId` smallint(5) unsigned not null,
  `bossStateId` tinyint(3) unsigned not null,
  `bossStates` tinyint(3) unsigned not null,
  `spawnGroupId` int(10) unsigned not null,
  `flags` tinyint(3) unsigned not null,
  PRIMARY KEY (`instanceMapId`,`bossStateId`,`spawnGroupId`,`bossStates`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
