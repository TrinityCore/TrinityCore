CREATE TABLE `scenario_poi` (
  `criteriaTreeId` int(10) unsigned NOT NULL DEFAULT '0',
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `mapid` int(10) unsigned NOT NULL DEFAULT '0',
  `WorldMapAreaId` int(10) unsigned NOT NULL DEFAULT '0',
  `unk12` int(10) unsigned NOT NULL DEFAULT '0',
  `unk16` int(10) unsigned NOT NULL DEFAULT '0',
  `unk20` int(10) unsigned NOT NULL DEFAULT '0',
  `unk24` int(10) unsigned NOT NULL DEFAULT '0',
  `unk28` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`criteriaTreeId`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `scenario_poi_points` (
  `criteriaTreeId` int(10) unsigned NOT NULL DEFAULT '0',
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `idx` int(10) unsigned NOT NULL DEFAULT '0',
  `x` int(11) NOT NULL DEFAULT '0',
  `y` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`criteriaTreeId`,`id`,`idx`),
  KEY `criteriaTreeId_id` (`criteriaTreeId`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;