CREATE TABLE IF NOT EXISTS `gameobject_overrides` (
  `spawnId` int(10) unsigned NOT NULL DEFAULT '0',
  `faction` smallint(5) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`spawnId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
