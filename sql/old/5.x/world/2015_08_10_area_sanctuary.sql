DROP TABLE IF EXISTS `area_sanctuary`;
CREATE TABLE `area_sanctuary` (
  `areaId` int(11) unsigned NOT NULL DEFAULT '0',
  `areaName` longtext CHARACTER SET utf8,
  PRIMARY KEY (`areaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;