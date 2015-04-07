DROP TABLE IF EXISTS `creature_questitem`;
CREATE TABLE `creature_questitem` (
  `CreatureEntry` int(10) unsigned NOT NULL DEFAULT '0',
  `Idx` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`CreatureEntry`,`Idx`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `gameobject_questitem`;
CREATE TABLE `gameobject_questitem` (
  `GameObjectEntry` int(10) unsigned NOT NULL DEFAULT '0',
  `Idx` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`GameObjectEntry`,`Idx`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
